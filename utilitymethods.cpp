/*
 *  - OFFICIAL MINECRAFT ROBOT TEAM -
 *
 *  Group C6
 *  Joe Forsman / Carson McCasland / Bailey Mulhern / Ryan Williamson
 *
 *  Utility Methods
 *  Version 1.0
 *  2/21/17 12:57PM
 *
 */

#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHServo.h>

#include "utilitymethods.h"
#include "motormethods.h"
#include "sensormethods.h"

//Defining States
#define CDS_LIGHT_NONE 0
#define CDS_LIGHT_RED 1
#define CDS_LIGHT_BLUE 2

/*
 * Waits for a screen touch to begin
 */
void StartTouch()
{
    float x,y;

    LCD.Clear( FEHLCD::Black );
    LCD.SetFontColor( FEHLCD::White );

    LCD.WriteLine("Press the Screen to Begin");

    while(!LCD.Touch(&x,&y))
    {
        Sleep(50);
    }

    LCD.Clear(FEHLCD::Black);
    LCD.WriteLine("Starting in 2 seconds...");
    Sleep(2000);
}

/*
 * Waits for the start light to begin
 */
void StartLight()
{
    LCD.Clear( FEHLCD::Black );
    LCD.SetFontColor( FEHLCD::White );
    LCD.WriteLine("Waiting for the red start light...");

    //Creating a timeout counter
    int timeout = 15000;
    int timeoutCounter = 0;

    while(true)
    {
        //If the red light is detected
        if(getLightColor() == CDS_LIGHT_RED)
        {
            LCD.WriteLine("The red light has been detected!");
            break;
        }
        //If the counter timed out
        if(timeoutCounter == timeout)
        {
            LCD.WriteLine("No light has been detected and has timed out!");
            break;
        }

        timeoutCounter++;
        Sleep(1);
    }
}

/*
 * Calibrates all motors and sensors
 *
 * @return true if all motors and sensors were initialized correctly, false if anything went wrong or needs attention
 */
bool Calibrate()
{
    /*
     * INSERT CODE HERE
     */
}

/*
 * Displays all important values to the screen for use in debugging the robot
 */
void Display()
{
    /*
     * INSERT CODE HERE
     */
}
