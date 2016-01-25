/**************************************************************************/
/*! 
  @file     ErrorManager.cpp
  @author   CNC LAB (Rami Nassouh for CNC LAB)
  @license  GPLv3 (see license.txt) 

  This library provides a simple error management class suitable for all UI applications.
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

#include "ErrorManager.h"

/**
 *  \function ErrorManager::ErrorManager
 *  \brief default constructor
 *  
 *  \return Return_Description
 *  
 *  \details Details
 */
ErrorManager::ErrorManager(){}

/**
 *  \function ErrorManager::init
 *  \brief Brief
 *  
 *  \return Return_Description
 *  
 *  \details Details
 */
void ErrorManager::init(int length)
{
	_error_code = -1;
	_errorsLength = length;
	_error_list = (bool*) malloc(_errorsLength);
	for(int i = 0; i < _errorsLength; i++)
		_error_list[i] = false;
}

/**
 *  \function ErrorManager::setError
 *  \brief Brief
 *  
 *  \param [in] idx Parameter_Description
 *  \return Return_Description
 *  
 *  \details Details
 */
void ErrorManager::setError(byte idx)
{
	idx = checkIndex(idx);
	if(!_error_list[idx])
	{
		_error_list[idx] = true;
		updateErrorCode();
	}
}

/**
 *  \function ErrorManager::setError
 *  \brief Brief
 *  
 *  \param [in] idx Parameter_Description
 *  \param [in] s Parameter_Description
 *  \return Return_Description
 *  
 *  \details Details
 */
void ErrorManager::setError(byte idx, bool s)
{
	idx = checkIndex(idx);
	if(_error_list[idx] != s)
	{
		_error_list[idx] = s;
		updateErrorCode();
	}
}

/**
 *  \function ErrorManager::clearError
 *  \brief Brief
 *  
 *  \param [in] idx Parameter_Description
 *  \return Return_Description
 *  
 *  \details Details
 */
void ErrorManager::clearError(byte idx)
{
	idx = checkIndex(idx);
	if(_error_list[idx])
	{
		_error_list[idx] = false;
		updateErrorCode();
	}
}

/**
 *  \function ErrorManager::getError
 *  \brief Brief
 *  
 *  \param [in] idx Parameter_Description
 *  \return Return_Description
 *  
 *  \details Details
 */
bool ErrorManager::getError(byte idx)
{
	idx = checkIndex(idx);	
	return _error_list[idx];
}

/**
 *  \function ErrorManager::getErrorCode
 *  \brief Brief
 *  
 *  \return Return_Description
 *  
 *  \details Details
 */
int ErrorManager::getErrorCode()
{
	return _error_code;
}

/**
 *  \function ErrorManager::updateErrorCode
 *  \brief Brief
 *  
 *  \return Return_Description
 *  
 *  \details Details
 */
void ErrorManager::updateErrorCode()
{
	_error_code = -1;
	for(int i = 0; i < _errorsLength; i++)
	{
		if(_error_list[i])
		{
			_error_code = i;
			break;
		}
	}
}

/**
 *  \brief Checks and controls the error index
 *  
 *  \param [in] idx index of error
 *  \return checked and controlled index
 *  
 *  \details Details
 */
int ErrorManager::checkIndex(int idx)
{
	if(idx < 0)
		idx = 0;
	else if(idx >= _errorsLength)
		idx = _errorsLength-1;
	return idx;
}

/**
 *  \function ErrorManager::clearAll
 *  \brief clears all errors
 *  
 *  \return Return_Description
 *  
 *  \details Details
 */
void ErrorManager::clearAll()
{
	_error_code = -1;
	for(int i = 0; i < _errorsLength; i++)
		_error_list[i] = false;
}
