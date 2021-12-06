#include "ESP8266.h"

#define RESET_PIN       GPIO_PIN1
#define RESET_PORT      GPIO_PORT_P6
#define AT              "AT\r\n" // test module
#define AT_RST          "AT+RST\r\n" //restart module
#define AT_GMR          "AT+GMR\r\n" //view firmware
#define AT_GSLP         "AT+GSLP\r\n"
#define ATE             "ATE\r\n" // Enable disable echo
#define AT_CWMODE       "AT+CWMODE\r\n" // 1 WiFi (client), 2 (host), 3 both
#define AT_CWJAP        "AT+CWJAP_DEF" // connect to Wi-Fi
#define AT_CWLAP        "AT+CWLAP\r\n" // list all wifi
#define AT_CWQAP        "AT+CWQAP\r\n" //disconnect from AP
#define AT_CWLIF        "AT+CWLIF\r\n" // List all clients connected
#define AT_CWDHCP       "AT+CWDHCP\r\n" // enable dhcp 0 AP, 1 WiFi, 2 both
#define AT_CIPSTAMAC    "AT+CIPSTAMAC\r\n" //view and change mac address of wifi
#define AT_CIPAPMAC     "AT+CIPAPMAC\r\n"
#define AT_CIPSTA       "AT+CIPSTA\r\n" // check wifi IP address
#define AT_CIPAP        "AT+CIPAP" // check AP IP address
#define AT_CIPSTATUS    "AT+CIPSTATUS\r\n"
#define AT_CIPSTART     "AT+CIPSTART"
#define AT_CIPSEND      "AT+CIPSEND"
#define AT_CIPCLOSE     "AT+CIPSEND\r\n"
#define AT_CIFSR        "AT+CIFSR\r\n"
#define AT_CIPMUX       "AT+CIPMUX"
#define AT_CIPSERVER    "AT+CIPSTO\r\n"
#define AT_CIPMODE      "AT+CIPMODE\r\n"
#define AT_CIPSTO       "AT+CIPSTO\r\n"
#define AT_CIUPDATE     "AT+CIUPDATE\r\n"
#define IPD             "+IPD\r\n"

char ESP8266_Buffer[ESP8266_BUFFER_SIZE];

bool ESP8266_WaitForAnswer(uint32_t Tries)
{
    uint32_t c;
    uint32_t i = 0;

    while(Tries)
    {
        if(UARTA2WriteIndex - UARTA2ReadIndex){

            while(UARTA2WriteIndex - UARTA2ReadIndex){
                UART_Read(EUSCI_A2_BASE, (uint8_t*)&c, 1);

                if(i > ESP8266_BUFFER_SIZE)
                {
                    return false;
                }
                else
                {
                    ESP8266_Buffer[i++] = c;
                }
            }

            ESP8266_Buffer[i++] = 0;
            return true;
        }
        Tries--;
        __delay_cycles(2400*10);
    }

    return false;
}

bool ESP8266_CheckConnection(void)
{
    UART_Printf(EUSCI_A2_BASE, AT);
    __delay_cycles(12000);
    if(!ESP8266_WaitForAnswer(ESP8266_RECEIVE_TRIES))
    {
        return false;
    }

    if(strstr(ESP8266_Buffer, "OK") == NULL)
    {
        return false;
    }

    return true;
}

bool ESP8266_AvailableAPs(void)
{
    UART_Printf(EUSCI_A2_BASE, AT_CWLAP);
    __delay_cycles(48000000);
    if(!ESP8266_WaitForAnswer(ESP8266_RECEIVE_TRIES))
    {
        return false;
    }

    if(strstr(ESP8266_Buffer, "OK") == NULL)
    {
        return false;
    }

    return true;
}

bool ESP8266_ChangeMode3(void)
{
    UART_Printf(EUSCI_A2_BASE, "AT+CWMODE=3\r\n");

    __delay_cycles(24000000);
    if(!ESP8266_WaitForAnswer(ESP8266_RECEIVE_TRIES))
    {
        return false;
    }

    if(strstr(ESP8266_Buffer, "OK") == NULL)
    {
        return false;
    }

    return true;
}

bool ESP8266_SetSoftAP(void)
{
    UART_Printf(EUSCI_A2_BASE, "AT+CWSAP=\"Guthixo's esp8266\",\"Guthixo1\",5,3\r\n");

    __delay_cycles(24000000);
    if (!ESP8266_WaitForAnswer(ESP8266_RECEIVE_TRIES))
    {
        return false;
    }

    if (strstr(ESP8266_Buffer, "OK") == NULL)
    {
        return false;
    }
    return true;
}

bool ESP8266_ConnectToAP(char *SSID, char *Password)
{
    UART_Printf(EUSCI_A2_BASE, "%s=\"%s\",\"%s\"\r\n", AT_CWJAP, SSID, Password);


    __delay_cycles(24000000);
    if(!ESP8266_WaitForAnswer(ESP8266_RECEIVE_TRIES))
    {
        return false;
    }

    if(strstr(ESP8266_Buffer, "WIFI CONNECTED") == NULL)
    {
        return false;
    }

    return true;
}

bool ESP8266_EnableMultipleConnections(bool Enable)
{
    char c;

    switch(Enable)
    {
    case 0:
        c = '0';
        break;
    case 1:
        c = '1';
        break;
    }

    UART_Printf(EUSCI_A2_BASE, "%s=%c\r\n", AT_CIPMUX, c);

    __delay_cycles(12000000);
    if(!ESP8266_WaitForAnswer(ESP8266_RECEIVE_TRIES))
    {
        return false;
    }

    if(strstr(ESP8266_Buffer, "OK") == NULL)
    {
        return false;
    }

    return true;
}

bool ESP8266_MultiMode(void)
{
    UART_Printf(EUSCI_A2_BASE, " AT+CIPMUX=1\r\n");

    __delay_cycles(10000000);
    if(!ESP8266_WaitForAnswer(ESP8266_RECEIVE_TRIES))
    {
        return false;
    }

    if(strstr(ESP8266_Buffer, "OK") == NULL)
    {
        return false;
    }

    return true;
}


bool ESP8266_ListInformation(void)
{
    UART_Printf(EUSCI_A2_BASE, " AT+CWLIF\r\n");
    __delay_cycles(48000000);
    if(!ESP8266_WaitForAnswer(ESP8266_RECEIVE_TRIES))
    {
        return false;
    }

    if(strstr(ESP8266_Buffer, "OK") == NULL)
    {
        return false;
    }

    return true;
}

bool ESP8266_EstablishConnection(char ID, uint8_t type, char *address, char *port)
{
    char ct[3];

    switch(type)
    {
    case TCP:
        ct[0] = 'T';
        ct[1] = 'C';
        ct[2] = 'P';
        break;
    case UDP:
        ct[0] = 'U';
        ct[1] = 'D';
        ct[2] = 'P';
        break;
    }

    MSPrintf(EUSCI_A2_BASE, "%s=%c,\"%s\",\"%s\",%s\r\n", AT_CIPSTART, ID, ct, address, port);

    __delay_cycles(6000000);

    if(!ESP8266_WaitForAnswer(ESP8266_RECEIVE_TRIES))
    {
        return false;
    }

    if(strstr(ESP8266_Buffer, "OK") == NULL)
    {
        return false;
    }

    return true;
}


bool ESP8266_SendData(char ID, char *Data, uint32_t DataSize)
{
    char size[5];

    ltoa(DataSize, size, 10);
    UART_Printf(EUSCI_A2_BASE, "%s=%c,%s\r\n", AT_CIPSEND, ID, size);

    __delay_cycles(3000000);
    if(!ESP8266_WaitForAnswer(ESP8266_RECEIVE_TRIES))
    {
        return false;
    }

    if(strstr(ESP8266_Buffer, ">") == NULL)
    {
        return false;
    }

    UART_Printf(EUSCI_A2_BASE, Data);

    __delay_cycles(6000000);//48000000
    if(!ESP8266_WaitForAnswer(ESP8266_RECEIVE_TRIES))
    {
        return false;
    }


    if(strstr(ESP8266_Buffer, "OK") == NULL)
    {
        return false;
    }

    return true;
}

void ESP8266_Terminal(void)
{
    while(1)
    {
        UART_Gets(EUSCI_A0_BASE, ESP8266_Buffer, 128);
        UART_Printf(EUSCI_A2_BASE, ESP8266_Buffer);

        __delay_cycles(48000000);
        if(!ESP8266_WaitForAnswer(ESP8266_RECEIVE_TRIES))
        {
            UART_Printf(EUSCI_A0_BASE, "ESP8266 receive timeout error\r\n");
        }
        else
        {
            UART_Printf(EUSCI_A0_BASE, ESP8266_Buffer);
        }

    }
}

char *ESP8266_GetBuffer(void)
{
    return ESP8266_Buffer;
}

void ESP8266_HardReset(void)
{
    MAP_GPIO_setOutputLowOnPin(RESET_PORT, RESET_PIN);

    __delay_cycles(3000000);

    MAP_GPIO_setOutputHighOnPin(RESET_PORT, RESET_PIN);

    __delay_cycles(6000000);
}


