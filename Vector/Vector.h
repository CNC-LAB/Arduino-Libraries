/**************************************************************************/
/*! 
  @file     Vector.h
  @author   CNC LAB (Rami Nassouh for CNC LAB)
  @license  GPLv3 (see license.txt) 

  This library provides a Vector class for easier byte array manipulation and passing to other functions as input parameter
  ----> https://www.cnclablb.com
  
  
  CNC LAB invests time and resources providing this open source code, 
  please support CNC LAB and open-source hardware by purchasing 
  products from CNC LAB! 
*/
/**************************************************************************/

#ifndef Vector_h
#define Vector_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#elif defined(WIRING)
#include "Wiring.h"
#else
#include "WProgram.h"
#include "pins_arduino.h"
#endif

class Vector
{
	public:
		Vector(byte * ptr, int l);
		Vector(int l);
		Vector(const Vector& v);
		Vector();		
		void init(int l);
		void Clear();
		void Clone(const Vector& v);
		byte * buffer;
		int length;
		byte tag;
};

#endif