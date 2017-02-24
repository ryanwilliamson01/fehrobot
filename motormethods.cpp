/*
 *  - OFFICIAL MINECRAFT ROBOT TEAM -
 *
 *  Group C6
 *  Joe Forsman / Carson McCasland / Bailey Mulhern / Ryan Williamson
 *
 *  Motor Methods
 *  Version 1.0
 *  2/21/17 12:57PM
 *
 */

#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHServo.h>

#include "motormethods.h"


//Defining Pins
#define SHAFT_ENCODER_LEFT FEHIO::P0_1 //FEHIO::P0_0 INSERT SHAFT ENCODER PINS
#define SHAFT_ENCODER_RIGHT FEHIO::P0_0//INSERT SHAFT ENCODER PINS
#define COUNTS_AN_INCH 33.74084799;
#define DRIVE_MOTOR_LEFT FEHMotor::Motor0
#define DRIVE_MOTOR_RIGHT FEHMotor::Motor1
#define SERVO_MOTOR FEHServo::Servo0 //FEHServo::Servo0 INSERT SERVO PINS

//Declaring Shaft Encoders
DigitalEncoder shaftEncoderLeft(SHAFT_ENCODER_LEFT);
DigitalEncoder shaftEncoderRight(SHAFT_ENCODER_RIGHT);
//Declaring Drive Motors
FEHMotor driveMotorLeft (DRIVE_MOTOR_LEFT, 12.0);
FEHMotor driveMotorRight (DRIVE_MOTOR_RIGHT, 12.0);
//Declaring Servo Motors
FEHServo servoMotor(SERVO_MOTOR);



void printCounts(int motor_percent,int expected_counts){

        LCD.Clear();
        LCD.Write("Theoretical Counts: ");
        LCD.WriteLine(expected_counts);
        LCD.Write("Motor Percent: ");
        LCD.WriteLine(motor_percent);
        LCD.Write("Actual LE Counts: ");
        LCD.WriteLine(shaftEncoderLeft.Counts());
        LCD.Write("Actual RE Counts: ");
        LCD.WriteLine(shaftEncoderRight.Counts());
}

void stop(){
    driveMotorLeft.Stop();
    driveMotorRight.Stop();
}

/*
 *Drives backward a specified amount in inches
 */
void DriveForward(int percent, double inch){

    //Calculate the number of counts do go a specified number of inches
    int counts = inch*COUNTS_AN_INCH;
    //Reset encoder counts
     shaftEncoderRight.ResetCounts();
     shaftEncoderLeft.ResetCounts();

     //Set both motors to desired percent
     driveMotorRight.SetPercent(percent);
     driveMotorLeft.SetPercent(percent);

     //While the average of the left and right encoder is less than counts,
     //keep running motors

     while((shaftEncoderRight.Counts() + shaftEncoderLeft.Counts()) / 2. < counts){

     }

     //Turn off motors
     driveMotorRight.Stop();
     driveMotorLeft.Stop();

     //Tell us how accurate we are
     printCounts(percent, counts);
}

/*
 * Drives backward infinitely
 */
void DriveBackward(int percent)
{
    driveMotorRight.SetPercent(-1*percent);
    driveMotorLeft.SetPercent(-1*percent);
}

/*
 *Drives backward a specified amount in inches
 */
void DriveBackward(int percent, double inch){

    //Calculate the number of counts do go a specified number of inches
    int counts = inch*COUNTS_AN_INCH;
    //Reset encoder counts
     shaftEncoderRight.ResetCounts();
     shaftEncoderLeft.ResetCounts();

     //Set both motors to desired percent
     driveMotorRight.SetPercent(-1*percent);
     driveMotorLeft.SetPercent(-1*percent);

     //While the average of the left and right encoder is less than counts,
     //keep running motors

     while((shaftEncoderRight.Counts() + shaftEncoderLeft.Counts()) / 2. < counts){

     }

     //Turn off motors
     driveMotorRight.Stop();
     driveMotorLeft.Stop();

     //Tell us how accurate we are
     printCounts(percent, counts);
}

/*
 *Drives forward until the front bump switches are pressed
 */
void DriveForwardUntilPressed(int percent){



}

/*
 *Drives backward until the back bump switches are pressed
 */
void DriveBackwardUntilPressed(int percent){

    //Calculate the number of counts do go a specified number of inches
//    int counts = inch*COUNTS_AN_INCH;
//    //Reset encoder counts
//    shaftEncoderRight.ResetCounts();
//    shaftEncoderRight.ResetCounts();

//    //Set both motors to desired percent
//    driveMotorRight.SetPercent(percent);
//    driveMotorLeft.SetPercent(-percent);

//    //While the average of the left and right encoder is less than counts,
//    //keep running motors
//    while((shaftEncoderRight.Counts() + shaftEncoderRight.Counts()) / 2. < counts);

//    //Turn off motors
//    driveMotorRight.Stop();
//    driveMotorLeft.Stop();

//    //Tell us how accurate we are
//    printCounts(percent, counts);
}

void turnRight(int percent){

    //Set both motors to desired percent
    driveMotorRight.SetPercent(-percent);
    driveMotorLeft.SetPercent(percent);


}
void turnRight(int percent, double inch){

    //Calculate the number of counts do go a specified number of inches
    int counts = inch*COUNTS_AN_INCH;
    //Reset encoder counts
    shaftEncoderRight.ResetCounts();
    shaftEncoderLeft.ResetCounts();

    //Set both motors to desired percent
    driveMotorRight.SetPercent(-percent);
    driveMotorLeft.SetPercent(percent);

    //While the average of the left and right encoder is less than counts,
    //keep running motors
    while((shaftEncoderRight.Counts() + shaftEncoderLeft.Counts()) / 2.0 < counts){

    }
    //Turn off motors
    driveMotorRight.Stop();
    driveMotorLeft.Stop();

    //Tell us how accurate we are
    printCounts(percent, counts);
}


void turnLeft(int percent){

    //Set both motors to desired percent
    driveMotorRight.SetPercent(percent);
    driveMotorLeft.SetPercent(-percent);

}

void turnLeft(int percent, double inch){

    //Calculate the number of counts do go a specified number of inches
    int counts = inch*COUNTS_AN_INCH;
    //Reset encoder counts
    shaftEncoderLeft.ResetCounts();
    shaftEncoderRight.ResetCounts();

    //Set both motors to desired percent
    driveMotorRight.SetPercent(percent);
    driveMotorLeft.SetPercent(-percent);

    //While the average of the left and right encoder is less than counts,
    //keep running motors
    while((shaftEncoderRight.Counts() + shaftEncoderLeft.Counts()) / 2.0 < counts){

    }
    //Turn off motors
    driveMotorRight.Stop();
    driveMotorLeft.Stop();

    //Tell us how accurate we are
    printCounts(percent, counts);
}

