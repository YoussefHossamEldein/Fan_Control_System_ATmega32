 /*=============================================================================
 *
 * Module      : ADC
 *
 * File Name   : adc.c
 *
 * Description : source file for the ATmega16 ADC driver
 *
 * Author      : Youssef Hossam
 *===============================================================================
 *
 */
/*************************** Includes Section *******************/
#include "avr/io.h" /* To use the ADC Registers */
#include "adc.h"
#include "common_macros.h" /* To use the macros like SET_BIT */
/************************ Global Declaration Section ************/
float ADC_REF_VOLT_VALUE ;
/*************************** Functions Definition Section **************/
/*
*  ===========================================================================================
* 	@brief  : Function that initialize ADC
* 	@param  : function takes pointer of type ADC_ConfigType
* 	@retVal : function returns nothing
* 	===========================================================================================
*/
void ADC_init(const ADC_ConfigType *Config_Ptr)
{
		switch(Config_Ptr->ref_volt){
		case AREF:
			ADC_REF_VOLT_VALUE = ADC_AREF;
			break;

		case AVCC:
			ADC_REF_VOLT_VALUE = ADC_AVCC;
			break;
		case INTERNAL:
			ADC_REF_VOLT_VALUE = ADC_INTERNAL;
			break;
		}
	/* ADMUX Register Bits Description:
	 * REFS1 & REFS0: V-Reference selection (bits6,7)
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */
	ADMUX = ( (ADMUX & 0x3f) | ( ( (Config_Ptr->ref_volt) & 0x03)<<6) );
	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADIE    = 0 Disable ADC Interrupt
	 * ADATE   = 0 Disable Auto Trigger
	 * ADPS2:0 = to choose ADC_Clock ADC must operate in range 50-200Khz
	 */

	ADCSRA =(1<<ADEN);
	ADCSRA |=  (  (ADCSRA&0xF8) | ( (Config_Ptr->prescaler) & 0x07)  );
}
/*
*  ===========================================================================================
* 	@brief  : Function that reads data from analog adc input channel and convert it do digital
* 	@param  : function takes the adc channel number
* 	@retVal : function returns the digital conversion of the analog data
* 	===========================================================================================
*/
uint16 ADC_readChannel(uint8 channel_num)
{
	channel_num &= 0x07; /* Input channel number must be from 0 --> 7 */
	ADMUX &= 0xE0; /* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX = ADMUX | channel_num; /* Choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA,ADSC); /* Start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF); /* Clear ADIF by write '1' to it :) */
	return ADC; /* Read the digital value from the data register */
}
