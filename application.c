/* ============================================================
 * File Name    : application.c
 *
 *
 * Description  : Fan Control System Application
 *
 *  Author      : Youssef Hossam
 *
 * ============================================================
 */
/****************************** Includes Section ************************/
#include "LCD.h"
#include "lm35_sensor.h"
#include "dc_motor.h"
/**************************** Macro Definition Section *******************/
#define FAN_QUARTER_SPEED 25
#define FAN_HALF_SPEED    50
#define FAN_MOST_OF_SPEED 75
#define FAN_FULL_SPEED   100

/************************** Main function of application *******************/
void main(){
		uint8 temperature;



		LCD_init(); /* Start the LCD */


		DcMotor_Init(); /* Start the DC Motor */


		LCD_displayStringRowColumn(1,4,"Temp =    C");


	while(1){
		temperature = LM35_getTemperature(); /*  read the temperature from the sensor */
		 /* if temperature is less than 30 turn off the fan */
		 	if(temperature < 30)
		 		{
		 			LCD_displayStringRowColumn(0,4,"Fan is OFF");

		 			LCD_moveCursor(1,11);

		 			if(temperature >= 10)
		 				{
		 					LCD_intgerToString(temperature);
		 				}
		 			else
		 				{
		 				 	LCD_intgerToString(temperature);

		 					/* In case the digital value is two or one digits print space in the next digit place */
		 					LCD_displayCharacter(' ');


		 				}
		 			DcMotor_Rotate(MotorStop,0);

		 		}
		 	else
		 		{
		 			LCD_moveCursor(0,4);
		 			LCD_displayString("Fan is ON ");

		 			if(temperature >= 30 && temperature < 60){
		 				DcMotor_Rotate(ClockWise,FAN_QUARTER_SPEED);
		 			}
		 			else if (temperature >= 60 && temperature < 90){
		 				DcMotor_Rotate(ClockWise,FAN_HALF_SPEED);
		 			}
		 			else if (temperature >= 90 && temperature < 120){
		 				DcMotor_Rotate(ClockWise,FAN_MOST_OF_SPEED);
		 			}
		 			else{
		 				DcMotor_Rotate(ClockWise,FAN_FULL_SPEED);
		 			}
		 			LCD_moveCursor(1,11);
		 			if(temperature >= 100)
		 			{
		 				LCD_intgerToString(temperature);
		 			}
		 			else
		 			{
		 				LCD_intgerToString(temperature);
		 				/* In case the digital value is two or one digits print space in the next digit place */
		 				LCD_displayCharacter(' ');
		 			}

		 		}
	}
}




