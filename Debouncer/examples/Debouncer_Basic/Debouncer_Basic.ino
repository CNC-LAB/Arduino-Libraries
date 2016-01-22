/**
 *  \file Debouncer_Basic.ino
 *  \brief 
 *  This example shows how to use Debouncer library to debounce a button press and show it on an LED
 */

#include <Debouncer.h>

#define BUTTON_PIN 2
#define LED_PIN 13

Debouncer debouncedSignal(500);

void setup() 
{
	pinMode(BUTTON_PIN,INPUT_PULLUP);
	pinMode(LED_PIN,OUTPUT);
}

void loop()
{
	bool buttonStatus = debouncedSignal.debounce(digitalRead(BUTTON_PIN));
	digitalWrite(LED_PIN,buttonStatus);
}