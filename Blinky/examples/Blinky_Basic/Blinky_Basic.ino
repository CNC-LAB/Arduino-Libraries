/**
 *  \file Blinky_Basic.ino
 *  \brief 
 *  This example shows how to use Blinky to blink LED at a certain frequency
 */

#include <Blinky\Blinky.h>

Blinky myLED;

void setup() 
{
	myLED.init(13);
	myLED.setInterval(100);
	myLED.start();
}

void loop()
{
	int aval = analogRead(A0);

	if (aval < 255)
		myLED.setInterval(250);
	else if (aval < 512)
		myLED.setInterval(500);
	else
		myLED.setInterval(1000);

	myLED.update();
}