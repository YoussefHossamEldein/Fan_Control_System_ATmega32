 /*============================================================================
 *
 * Module      : Temperature Sensor
 *
 * File Name   : lm35_sensor.h
 *
 * Description : header file for the LM35 Temperature Sensor driver
 *
 * Author      : Youssef Hossam
 *
 *=============================================================================
 */

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_
/************************ Includes Section ****************************/
#include "std_types.h"
/************************ Data Types Section **************************/


/************************ Macro Definition Section ********************/
#define SENSOR_CHANNEL_ID         2
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150
/************************ Macro Functions Section *********************/



/************************ Functions Declaration Section ***************/



/*
 * ===========================================================================================
 * 	@brief  : Function that get the analog temperature value and turns it to digital using ADC
 * 	@param  : function takes the required duty cycle
 * 	@retVal : function returns nothing
 * 	===========================================================================================
 */
uint8 LM35_getTemperature(void);

#endif /* LM35_SENSOR_H_ */
