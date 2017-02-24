/*
 *  - OFFICIAL MINECRAFT ROBOT TEAM -
 *
 *  Group C6
 *  Joe Forsman / Carson McCasland / Bailey Mulhern / Ryan Williamson
 *
 *  Sensor Methods
 *  Version 1.0
 *  2/21/17 12:57PM
 *
 */

#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHServo.h>

#include "sensors.h"

//Defining Pins
#define BUMP_FRONT_LEFT //FEHIO::P0_0 INSERT BUMP PINS
#define BUMP_FRONT_RIGHT //INSERT BUMP PINS
#define BUMP_BACK_LEFT //INSERT BUMP PINS
#define BUMP_BACK_RIGHT //INSERT BUMP PINS
#define CDS_CELL FEHIO::P0_0//FEHIO::P0_0 INSERT CDS CELLS PINS
#define ANALOG_OPTOSENSOR_LEFT //FEHIO::P0_0 INSERT ANALOG OPTOSENSOR PINS
#define ANALOG_OPTOSENSOR_MIDDLE //INSERT ANALOG OPTOSENSOR PINS
#define ANALOG_OPTOSENSOR_RIGHT //INSERT ANALOG OPTOSENSOR PINS

//Defining States
#define CDS_LIGHT_NONE 0
#define CDS_LIGHT_RED 1
#define CDS_LIGHT_BLUE 2
#define STATE_ON_LINE 0
#define STATE_OFF_LINE_LEFT 1
#define STATE_OFF_LINE_RIGHT 2

//Declaring Bump Switches
DigitalInputPin bumpFrontLeft(BUMP_FRONT_LEFT);
DigitalInputPin bumpFrontRight(BUMP_FRONT_RIGHT);
DigitalInputPin bumpBackLeft(BUMP_BACK_LEFT);
DigitalInputPin bumpBackRight(BUMP_BACK_RIGHT);
//Declaring CdS Cell
AnalogInputPin CdSCell(CDS_CELL);
//Declaring Analog OptoSensors
AnalogInputPin analogOptosensorLeft(ANALOG_OPTOSENSOR_LEFT);
AnalogInputPin analogOptosensorMiddle(ANALOG_OPTOSENSOR_MIDDLE);
AnalogInputPin analogOptosensorRight(ANALOG_OPTOSENSOR_RIGHT);

//Set CdS Cell Thresholds
double lightThresholdBlue;
double lightThresholdBlueTolerance;
double lightThresholdRed;
double lightThresholdRedTolerance;
double lightThresholdNone;
double lightThresholdNoneTolerance;

//Set OptoSensor Thresholds
double lineThresholdOrangeLeft;
double lineThresholdOrangeMiddle;
double lineThresholdOrangeRight;

// Bump Switches

/*
 * Returns the value of the given bump switch
 *
 * @return true if the bump switch is pressed, false if it is not
 */
bool isPressed(DigitalInputPin bump)
{
    /*
     * INSERT CODE HERE
     */
}

/*
 * Returns whether or not both front bump switches are pressed
 *
 * @return true if both front bump switches are pressed, false if one or both are not pressed
 */
bool IsFrontPressed()
{
    /*
     * INSERT CODE HERE
     */
}

/*
 * Returns whether or not both back bump switches are pressed
 *
 * @return true if both back bump switches are pressed, false if one or both are not pressed
 */
bool isBackPressed()
{
    /*
     * INSERT CODE HERE
     */
}





// CdS Cell

/*
 * Sets the threshholds for various colors of light
 */
void setCdSThreshold()
{
    // - RECORDING THE NO LIGHT VALUES -

    //Waiting for the User to Touch the Screen
    float x,y;
    LCD.Clear( FEHLCD::Black );
    LCD.SetFontColor( FEHLCD::White );
    LCD.WriteLine("Setting CdS Threshold");
    LCD.WriteLine("Recording the No Light Values");
    LCD.WriteLine("Press the Screen to Begin");
    while(!LCD.Touch(&x, &y))
    {
        Sleep(10);
    }

    //Begin Recording Values for the No Light Threshold
    double max = 0;
    double min = 3.3;
    double average = 0;

    for(int i = 0; i < 100; i++)
    {
        //Reading in the value
        double reading = CdSCell.Value();
        average += reading;

        //Recording the min and max
        if(reading > max)
        {
            max = reading;
        }
        else if(reading < min)
        {
            min = reading;
        }

        Sleep(50);
    }

    //Recording the average threshold
    average = average / 100.0;
    lightThresholdNone = average;

    //Calculating the threshold
    if(max - average > average - min)
    {
        lightThresholdNoneTolerance = max - average;
    }
    else
    {
        lightThresholdNoneTolerance = average - min;
    }

    // - RECORDING THE RED LIGHT VALUES -

    //Waiting for the User to Touch the Screen
    LCD.Clear( FEHLCD::Black );
    LCD.SetFontColor( FEHLCD::White );
    LCD.WriteLine("Recording the Red Light Values");
    LCD.WriteLine("Press the Screen to Begin");
    while(!LCD.Touch(&x, &y))
    {
        Sleep(10);
    }

    //Begin recording values for the red light
    max = 0;
    min = 3.3;
    average = 0;

    for(int i = 0; i < 100; i++)
    {
        //Reading in the value
        double reading = CdSCell.Value();
        average += reading;

        //Recording the min and max
        if(reading > max)
        {
            max = reading;
        }
        else if(reading < min)
        {
            min = reading;
        }

        Sleep(50);
    }

    //Recording the average threshold
    average = average / 100.0;
    lightThresholdRed = average;

    //Calculating the threshold
    if(max - average > average - min)
    {
        lightThresholdRedTolerance = max - average;
    }
    else
    {
        lightThresholdRedTolerance = average - min;
    }

    // - RECORDING THE BLUE LIGHT VALUES -

    //Waiting for the User to Touch the Screen
    LCD.Clear( FEHLCD::Black );
    LCD.SetFontColor( FEHLCD::White );
    LCD.WriteLine("Recording the Blue Light Values");
    LCD.WriteLine("Press the Screen to Begin");
    while(!LCD.Touch(&x, &y))
    {
        Sleep(10);
    }

    //Begin recording values for the blue right
    max = 0;
    min = 3.3;
    average = 0;

    for(int i = 0; i < 100; i++)
    {
        //Reading in the value
        double reading = CdSCell.Value();
        average += reading;

        //Recording the min and max
        if(reading > max)
        {
            max = reading;
        }
        else if(reading < min)
        {
            min = reading;
        }

        Sleep(50);
    }

    //Recording the average threshold
    average = average / 100.0;
    lightThresholdBlue = average;

    //Calculating the threshold
    if(max - average > average - min)
    {
        lightThresholdBlueTolerance = max - average;
    }
    else
    {
        lightThresholdBlueTolerance = average - min;
    }

    DisplayCdSCell();
}

/*
 * Displays the values of the light thresholds and tolerances
 */
void DisplayCdSCell()
{
    //Clear the Screen
    LCD.Clear( FEHLCD::Black );

    //Drawing the colored rectangles
    LCD.SetFontColor(FEHLCD::White);
    LCD.FillRectangle(0,39,40,40);
    LCD.SetFontColor(FEHLCD::Red);
    LCD.FillRectangle(0,89,40,40);
    LCD.SetFontColor(FEHLCD::Blue);
    LCD.FillRectangle(0,139,40,40);

    //Displaying the text displaying the threshold and tolerance values
    LCD.SetFontColor(FEHLCD::White);

    LCD.WriteAt("No Light Threshold: ", 49, 40);
    LCD.WriteAt(lightThresholdNone, 49 + 12*21, 40);
    LCD.WriteAt("No Light Tolerance: ", 49, 60);
    LCD.WriteAt(lightThresholdNoneTolerance, 49 + 12*21, 60);

    LCD.WriteAt("Red Light Threshold: ", 49, 90);
    LCD.WriteAt(lightThresholdRed, 49 + 12*22, 90);
    LCD.WriteAt("Red Light Tolerance: ", 49, 110);
    LCD.WriteAt(lightThresholdRedTolerance, 49 + 12*22, 110);

    LCD.WriteAt("Blue Light Threshold: ", 49, 140);
    LCD.WriteAt(lightThresholdBlue, 49 + 12*23, 140);
    LCD.WriteAt("Blue Light Tolerance: ", 49, 160);
    LCD.WriteAt(lightThresholdBlueTolerance, 49 + 12*23, 160);
}

/*
 * Returns an int value corresponding to the value of the light detected
 */
int getLightColor()
{
    double reading = CdSCell.Value();

    //If the light value is in the no light range
    if(reading >= lightThresholdNone - lightThresholdNoneTolerance && reading <= lightThresholdNone + lightThresholdNoneTolerance)
    {
        return CDS_LIGHT_NONE;
    }

    //If the light value is in the red light range
    else if(reading >= lightThresholdRed - lightThresholdRedTolerance && reading <= lightThresholdRed + lightThresholdRedTolerance)
    {
        return CDS_LIGHT_RED;
    }

    //If the light value is in the blue light range
    else if(reading >= lightThresholdBlue - lightThresholdBlueTolerance && reading <= lightThresholdBlue + lightThresholdBlueTolerance)
    {
        return CDS_LIGHT_BLUE;
    }

    //If the light value is not in either
    else
    {
        return -1;
    }
}




// Analog Optosensors

/*
 * Sets the threshold for various colors of line
 */
void setOptosensorThreshold()
{
    /*
     * INSERT CODE HERE
     */
}
