/* DriverLib Includes */
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

/* Standard C Includes */
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

/*Movement-Instruction Definition*/
#define MOVE_LEFT "L"
#define MOVE_RIGHT "R"
#define MOVE_FORWARD "F"
#define MOVE_BACKWARD "B"
#define MIN_DISTANCE 25.0f                  //15cm

/*STATES OF CAR*/
#define STATE_RESET 0                       //Initializing
#define STATE_IDLE 1                        //After initialization
#define STATE_CONNECTED 2                   //Connected to WI
#define STATE_MOVING 3                      //Car moving
#define STATE_TURNINGLEFT 4
#define STATE_TURNINGRIGHT 5
#define STATE_STOPPED 6                     //Car not moving
int CAR_STATE = 0;                          //State of car

/*Standard Constants*/
//1 full rotation is 20 notches -> 21.5cm ; 1 notch = 1.075cm
const float NOTCH_1Length = 1.075;
const float NOTCH_20Length = 21.5;


/*Global Variables*/
int NOTCH_LeftCountTotal = 0;               //Total Left Notches counted
int NOTCH_RightCountTotal = 0;              //Total Right Notches counted

int CAR_UpTime = 0;                         //Total Minicar uptime, nearest seconds
float CAR_DistanceTraveled = 0.0;
float CAR_AverageSpeed = 0.0;
