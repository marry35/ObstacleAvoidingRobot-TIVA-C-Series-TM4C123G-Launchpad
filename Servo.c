#include "servo.h"
#include "lcd.h"

void Timer1A_Init(void)
	
{


 RCGC_GPIO_R |= CLOCK_GPIOF; //Enabling the clock to PortF Module
 RCGC_TIMER_R |= 0x02; //Enabling clock to Timer Module 1
 
 GPIO_PORTF_AFSEL_R |= 0x00000004; //Alternate functionality for PF2 GPIO Pin
 GPIO_PORTF_PCTL_R |=  0x00000700; //Timer2 Capture Compare mode Alternate functionality
 GPIO_PORTF_DEN_R |=   0x00000004; //Digital Enable
	
 GPTM_CONTROL_PWM_R &= ~(TIM_A_ENABLE); //Disable the Timer
 GPTM_CONFIG_PWM_R |= TIM_16_BIT_CONFIG; //Timer as 16 Bit Basic Timer
	
 GPTM_TA_MODE_PWM_R |= TIM_PWM_MODE; //Timer is configured in PWM mode
 GPTM_TA_MODE_PWM_R &= ~(TIM_CAPTURE_PWM_MODE); 
	
 GPTM_TA_IL_PWM_R = TIM_A_INTERVAL_PWM; //Providing the Load values for 250Hz Frequency
 GPTM_TA_MATCH_PWM_R = TIM_A_MATCH ; //Match value for 50% duty cycle initially
 
 //GPTM_TA_PRESCALE_R = 4;
 //GPTM_TA_PRESCALE_MATCH_R   = 1;
	
	GPTM_CONTROL_PWM_R |= TIM_A_ENABLE; //Enabling the Timer

	
}

//Function for putting Servo in Neutral position by changing PWM duty cycle
void servoNeutral( void)
{
 GPTM_TA_MATCH_PWM_R = 48000;

}

//Function for putting Servo in Left position by changing PWM duty cycle
void servoLeft( void)
{
 GPTM_TA_MATCH_PWM_R = 34000;

}

//Function for putting Servo in Right position by changing PWM duty cycle
void servoRight( void)
{
 GPTM_TA_MATCH_PWM_R = 58000;

}


void servoConfig(void)
{
	
Timer1A_Init();

}

