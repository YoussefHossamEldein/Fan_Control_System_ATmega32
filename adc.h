/*============================================================================
*
* Module      : ADC
*
* File Name   : adc.h
*
* Description : header file for the ATmega16 ADC driver
*
* Author      : Youssef Hossam
*===============================================================================
*
*/

#ifndef ADC_H_
#define ADC_H_
/**************************** Includes Section *******************/
#include "std_types.h"
/**************************** Data Types Section *****************/
typedef enum{
	AREF,
	AVCC,
	RESRVED,
	INTERNAL,
}ADC_ReferenceVoltage;
typedef enum {
	F_CPU_2 = 1,
	F_CPU_4,
	F_CPU_8,
	F_CPU_16,
	F_CPU_32,
	F_CPU_64,
	F_CPU_128
}ADC_Prescaler;
	typedef struct {
		ADC_ReferenceVoltage ref_volt;
		ADC_Prescaler prescaler;
	}ADC_ConfigType;
/************************ Global Variables Section *****************/
	extern float ADC_REF_VOLT_VALUE ;
/**************************** Macro Definitions Section **********/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_AREF 5
#define ADC_AVCC 5
#define ADC_INTERNAL 2.56


/*
*  ===========================================================================================
* 	@brief  : Function that initialize ADC
* 	@param  : function takes pointer of type ADC_ConfigType
* 	@retVal : function returns nothing
* 	===========================================================================================
*/
void ADC_init( const ADC_ConfigType *Config_Ptr);

/*
*  ===========================================================================================
* 	@brief  : Function that reads data from analog adc input channel and convert it do digital
* 	@param  : function takes the adc channel number
* 	@retVal : function returns the digital conversion of the analog data
* 	===========================================================================================
*/
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
