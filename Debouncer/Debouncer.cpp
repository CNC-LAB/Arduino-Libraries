/**************************************************************************/
/*! 
  @file     Debouncer.cpp
  @author   CNC LAB (Rami Nassouh for CNC LAB)
  @license  BSD (see license.txt) 

  This library provides a simple debouncing routine suitable for any boolean value debouncing purposes without delay
  ----> https://www.cnclablb.com
  
  
  CNC LAB invests time and resources providing this open source code, 
  please support CNC LAB and open-source hardware by purchasing 
  products from CNC LAB! 
*/
/**************************************************************************/

#include "Debouncer.h"

/**
 *  \brief Constructor
 *  
 *  \param [in] interval debouncing delay
 *  \return Return_Description
 *  
 *  \details Details
 */
Debouncer::Debouncer(long interval)
{	
	timeout_interval = interval;
	pm = millis();
	previous_value = false;
}

/**
 *  \brief updates the current state and returns debounced state
 *  
 *  \param [in] currentValue current state
 *  \return Return_Description debounced state
 *  
 *  \details Details
 */
bool Debouncer::debounce(bool currentValue)
{	
	if(currentValue == previous_value)
		pm = millis();
	
	if(millis() - pm >= timeout_interval)
	{
		previous_value = currentValue;
		pm = millis();
	}
		
	return previous_value;
}
