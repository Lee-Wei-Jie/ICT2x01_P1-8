/* This file includes the movement logic that will be perform by the car
 *
 * Has been placed here to reduce clutter
 * */

//external variable declarations
//extern const float NOTCH_1Length;
extern Timer_A_PWMConfig pwmConfigLeft;
extern Timer_A_PWMConfig pwmConfigRight;


//Computes & returns the average notch counted by left and right wheel encoder
int CalculateAverageNotches(int left, int right){
    return (left + right) / 2;
}

//Computes & return the Distance traveled with the length of 1 notch (1.075cm)
float CalculateDistanceTraveled(int totalNotches){
    return (totalNotches * NOTCH_1Length);
}

//Computes and returns the Speed, given the Distance traveled and time ticked
//where distance = cm, time = s; cm/s
float CalculateSpeed(float distance, int time){
    return (distance / time);
}

//Simple busy wait function, using system clock (1/3M)
void Delay(uint32_t loops){
    volatile uint32_t i;
    for (i = 0; i < loops; i++);
}


//Set the state of the car
void CAR_SetState(int state){
    CAR_STATE = state;
    switch(CAR_STATE){
        case 0:
            printf("STATE: RESET\n");
            break;
        case 1:
            printf("STATE: IDLE\n");
            break;
        case 2:
            printf("STATE: CONNECTED\n");
            break;
        case 3:
            printf("STATE: MOVING\n");
            break;
        case 4:
            printf("STATE: TURNING LEFT\n");
            break;
        case 5:
            printf("STATE: TURNING RIGHT\n");
            break;
        case 6:
            printf("STATE: STOPPED\n");
            break;
    }
}

void CAR_InitializeLeftMotor(void){
    /*Configuring P4.4 and P4.5 as Output //// Controls the Left Motor
     * IN1 = HIGH && IN2 = LOW
     * FORWARD
     * IN1 = LOW && IN2 = HIGH
     * BACKWARD*/
    printf("CONFIGURING LEFT MOTOR\n");
    GPIO_setAsOutputPin(GPIO_PORT_P4, GPIO_PIN5);           //IN2;These are set to control the direction; Must be added for motor to run
    GPIO_setAsOutputPin(GPIO_PORT_P4, GPIO_PIN4);           //IN1;These are set to control the direction; Must be added for motor to run

    /*Setting P4.4 on Low, P4.5 on High*/
    GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN5);        //P4.5 LOW
    GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN4);       //P4.4 HIGH

    /*Configuring P2.4 as PWM (PRIMARY MODULE FUNCTION for PWM)*/
    GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P2, GPIO_PIN4, GPIO_PRIMARY_MODULE_FUNCTION);

    pwmConfigLeft.dutyCycle = 3000;
}

void CAR_InitializeRightMotor(void){
    /*Configuring P4.0 and P4.2 as Output //// Controls the Left Motor
     * IN1 = HIGH && IN2 = LOW
     * FORWARD
     * IN1 = LOW && IN2 = HIGH
     * BACKWARD*/
    printf("CONFIGURING RIGHT MOTOR\n");
    GPIO_setAsOutputPin(GPIO_PORT_P4, GPIO_PIN2);
    GPIO_setAsOutputPin(GPIO_PORT_P4, GPIO_PIN0);

    /*Setting P4.4 on Low, P4.5 on High*/
    GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN2);        //P4.2 LOW
    GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN0);       //P4.0 HIGH

    /*Configuring P2.5 as PWM (PRIMARY MODULE FUNCTION for PWM)*/
    GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P2, GPIO_PIN5, GPIO_PRIMARY_MODULE_FUNCTION);

    pwmConfigRight.dutyCycle = 4000;
}

//Generate PWM for car
void CAR_GeneratePWM(void){
    /*Generating PWM to the left motor, approx 80ms period*/
    Timer_A_generatePWM(TIMER_A0_BASE, &pwmConfigLeft);                 //TA0.1
    printf("LEFT MOTOR GENERATED\n");
    /*Generating PWM to the right motor, approx 80ms period*/
    Timer_A_generatePWM(TIMER_A0_BASE, &pwmConfigRight);                //TA0.2
    printf("RIGHT MOTOR GENERATED\n");
}

void CAR_Forward(void){
    //Due to the nature of how the motor is being initialized (default is forward)
    //We will call to re-initialize it here
    CAR_InitializeLeftMotor();
    CAR_InitializeRightMotor();
    CAR_GeneratePWM();
    printf("CAR MOVING FORWARD\n");
    CAR_SetState(STATE_MOVING);
}

//Stop Car
void CAR_Stop(void){
    pwmConfigLeft.dutyCycle = 0;
    pwmConfigRight.dutyCycle = 0;
    Timer_A_generatePWM(TIMER_A0_BASE, &pwmConfigLeft);  //generate the PWM again
    Timer_A_generatePWM(TIMER_A0_BASE, &pwmConfigRight); //generate the PWM again
    printf("CAR STOPPED\n");
    CAR_SetState(STATE_STOPPED);
}

//Turn Right Car
void CAR_TurnRight(void){
    printf("TURNING RIGHT \n");
    CAR_SetState(STATE_TURNINGRIGHT);
    /****SWAP OUTPUT SIDE****/
    //LEFT WHEEL don't move
    pwmConfigLeft.dutyCycle = 0;
    //RIGHT WHEEL REVERSE
    pwmConfigRight.dutyCycle = 2800;
    /*For right wheel to move forward*/
    GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN0);    //P4.0 LOW
    GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN2);   //P4.2 HIGH
    CAR_GeneratePWM();
    CAR_SetState(STATE_CONNECTED);
}

//Turn Left Car
void CAR_TurnLeft(void){
    printf("TURNING LEFT \n");
    CAR_SetState(STATE_TURNINGLEFT);
    /****SWAP OUTPUT SIDE****/
    //RIGHT WHEEL turns only
    pwmConfigRight.dutyCycle = 3300;
    //LEFT WHEEL don't move
    pwmConfigLeft.dutyCycle = 0;
    /*For right wheel to move forward*/
    GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN2);    //P4.2 LOW
    GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN0);   //P4.0 HIGH
    CAR_GeneratePWM();
    CAR_SetState(STATE_CONNECTED);
}

int PID_Controller(int leftnotch, int rightnotch){
    if (CAR_STATE == STATE_TURNINGLEFT || CAR_STATE == STATE_TURNINGRIGHT){
        NOTCH_LeftCountTotal = 0;
        NOTCH_RightCountTotal = 0;
        return 1;
    }
    if (leftnotch != rightnotch){
        if(leftnotch > rightnotch){
            //boost right side
            pwmConfigRight.dutyCycle += 250;
            CAR_GeneratePWM();
        }
        else if(leftnotch < rightnotch){
            //boost LEFT side
            pwmConfigLeft.dutyCycle += 250;
            CAR_GeneratePWM();
        }
    }
    else if (leftnotch == rightnotch){

    }
    return 1;       //normal wheel situation
}



