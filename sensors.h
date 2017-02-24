#ifndef SENSORS_H
#define SENSORS_H

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

//Bump Switches
bool isPressed(DigitalInputPin bump);
bool IsFrontPressed();
bool isBackPressed();

//CdS Cell
void setCdSThreshold();
void DisplayCdSCell();
int getLightColor();

//Analog Optosensors
void setOptosensorThreshold();



#endif // SENSORS_H
