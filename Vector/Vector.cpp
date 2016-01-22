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

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#elif defined(WIRING)
#include "Wiring.h"
#else
#include "WProgram.h"
#include "pins_arduino.h"
#endif

#include "Vector.h"

/**
 *  \function Vector::Vector
 *  \brief Contructor from byte array
 *  
 *  \param [in] ptr byte array
 *  \param [in] l length of array
 *  \return Return_Description
 *  
 *  \details Details
 */
Vector::Vector(byte * ptr, int l)
{	
	length = l;
	tag = 0;
	buffer = (byte*) malloc(length);
	for(int i = 0; i < length; i++)
		buffer[i] = *(ptr+i);
}

/**
 *  \brief Constructor from length
 *  
 *  \param [in] l vector length
 *  \return Return_Description
 *  
 *  \details Details
 */
Vector::Vector(int l)
{	
	length = l;
	tag = 0;
	if(l > 0)
	{
		buffer = (byte*) malloc(length);
		for(int i = 0; i < length; i++)
			buffer[i] = 0;
	}
	else
	{
		buffer = (byte*) malloc(2);
		for(int i = 0; i < 2; i++)
			buffer[i] = 0;
		tag = 1;
	}
}

/**
 *  \brief Constructor from other vector instance
 *  
 *  \param [in] v Vector instance to clone
 *  \return Return_Description
 *  
 *  \details Details
 */
Vector::Vector(const Vector& v)
{	
	length = v.length;
	tag = v.tag;
	if(length > 0)
	{
		buffer = (byte*) malloc(length);
		for(int i = 0; i < length; i++)
			buffer[i] = v.buffer[i];
	}
	else
	{
		buffer = (byte*) malloc(2);
		for(int i = 0; i < 2; i++)
			buffer[i] = 0;
		tag = 1;
	}
}

/**
 *  \brief Default Constructor
 *  
 *  \return Return_Description
 *  
 *  \details Details
 */
Vector::Vector(){}

/**
 *  \brief Initialize Vector instance
 *  
 *  \param [in] l length
 *  \return Return_Description
 *  
 *  \details This method should be used in case of the need to reset the Vector instance or in case of the default constructor being used
 */
void Vector::init(int l)
{	
	length = l;
	tag = 0;
	buffer = (byte*) malloc(length);
	for(int i = 0; i < length; i++)
		buffer[i] = 0;
	return;
}

/**
 *  \brief Clear (Zero-out) Vector content
 *  
 *  \return Return_Description
 *  
 *  \details Details
 */
void Vector::Clear()
{
	for(int i = 0; i < length; i++)
		buffer[i] = 0;
	return;
}

/**
 *  \brief Clone the Vector instance
 *  
 *  \param [in] v Instance to clone
 *  \return New Vector instance
 *  
 *  \details Details
 */
void Vector::Clone(const Vector& v)
{	
	if(length == v.length)
	{
		length = v.length;
		tag = v.tag;
		for(int i = 0; i < length; i++)
			buffer[i] = v.buffer[i];
	}
}
