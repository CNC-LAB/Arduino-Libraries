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

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#elif defined(WIRING)
#include "Wiring.h"
#else
#include "WProgram.h"
#include "pins_arduino.h"
#endif

#include "Blinky.h"

/**
 *  \brief Default Constructor
 *  
 *  \return Return_Description
 *  
 *  \details Details
 */
Blinky::Blinky() {}

/**
 *  \brief initialize the object
 *  
 *  \param [in] ledPin led pin number to attach to
 *  \return Return_Description
 *  
 *  \details Details
 */
void Blinky::init(byte ledPin)
{
	_led_pin = ledPin;
	_isActive = false;
	_isCountMode = false;
	_isAnalog = false;
	_anval = 0;
	_interval = 1000;
	_beepOnTime = 100;
	_isFlipped = false;
	_pm = 0;
	_status = false;
	pinMode(_led_pin, OUTPUT);
	output();
}

/**
 *  \brief Set count mode status
 *  
 *  \param [in] isCountMode count mode status
 *  \return Return_Description
 *  
 *  \details Details
 */
void Blinky::setCountMode(bool isCountMode)
{
	_isCountMode = isCountMode;
}

/**
 *  \brief set analog output mode status
 *  
 *  \param [in] isAnMode analog mode status
 *  \return Return_Description
 *  
 *  \details Details
 */
void Blinky::setAnalogMode(bool isAnMode)
{
	_isAnalog = isAnMode;
}

/**
 *  \brief set analog output value
 *  
 *  \param [in] anval analog value (0 - 255)
 *  \return Return_Description
 *  
 *  \details Details
 */
void Blinky::setAnalogValue(int anval)
{
	if(anval > 255)
		anval = 255;
	else if(anval < 0)
		anval = 0;
	_anval = anval;
}

/**
 *  \brief set count for count mode
 *  
 *  \param [in] beepCount number of beeps per interval (0 - 5)
 *  \return Return_Description
 *  
 *  \details Details
 */
void Blinky::setCount(byte beepCount)
{
	if(beepCount > 5)
		beepCount = 5;
	_beepCount = beepCount*2;
}

/**
 *  \brief set interval for blink and count modes
 *  
 *  \param [in] interval interval in ms
 *  \return Return_Description
 *  
 *  \details Details
 */
void Blinky::setInterval(long interval)
{
	if(interval <= 0)
		interval = 0;
	_interval = interval;
	_beepOnTime = _interval / 10;
}

/**
 *  \brief stop activity
 *  
 *  \return Return_Description
 *  
 *  \details Details
 */
void Blinky::stop()
{
	_isActive = false;
	_status = false;
}

/**
 *  \brief start activity
 *  
 *  \return Return_Description
 *  
 *  \details Details
 */
void Blinky::start()
{
	_isActive = true;
	_tempBeepCount = 0;
	_status = false;
	_pm = 0;
}

/**
 *  \brief force toggle output status
 *  
 *  \return Return_Description
 *  
 *  \details Details
 */
void Blinky::forceToggle()
{
	_isActive = false;
	_status = !_status;
}

/**
 *  \brief force output status ON
 *  
 *  \return Return_Description
 *  
 *  \details Details
 */
void Blinky::forceON()
{
	_isActive = false;
	_status = true;
}

/**
 *  \brief force output status off
 *  
 *  \return Return_Description
 *  
 *  \details Details
 */
void Blinky::forceOFF()
{
	_isActive = false;
	_status = false;
}

/**
 *  \brief Updates and manages the status
 *  
 *  \return Return_Description
 *  
 *  \details Details
 */
void Blinky::update()
{
	if(_isActive)
	{
		if(millis() - _pm >= _interval)
		{
			if(_isCountMode)
			{
				if(millis() - _CountModePM >= _beepOnTime)
				{
					_status = !_status;
					_tempBeepCount++;
					if(_tempBeepCount > _beepCount)
					{
						_status = false;
						_tempBeepCount = 0;
						_pm = millis();
					}
					_CountModePM = millis();
				}
			}
			else
			{
				_status = !_status;
				_pm = millis();
			}
		}
	}	
	
	output();	//refresh output
}

/**
 *  \brief get the current digital output status
 *  
 *  \return Return_Description
 *  
 *  \details Details
 */
bool Blinky::getState()
{
	return _status;
}

/**
 *  \brief set logic status
 *  
 *  \param [in] logic state Parameter_Description
 *  \return Return_Description
 *  
 *  \details Details
 */
void Blinky::isFlipped(bool f)
{
	_isFlipped = f;	//update current logic status
	output();		//refresh output
}

/**
 *  \brief Get current activity status
 *  
 *  \return bilinking status
 *  
 *  \details Details
 */
bool Blinky::isActive()
{
	return _isActive;	//return activity status
}

/**
 *  \brief Manages the digital output status
 *  
 *  \return Return_Description
 *  
 *  \details Details
 */
void Blinky::output()
{
	if(!_isAnalog || _isCountMode)	//if no pwm output
		digitalWrite(_led_pin,_status^_isFlipped);	//output digital status taking the logic state into account
	else
		analogWrite(_led_pin,_isFlipped? (255-_anval):_anval);	//output pwm cycle taking into consideration the logic state
}
	