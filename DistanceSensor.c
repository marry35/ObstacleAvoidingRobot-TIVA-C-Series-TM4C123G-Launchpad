#include "sensorDriver.h"
#include "lcd.h"
#include <stdio.h>
#include "distance_sensor.h"
#include "gpio.h"
int distance2 = 0;


void distanceSensorConfig(void)
{
	//Enabling clock to Timer and PortF
 RCGC_TIMER_R |= 0x04;
 SYSCTL_RCGCGPIO_R |= CLOCK_GPIOF + PORTE_CLK_EN;
	
	//Enabling PortE GPIO and module
 GPIO_PORTE_DEN_R |= TRIG_ECHO_PIN_EN;
 GPIO_PORTE_DIR_R |= TRIG_PINE2;
 GPIO_PORTE_DIR_R &=~ECHO_PINE1;
 GPIO_PORTE_PD_R  |= ECHO_PINE1;
	
//Enabling PortF PF4 pin with Input Capture mode
 GPIO_PORTF_DEN_R   |= 0x00000010;
 GPIO_PORTF_AFSEL_R |= 0x00000010;
 GPIO_PORTF_PCTL_R  |= 0x00070000;
	
  //Initialize the Timer Module for Input Capture
 Timer2A_Init();
	
	
	//Configuring systick timer for 50ms continous Trigger to the Sensor
 configureSystickTimer();
}


void Timer2A_Init(void)
{
 
	
 GPTM_CONFIG_R = TIM_16_BIT_CONFIG; //16Bit Timer
	
	//Timer mode is input Capture with count down
 GPTM_TA_MODE_R |= TIM_EDGE_TIME_MODE + TIM_CAPTURE_MODE; 
 GPTM_CONTROL_R |= TIM_A_EVENT_POS_EDGE;
	
 //providing the Interval and Prescale values
 GPTM_TA_IL_R = TIM_A_INTERVAL;
 GPTM_TA_PRESCALE_R = TIM_A_PRESCALE;
 
	//Timer0 A interrupt configuration
 GPTM_INT_MASK_R |= TIM_A_CAP_EVENT_IM;
 NVIC_EN0_R = NVIC_EN0_INT23;
	
	//Enable the Timer
 GPTM_CONTROL_R |=TIM_A_ENABLE;
	
}

void configureSystickTimer (void)
{
  ST_CTRL_R &= ~ST_ENABLE;  //Disabling systick
	ST_RELOAD_R = ST_RELOAD_VALUE; //Writing reload value
	ST_CURRENT_R = 0;  //Setting Count Flag value to 0
  ST_CTRL_R |= (ST_INT_EN); 	//Enabling Interrupt
	ST_CTRL_R |= ST_CLK_SRC;   //Clock Source is Main clock
  ST_CTRL_R |= ST_ENABLE; //Enable Systick Timer
}

void Timer2A_Handler (void)
{

unsigned int time_period = 0;
static unsigned int time_capture = 0;
float time = 0;
static char flag =0;

//Debugging Variable
//char distanceToString [10];	
	
	
	GPTM_INT_CLEAR_R |= TIM_A_CAP_EVENT_IC; //Clear interrupt Flag
	GPTM_CONTROL_R ^= TIM_A_EVENT_NEG_EDGE; //Toggling the Event so Pulse width can be measured 
	
	if (flag ==0)
	{
	  time_capture = GPTM_TA_COUNT_R;
		flag = 1;
	}
	
	else 
	{
	
	  if (GPTM_TA_COUNT_R > time_capture)
			time_period = time_capture - GPTM_TA_COUNT_R;
		  else
			time_period = time_capture - GPTM_TA_COUNT_R;
			
		//Getting the pulse width time and converting it to milliseconds
		 time = (time_period*1000)/16000000.0;
			
		 //Using S= V(T/2) we get the distance; 4 is a calibration factor to convert reading to inches
		 distance2 = (time/2.0) * 3.43 * 4;
			
			//For Debugging Purposes!
		/* sprintf(distanceToString, "%d", distance2);
		 LCD_Clear();
		 LCD_Goto_XY (1,1);
		 LCD_Send_String("Distance:");
		 LCD_Send_String(distanceToString);
	   */
			
			flag = 0;
	}
}

//After each 50ms the Systick timer triggers the sensor
void SysTick_Handler (void)
{
  triggerSensor();

}
	
//Function for Triggering the Distance sensor with a pulse of 10us
void triggerSensor (void)
{
	GPIO_PORTE_DATA_TRIG_R &= ~TRIG_PINE2;
  //Providing a pulse of >10us on Trigger Pin
	GPIO_PORTE_DATA_TRIG_R |= TRIG_PINE2;
	Delay(4);
	GPIO_PORTE_DATA_TRIG_R &= ~TRIG_PINE2;

}

// Function to return the distance measured by the Sensor
int getDistance(void)
{
 return distance2;

}


