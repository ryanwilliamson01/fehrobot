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

#ifndef MOTORMETHODS_H
#define MOTORMETHODS_H

#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHServo.h>



void DriveBackward(int percent);
void DriveBackward(int percent, double inch);

void DriveBackward(int percent);
void DriveBackward(int percent, double inch);

void DriveForwardUntilPressed(int percent);
void DriveBackwardUntilPressed(int percent);

void TokyoDrift(int percent);

void printCounts(int motor_percent,int expected_counts);

#endif
 // MOTORMETHODS_H
