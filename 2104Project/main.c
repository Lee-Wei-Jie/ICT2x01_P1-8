/******************************************************************************
 * MSP432 ICT2104 / ICT2x01 Project
 *
 *
 * ICT2104 Team 2-7
 * - Koh Jia Cheng (2000665)
 * - Lee Wei Jie (2000990)
 *
 *
 * PID implemented:
 * ********The wheels will be adjusted every second to ensure both wheels are of the same speed (baseline/target:the faster wheel)
 * State Machine:
 * ********Simple State Machine implemented to prevent PID from kicking in during a Turn.
 * Optimization applied:
 * ********3Mhz timer for all clock (Even for WiFi Modules, Libraries are edited accordingly. Baud rate for UART as well)
 *******************************************************************************/


//Consolidate Header declarations
#include "declarations.h"
#include "functions.h"
#include <ESP8266.h>
#include <UART_Driver.h>
#include <MSPIO.h>

//Consolidate external functions
extern int CalculateAverageNotches(int left, int right);
extern float CalculateDistanceTraveled(int totalnotches);
extern void Delay(uint32_t loops);
extern void CAR_InitializeLeftMotor(void);
extern void CAR_InitializeRightMotor(void);
extern void CAR_GeneratePWM(void);
extern void CAR_Stop(void);
extern void CAR_TurnRight(void);
extern void CAR_TurnLeft(void);
extern int PID_Controller(int leftnotch, int rightnotch);
extern void CAR_SetState(int state);

/***************************************CONFIGURATION FOR LEFT MOTOR THROUGH L398N MOTOR DRIVER BOARD******************FOR*TA0****************************/
Timer_A_PWMConfig pwmConfigLeft =
{
     TIMER_A_CLOCKSOURCE_SMCLK,                     //3Mhz
     TIMER_A_CLOCKSOURCE_DIVIDER_24,                //3Mhz / 24 = 125000hz
     10000,                                         //Timer Period
     TIMER_A_CAPTURECOMPARE_REGISTER_1,             //TA0.1
     TIMER_A_OUTPUTMODE_RESET_SET,                  //RESET-SET MODE
     3000                                           //Duty Cycle; higher = faster
};

/***************************************CONFIGURATION FOR RIGHT MOTOR THROUGH L398N MOTOR DRIVER BOARD******************FOR*TA0****************************/
Timer_A_PWMConfig pwmConfigRight =
{
     TIMER_A_CLOCKSOURCE_SMCLK,                     //3Mhz
     TIMER_A_CLOCKSOURCE_DIVIDER_24,                //3Mhz / 24 = 125000hz
     10000,                                         //Timer Period
     TIMER_A_CAPTURECOMPARE_REGISTER_2,             //TA0.2
     TIMER_A_OUTPUTMODE_RESET_SET,                  //RESET-SET MODE
     3000                                           //Duty Cycle; higher = faster
};

/***************************************CONFIGURATION FOR GENERAL COUNTING USE******************************************FOR*TA1****************************/
const Timer_A_UpModeConfig upConfig =
{
     TIMER_A_CLOCKSOURCE_SMCLK,                                     //3Mhz
     TIMER_A_CLOCKSOURCE_DIVIDER_48,                                //3Mhz / 48 = 62500hz
     62500,                                                         //62500 ticks = 1 second
     TIMER_A_TAIE_INTERRUPT_DISABLE,                                //Disabling Timer Interrupt (THIS IS TAIFG)
     TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE,                            //Enabling CCR0 Interrupt (THIS IS CCIFG)
     TIMER_A_SKIP_CLEAR                                             //clearing counter of Timer
};

/***************************************eUSCI UART CONFIGURATION**************************************************************************/
//http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSP430BaudRateConverter/index.html
/*
 * BAUD RATE calculated for:
 * 3MHz         (instead of 24Mhz)
 * 115200 BAUD RATE
 *
 * clockPrescalar   = 1
 * firstModReg      = 10
 * secondModReg     = 0
 * overSampling     = 1
 * */
eUSCI_UART_ConfigV1 UARTConfig =
{
     EUSCI_A_UART_CLOCKSOURCE_SMCLK,                    //CLK SRC as small clock = 3MHz
     1,                                                 //clockPrescalar
     10,                                                //firstModReg
     0,                                                 //secondModReg
     EUSCI_A_UART_NO_PARITY,
     EUSCI_A_UART_LSB_FIRST,
     EUSCI_A_UART_ONE_STOP_BIT,
     EUSCI_A_UART_MODE,
     EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION      //oversampling = 1
};


/***************************************MAIN LOOP********************************************************/
int main(void)
{
    /* Stop Watchdog  */
    MAP_WDT_A_holdTimer();
    //WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;


    printf("\nLogging System Status:\n");
    CAR_SetState(STATE_RESET);

    CAR_InitializeLeftMotor();
    CAR_InitializeRightMotor();


    /************************************PIN CONFIGURATION FOR LEFT WHEEL ENCODER*********************************************************************************/
    printf("CONFIGURING LEFT WHEEL ENCODER\n");
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P6, GPIO_PIN5);      //P6.5
    GPIO_clearInterruptFlag(GPIO_PORT_P6, GPIO_PIN5);
    GPIO_enableInterrupt(GPIO_PORT_P6, GPIO_PIN5);
    /************************************PIN CONFIGURATION FOR RIGHT WHEEL ENCODER*********************************************************************************/
    printf("CONFIGURING RIGHT WHEEL ENCODER\n");
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P6, GPIO_PIN4);      //P6.4
    GPIO_clearInterruptFlag(GPIO_PORT_P6, GPIO_PIN4);
    GPIO_enableInterrupt(GPIO_PORT_P6, GPIO_PIN4);

    /************************************TIMER A1 CONFIGURATION*********************************************************************************/
    Timer_A_configureUpMode(TIMER_A1_BASE, &upConfig);
    Timer_A_clearTimer(TIMER_A1_BASE);
    Timer_A_startCounter(TIMER_A1_BASE, TIMER_A_UP_MODE);

    /************************************PIN CONFIGURATION ULTRASONIC SENSOR*********************************************************************************/
    GPIO_setAsOutputPin(GPIO_PORT_P3, GPIO_PIN6);                       //P3.6 OUT set to LOW
    GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN6);
    GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P3, GPIO_PIN7);    //P3.7 IN

    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);                       //Lights up RED led when close
    GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);

    /************************************CONFIGURING ESP8266 MODULE*********************************************************************************/
    printf("CONFIGURING ESP8266 MODULE\n");
    //EUSCI A0 BASE (FOR PC INPUTS through ESP8266_Terminal() NOT WORKING)
    /*P1.2 UCA0 RXD*/
    /*P1.3 UCA0 TXD*/
    MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P1, GPIO_PIN2 | GPIO_PIN3, GPIO_PRIMARY_MODULE_FUNCTION);
    MAP_UART_initModule(EUSCI_A0_BASE, &UARTConfig);
    MAP_UART_enableModule(EUSCI_A0_BASE);
    MAP_UART_enableInterrupt(EUSCI_A0_BASE, EUSCI_A_UART_RECEIVE_INTERRUPT);

    //EUSCI A2 BASE (FOR WIFI MODULE)
    /*P3.2 UCA2 RXD, given the color GREEN wire*/
    /*P3.3 UCA2 TXD, given the color ORANGE wire*/
    MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P3, GPIO_PIN2 | GPIO_PIN3, GPIO_PRIMARY_MODULE_FUNCTION);
    MAP_UART_initModule(EUSCI_A2_BASE, &UARTConfig);
    MAP_UART_enableModule(EUSCI_A2_BASE);
    MAP_UART_enableInterrupt(EUSCI_A2_BASE, EUSCI_A_UART_RECEIVE_INTERRUPT);

    //Reset Pin
    /*P6.1, given the color YELLOW wire*/
    GPIO_setAsOutputPin(GPIO_PORT_P6, GPIO_PIN1);

    /*For visual checking during deployment(green=connected,)*/
    /*All lights up on error(White=error)*/
    GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN0);                       //Lights up Red when connected.
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0);
    GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN1);                       //Lights up Green when connected.
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1);
    GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN2);                       //Lights up Blue when connected.
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2);

    /*******************************************Final Closure Settings********************************************************************************************/
    printf("CONFIGURING CLOSURE\n");

    //S1 IS TEMPORARY DOWN BELOW HERE TO FACILITATE THE PWM
    /*Configuring P1.1 (button) as input with Active Low activation mechanism*/
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN1);
    /*Clearing Interrupt flag for Pin 1*/
    GPIO_clearInterruptFlag(GPIO_PORT_P1, GPIO_PIN1);
    /*Enabling Pin Interrupt*/
    GPIO_enableInterrupt(GPIO_PORT_P1, GPIO_PIN1);
    //S1 IS TEMPORARY UP ABOVE HERE TO FACILITATE THE PWM

    /*Enabling Interrupts*/
    Interrupt_enableInterrupt(INT_PORT1);       //for S1
    Interrupt_enableInterrupt(INT_PORT6);       //enables interrupt for wheel encoder
    Interrupt_enableInterrupt(INT_TA1_0);       //enables interrupt for Timer A1
    MAP_Interrupt_enableInterrupt(INT_EUSCIA0); //enables interrupt for EUSCI A0
    MAP_Interrupt_enableInterrupt(INT_EUSCIA2); //enables interrupt for EUSCI A2
    //Interrupt_enableSleepOnIsrExit();           //enables the processor to sleep when exiting an ISR; but messes with EUSCI
    Interrupt_enableMaster();
    MAP_Interrupt_enableMaster();
    MSPrintf(EUSCI_A0_BASE, "Interrupted Enabled\n\r");

    /*Setting up pointer to buffer*/
    char *ESP8266_Data = ESP8266_GetBuffer();
    char *command;

    /*Setting up connection*/

    /*Hard Reset ESP8266*/
    ESP8266_HardReset();
    __delay_cycles(6000000);
    /*flush reset data, we do this because a lot of data received cannot be printed*/
    UART_Flush(EUSCI_A2_BASE);
    __delay_cycles(3000000);
    MSPrintf(EUSCI_A0_BASE, "Hard Reset Performed\n\r");


     /*Check UART connection to MSP432*/
     if (!ESP8266_ChangeMode3())
     {
       MSPrintf(EUSCI_A0_BASE, "Failed to Change Mode\r\n");
       GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN0);
       GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN1);
       GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2);
       /*Trap MSP432 if failed connection*/
       while (1)
       ;
     }
       MSPrintf(EUSCI_A0_BASE, "SoftAP + Station Mode Enabled \n\r");


     /*Check UART connection to MSP432*/
     if (!ESP8266_SetSoftAP())
     {
        MSPrintf(EUSCI_A0_BASE, "Failed to set AP Mode\r\n");
        GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN0);
        GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN1);
        GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2);
        /*Trap MSP432 if failed connection*/
        while (1)
        ;
     }
        MSPrintf(EUSCI_A0_BASE, "ESP8266 Renamed \n\r");

     /*Check UART connection to MSP432*/
     if (!ESP8266_CheckConnection())
     {
        MSPrintf(EUSCI_A0_BASE, "Failed MSP432 UART connection\r\n");
        GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN0);
        GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN1);
        GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2);
        /*Trap MSP432 if failed connection*/
        while (1)
        ;
     }

     /*Enable multiple connections*/
     if (!ESP8266_MultiMode())
     {
        MSPrintf(EUSCI_A0_BASE, "Failed to set multiple connections\r\n");
        GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN0);
        GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN1);
        GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2);
        while (1)
        ;
     }


     MSPrintf(EUSCI_A0_BASE, "Multiple Connections Enabled\n\r");
     /*Connect to Access Point if necessary here*/
     MSPrintf(EUSCI_A0_BASE, "Connecting to Wifi... \n\r");
     while (!ESP8266_ConnectToAP("Guthixo", "Guthixo1"))
     {
        /*Trap MSP432 we do not have a connection to an AP*/
        MSPrintf(EUSCI_A0_BASE, "Please Wait... \n\r");
     }

     MSPrintf(EUSCI_A0_BASE, "Connected to Mobile hotspot!\n\r");


      /*Declaring connection settings*/
      char HTTP_WebPage[] = "192.168.43.241";
      char Port[] = "80";
      char HTTP_Request[] = "GET /sendInstructions HTTP/1.1\r\n\r\n";
      uint32_t HTTP_Request_Size = sizeof(HTTP_Request) - 1;

     /*Loop to keep sending GET request to webpage for retrieval of commands to exeecute*/
     while(1)
     {

     /*Try to establish TCP connection to a HTTP server*/
     if(!ESP8266_EstablishConnection('0', TCP, HTTP_WebPage, Port))
     {
         MSPrintf(EUSCI_A0_BASE, "Failed to connect to: %s\r\nERROR: %s\r\n", HTTP_WebPage, ESP8266_Data);
         GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN0);
         GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN1);
         GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2);
         while(1)
         ;
     }

     MSPrintf(EUSCI_A0_BASE, "TCP Connection Established \n\r");

     /*Query data to connected HTTP server, in order to do this look for an API and request a key*/
     if(!ESP8266_SendData('0', HTTP_Request, HTTP_Request_Size))
     {
         MSPrintf(EUSCI_A0_BASE, "Failed to send: %s to %s \r\nError: %s\r\n", HTTP_Request, HTTP_WebPage, ESP8266_Data);
         GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN0);
         GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN1);
         GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2);
         while(1);
     }
    /*Pointer to extract commands received from wifi module*/
    command = strstr(ESP8266_Data, "==");
    MSPrintf(EUSCI_A0_BASE, "Data sent: %s to %s\r\n\r\nCommand to execute%s\r\n", HTTP_Request, HTTP_WebPage, ESP8266_Data);


    char * ptr = command;
    ptr++;
    ptr++;
    ptr++;

    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN1);

    /*Sleeping loop for power efficiency*/
    while(1){

        printf("%c", *ptr);

        char instruction = *ptr;

        switch (instruction)
        {
            case 'F':
                CAR_Forward();
                __delay_cycles(9000000);
                CAR_Stop();
                *ptr=' ';
                ptr++;
                break;

            case 'L':
                CAR_TurnLeft();
                __delay_cycles(9000000);
                CAR_Stop();
                *ptr=' ';
                ptr++;
                break;

            case 'R':
                CAR_TurnRight();
                __delay_cycles(9000000);
                CAR_Stop();
                *ptr=' ';
                ptr++;
                break;

        }

        if (instruction == '.')
        {
            UART_Flush(EUSCI_A2_BASE);
            GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1);
            __delay_cycles(4500000);
            break;
        }
    }

  }

}

float SR04_GetDistance(void){
    uint32_t echopulseduration = 0;
    float timetaken = 0;
    float calculateddistance = 0;

    Timer_A_clearTimer(TIMER_A1_BASE);

    //pulse out of p3.6 for 10us
    GPIO_setOutputHighOnPin(GPIO_PORT_P3, GPIO_PIN6);
    Delay(30);
    GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN6);

    while(GPIO_getInputPinValue(GPIO_PORT_P3, GPIO_PIN7) == 0); //busy wait for response

    Timer_A_clearTimer(TIMER_A1_BASE);
    Timer_A_startCounter(TIMER_A1_BASE, TIMER_A_UP_MODE);

    while(GPIO_getInputPinValue(GPIO_PORT_P3, GPIO_PIN7) == 1); //busy wait for response to finish

    echopulseduration = Timer_A_getCounterValue(TIMER_A1_BASE);
    //1tick = 16us
    float tick = 0.000016;
    timetaken = echopulseduration * tick;                       //time taken in seconds

    calculateddistance = ((float)timetaken * 343) / 2;          //dist in meters

    return calculateddistance;
}


/*******************************************PORT1 IRQ HANDLER********************************************************************************************/
//for now, S1 to reset to speed and initialize them again
void PORT1_IRQHandler(void)
{
    uint32_t status = MAP_GPIO_getEnabledInterruptStatus(GPIO_PORT_P1);

    if(status & GPIO_PIN1) //if there is interrupt on P1.1
    {
        CAR_Forward();
    }
    GPIO_clearInterruptFlag(GPIO_PORT_P1, status);
}


/*******************************************PORT6 IRQ HANDLER********************************************************************************************/
void PORT6_IRQHandler(void){
    if (P6->IFG & BIT4){
//        printf("RIGHT WHEEL ENCODER 1 NOTCH\n");                //To comment out to not mess with timing
        NOTCH_RightCountTotal = NOTCH_RightCountTotal + 1;
        //printf("TOTAL NOTCH: %d", NOTCH_RightCountTotal);
        GPIO_clearInterruptFlag(GPIO_PORT_P6, BIT4);
    }
    else if (P6->IFG & BIT5){
//        printf("LEFT WHEEL ENCODER 1 NOTCH\n");                 //To comment out to not mess with timing
        NOTCH_LeftCountTotal = NOTCH_LeftCountTotal + 1;
        //printf("TOTAL NOTCH: %d", NOTCH_LeftCountTotal);
        GPIO_clearInterruptFlag(GPIO_PORT_P6, BIT4);
    }
}


/*******************************************TIMER A1 IRQ HANDLER********************************************************************************************/
void TA1_0_IRQHandler(void){
    //every 1s log data
    CAR_UpTime = CAR_UpTime + 1;
    //printf("Car Up-time: %d seconds\n", CAR_UpTime);

    if (CAR_UpTime % 2 == 0) {          //Use SR04 every 2s
        float distinm = SR04_GetDistance();
        float distincm = distinm * 100;
        if (distincm < MIN_DISTANCE){
            GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0);
            printf("!!OBJECT DETECTED CLOSE AHEAD (%f cm)!!\n", distincm);
            //stop the car
            CAR_Stop();
        }
        else{
            GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
            //for future use, do nothing as of the moment
        }
    }
    else if (CAR_UpTime % 5 == 0){      //Calculate speed and distance travelled
        CAR_DistanceTraveled += CalculateDistanceTraveled(CalculateAverageNotches(NOTCH_LeftCountTotal, NOTCH_RightCountTotal));
        printf("Total Distance Traveled: %f cm\n", CAR_DistanceTraveled);
        CAR_AverageSpeed = CalculateSpeed(CAR_DistanceTraveled, CAR_UpTime);
        printf("Speed: %f cm/s\n", CAR_AverageSpeed);
    }
    else if (CAR_UpTime % 1 == 0 && CAR_STATE == STATE_MOVING){        //Use PID every 1 second

        PID_Controller(NOTCH_LeftCountTotal, NOTCH_RightCountTotal);
    }

    //Clear Interrupt flag
    Timer_A_clearCaptureCompareInterrupt(TIMER_A1_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_0); //clearing the CCR interrupt
}

