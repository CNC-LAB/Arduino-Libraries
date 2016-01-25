/**************************************************************************/
/*! 
  @file     ErrorManager.h
  @author   CNC LAB (Rami Nassouh for CNC LAB)
  @license  GPLv3 (see license.txt) 

  This library provides a simple error management class suitable for all UI applications.
  ----> https://www.cnclablb.com
  
  
  CNC LAB invests time and resources providing this open source code, 
  please support CNC LAB and open-source hardware by purchasing 
  products from CNC LAB! 
*/
/**************************************************************************/

#ifndef ErrorManager_h
#define ErrorManager_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#elif defined(WIRING)
#include "Wiring.h"
#else
#include "WProgram.h"
#include "pins_arduino.h"
#endif

class ErrorManager
{
  public:
    ErrorManager();
	void init(int length);
	void setError(byte idx);
	bool getError(byte idx);
	void setError(byte idx, bool s);
	void clearError(byte idx);
	int getErrorCode();
	void clearAll();
	
  private:
	int _errorsLength;
	int _error_code;
	bool * _error_list;
	void updateErrorCode();
	int checkIndex(int idx);
};

#endif