/**
 *  \file ErrorManager_Basic.ino
 *  \brief 
 *  This example shows how to use ErrorManager library to manipulate create a simple user interface
 */

#include <ErrorManager.h>

ErrorManager er_manager;

void setup() 
{
	Serial.begin(9600);
	
	er_manager.init(3);	//initialize the manager to include 3 error codes
}

void loop()
{
	int anval = analogRead(A0);
	
	if(anval < 50)
		er_manager.setError(0);
	else if(anval < 200)
	{
		er_manager.clearError(0);
		er_manager.setError(1);
	}
	else if(anval > 900)
		er_manager.setError(2);
	else
		er_manager.clearAll();
	
	//Simple way to demonstrate error code usage
	//It can also be used with our Blinky library to...
	//	make an LED blink N times per period based on the error code value
	switch(er_manager.getErrorCode())
	{
		case -1:	//No errors
			Serial.print("Sensor Value: ");
			Serial.println(anval);
			break;
		case 0:	//Highest priority error code 0
			Serial.println("Error Code 0: Sensor Disconnected");
			break;
		case 1:	//error code 1
			Serial.println("Error Code 1: Sensor value is low");
			break;
		case 2:	//error code 2
			Serial.println("Error Code 2: Sensor value is high");
			break;
	}
	
	delay(50);
}