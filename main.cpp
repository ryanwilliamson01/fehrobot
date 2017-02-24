/*
 *  - OFFICIAL MINECRAFT ROBOT TEAM -
 *
 *  Group C6
 *  Joe Forsman / Carson McCasland / Bailey Mulhern / Ryan Williamson
 *
 *  Code Outline
 *  Version 4.0
 *  2/21/17 12:48PM
 *
 */

#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHServo.h>


#include "motormethods.h"
#include "sensormethods.h"
#include "utilitymethods.h"

#include "motormethods.cpp"
#include "sensormethods.cpp"
#include "utilitymethods.cpp"


//Defining Tasks
#define TASK_DRIVE_FORWARD 0
#define TASK_DRIVE_BACKWARDS 1
#define TASK_TURN_LEFT 2
#define TASK_TURN_RIGHT 3
//Defining States
#define CDS_LIGHT_NONE 0
#define CDS_LIGHT_RED 1
#define CDS_LIGHT_BLUE 2
#define STATE_ON_LINE 0
#define STATE_OFF_LINE_LEFT 1
#define STATE_OFF_LINE_RIGHT 2


int main(void)
{
    LCD.Clear(FEHLCD::Black);
    LCD.SetFontColor(FEHLCD::White);

    int motor_percent = 25; //Input power level here
    int expected_counts_right90 = 205; //Input theoretical counts here
    int expected_counts_10 = 405;
    int expected_counts_14 = 566;
    int expected_counts_4 = 162;


    //setCdSThreshold();
    StartLight();




    //Leave starting block
    DriveBackward(40,3);
    Sleep(500);
    //Turn towards wall
    turnLeft(40,2.35);
    Sleep(500);
    DriveBackward(40,3);
    Sleep(500);
    turnLeft(40,2.2);
    Sleep(500);
    //Drive until we run into the ramp wall
    DriveBackward(30);
    //Hit the first wall
    while(!isBackPressed())
    {
        Sleep(10);
    }
    stop();
    Sleep(500);
    //Turn around to go up the ramp
    turnLeft(30,2.55);
    Sleep(300);
    DriveForward(20,3.2);
    Sleep(300);
    turnLeft(30,3.3);
    Sleep(500);
    //Drive up the ramp. High power at first
    DriveBackward(55,25);
    DriveBackward(25);
    //Drive to the button
    turnLeft(40,.4);
    DriveBackward(50,25);
    //Ram into the button for 1 second to make sure its pressed
    DriveBackward(50);
    Sleep(1000);
    stop();
    //Wait until the button si pressed
    Sleep(4000);

    //Drive from the button to the lever
    DriveForward(30,16);
    turnLeft(40,5.5);
    DriveBackward(30,25);
    //Hit the button
    while(!isBackPressed())
    {
        Sleep(10);
    }
    //Stop when we hit the lever
    stop();



    return 0;
}
