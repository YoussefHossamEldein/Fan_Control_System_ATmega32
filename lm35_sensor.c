 /*==============================================================================
 *
 * Module      : Temperature Sensor
 *
 * File Name   : lm35_sensor.h
 *
 * Description : source file for the LM35 Temperature Sensor driver
 *
 * Author      : Youssef Hossam
 *
 *==================================================================================
 */


/************************* Includes Section ********************************/
#include "lm35_sensor.h"

#include "adc.h"
/************************** Functions Definition Section *******************/
/*
 * ===========================================================================================
 * 	@brief  : Function that get the analog temperature value and turns it to digital using ADC
 * 	@param  : function takes the required duty cycle
 * 	@retVal : function returns nothing
 * 	===========================================================================================
 */
uint8 LM35_getTemperature(void)
{
	/* Configure ADC Prescaler and reference voltage */
		ADC_ConfigType fan_control_adc = {
				.ref_volt = INTERNAL,
				.prescaler = F_CPU_8,
		};


		ADC_init(&fan_control_adc); /* Start the ADC */

	uint8 temp_value = 0;

	uint16 adc_value = 0;

	/* Read ADC channel where the temperature sensor is connected */
	adc_value = ADC_readChannel(SENSOR_CHANNEL_ID);

	/* Calculate the temperature from the ADC value*/
	temp_value = (uint8)(((uint32)adc_value*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

	return temp_value;
}

