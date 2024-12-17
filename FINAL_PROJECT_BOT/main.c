/*
 * @file main.c
 *
 * @brief Main source code for the PWM program.
 *
 * This file contains the main entry point and function definitions for the PWM program.
 * This lab demonstrates how to generate PWM signals using the two PWM modules: M0PWM and M1PWM.
 *
 * It interfaces with the following:
 *  - User LED (RGB) Tiva C Series TM4C123G LaunchPad
 *	- PMOD BTN module
 *	-	LN298N Motor Driver
 *
 * It configures the pins used by the PMOD BTN module to generate interrupts on rising edges.
 * The PMOD BTN module will be used to update the duty cycle value for the HS-485HB Servo.
 * 
 * In addition, Timer 0A is used to generate periodic interrupts every 1 ms. It will
 * update the duty cycle for the RGB LED (specifically PF2) every 5 ms to demonstrate
 * a fading LED effect.
 *
 * @author JONATHAN G ,JONATHAN P
 


 */

#include "TM4C123GH6PM.h"
#include "SysTick_Delay.h"
#include "PWM_Clock.h"
#include "PWM1_3.h"

#include "PWM0_0.h"
#include "Timer_0A_Interrupt.h"
#include "PMOD_BTN_Interrupt.h"
#include "GPIO.h"

// Declare the user-defined function prototype for Timer 0A
void Timer_0A_Periodic_Task (void) ;

// Declare the user-defined function prototype for PMOD_BTN_Interrupt
void PMOD_BTN_Handler (uint8_t pmod_btn_status) ;
// Declare the user defined functions for motor control
void Motor_Forward_R();
void Motor_Reverse_R();
void Motor_Reverse_L();
void Motor_Forward_L();

// Funtion to control the direction of the bot 
void direction(int state, int speed)
{
	if(state == 1) // forawrd
	{
		Motor_Forward_L();
		Motor_Forward_R();
	}
	else if(state == 2) //reverse 
	{
		Motor_Reverse_L();
		Motor_Reverse_R();
	}
	else if (state == 3) //turn left
	{
		Motor_Forward_R();
		Motor_Reverse_L();
	}
	else if (state == 4) // turn right
	{
		Motor_Forward_L();
		Motor_Reverse_R();
	}
	PWM0_0_Update_Duty_Cycle(speed); //PWM Signals for left and right sides take the speed input
	PWM1_3_Update_Duty_Cycle(speed);
		
}
int main(void)
{
	
	// Initialize the SysTick timer used to provide blocking delay functions
	SysTick_Delay_Init () ;
	// Initialize the motor control functions
//	Motor_Forward_R();
//	Motor_Reverse_R();
//	Motor_Reverse_L();
//	Motor_Forward_L();

// Initialize the PWM clock to use the PWM clock divisor as the source
// and update the PWM clock frequency to 50 MHz / 16 = 3.125 MHz
	PWM_Clock_Init();

// Initialize the Module 1 PWM Generator 3 (PWMI_3) to generate a PWM signal
// using the PF2 pin that has a frequency of 50 Hz with 5% duty cycle
// Period constant = ((50 MHz / 16) / 50 Hz) = 62500
// Duty cycle = (62500 * 0.05) = 3125
	PWM1_3_Init (62500, 12500) ; // Right Side PWM Control 
	
// Initialize the Module 0 PWM Generator 0 Block (PWMO 0) to generate a PWM signal
// using the PB6 pin that has a frequency of 50 Hz with 20% duty cycle
// Period constant = ((50 MHz / 16) / 50 Hz) = 62500
// Duty cycle = (62500 * 0.05) = 3125
	PWM0_0_Init (62500, 12500) ; // Left Side PWM Control 

// Initialize the push buttons on the PMOD BTN module (Port A)
	PMOD_BTN_Interrupt_Init (&PMOD_BTN_Handler) ;

// Initialize Timer AO to generate periodic interrupts every 1 ms
//Timer_0A_Interrupt_Init (&Timer_0A_Periodic_Task) ;
	
	
	while(1)
	{						
	}
}
 

void PMOD_BTN_Handler (uint8_t pmod_btn_status)
{
	switch(pmod_btn_status)
	{
	// BTNO (PA2)
		// make the bot incramentally go forward from 0-Max Speed
		case 0x04:
		{
			SysTick_Delay1ms(2000);
		for (int i = 0; i < 62500; i++)
		{
			direction(1, i);
		SysTick_Delay1us(100);
			if (i == 62499)
			{
				SysTick_Delay1ms(500);
				direction(1, 0);
			}
		}
		
			break;
		}
		
		// BIN1 (PA3)
		// Make the bot incramentally slow down from Max Speed - 0
		case 0x08:
		{	
		SysTick_Delay1ms(2000);
		for (int i = 62500; i >= 0; i--)
		{
			direction(2, i);
		SysTick_Delay1us(100);
		
		}
			break;
		}
		
		// BTN2 (PA4)
		// Make bot do a square pattern
		case 0x10:
		{
			SysTick_Delay1ms(2000);

		for (int count = 0; count < 3; count++)
			{
				direction(1, 62499);
				SysTick_Delay1ms(1000);
				direction(1, 0);
				
				direction(3, 62499);
				SysTick_Delay1ms(500);
				direction(3, 0);
				
			}
			PWM0_0_Update_Duty_Cycle(0);
			PWM1_3_Update_Duty_Cycle(0);
			
	
			break;
		
		}
		
		// BTN3 (PA5)
		// Make bot do a circle pattern 
		case 0x20:
		{
			SysTick_Delay1ms(2000);
			
			direction(3, 62499);
			SysTick_Delay1ms(3000);
			direction(3, 0);
			direction(1, 40000);
			SysTick_Delay1ms(1000);
			direction(1, 0);
			direction(2, 40000);
			SysTick_Delay1ms(1000);
			direction(2, 0);
			
			direction(4, 62499);
			SysTick_Delay1ms(3000);
			direction(4, 0);
			direction(2, 40000);
			SysTick_Delay1ms(1000);
			direction(2, 0);
			direction(1, 40000);
			SysTick_Delay1ms(1000);
			direction(1, 0);
			
			break;
			
		}
		default:
		{
			direction(1, 0);
			break;
		}
	}
}