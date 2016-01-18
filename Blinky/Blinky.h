/**************************************************************************/
/*! 
  @file     Blinky.h
  @author   CNC LAB (Rami Nassouh for CNC LAB)
  @license  BSD (see license.txt) 

  This is a library provides easy blinking LED management suitable for error codes and user interfacing purposes
  ----> https://www.cnclablb.com
  
  
  CNC LAB invests time and resources providing this open source code, 
  please support CNC LAB and open-source hardware by purchasing 
  products from CNC LAB! 
*/
/**************************************************************************/

#ifndef Blinky_h
#define Blinky_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#elif defined(WIRING)
#include "Wiring.h"
#else
#include "WProgram.h"
#include "pins_arduino.h"
#endif

class Blinky
{
  public:
    Blinky();
	void init(byte ledPin);
	void setCountMode(bool isCountMode);
	void setAnalogMode(bool isAnMode);
	void setCount(byte beepCount);
	void setInterval(long interval);
	bool getState();
	void stop();
	void start();
	bool isActive();
	void forceToggle();
	void forceON();
	void forceOFF();
	void setAnalogValue(int val);
	void update();
	void isFlipped(bool f);
	
  private:
	void output();
	
	bool _isFlipped;
	byte _led_pin;
	long _interval;
	byte _beepCount;
	byte _tempBeepCount;
	long _beepOnTime;
	long _pm;
	long _CountModePM;
	bool _isActive;
	bool _status;
	bool _isCountMode;
	bool _isAnalog;
	int _anval;
};

#endif