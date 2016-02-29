/**************************************************************************/
/*! 
  @file     Debouncer.h
  @author   CNC LAB (Rami Nassouh for CNC LAB)
  @license  GPLv3 (see license.txt) 

  This library provides a simple debouncing routine suitable for any boolean value debouncing purposes
  ----> https://www.cnclablb.com
  
  
  CNC LAB invests time and resources providing this open source code, 
  please support CNC LAB and open-source hardware by purchasing 
  products from CNC LAB! 
*/
/**************************************************************************/

#ifndef Debouncer_h
#define Debouncer_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#elif defined(WIRING)
#include "Wiring.h"
#else
#include "WProgram.h"
#include "pins_arduino.h"
#endif

class Debouncer
{
  public:
    Debouncer(long interval);
	bool debounce(bool currentValue);
	
  private:
	long pm;
	long timeout_interval;
	bool previous_value;
};

#endif