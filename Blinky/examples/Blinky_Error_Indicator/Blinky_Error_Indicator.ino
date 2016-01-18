/**
 *  \file Blinky_Error_Indicator.ino
 *  \brief 
 *  This example shows how to use the Blinky library to indicate an error code
 */
 
#include <Blinky\Blinky.h>

Blinky myLED;

void setup() 
{
	myLED.init(13);				// Attache to Digital pin 13
	myLED.setInterval(4000);	// Set interval to 4 sec
	myLED.setCountMode(true);	// Set as Count Mode
    myLED.setCount(0); 			// No Errors
    myLED.start(); 				// Activate blinky
}

void loop() 
{
	int aval = analogRead(A0);
	
	if (aval > 800)
		myLED.setCount(1);
	else if (aval < 200)
		myLED.setCount(2);
	else
		myLED.setCount(0);
	
	myLED.update();
}