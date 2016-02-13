#include "lcd.h"
#include "gpio.h"


void GPIO_Port_Init (void)
{

	SYSCTL_RCGCGPIO_R |= 0x12;
	
	GPIO_PORTB_DIR_R |= 0xFF;
	GPIO_PORTB_DEN_R |= 0xFF;
	GPIO_PORTB_AFSEL_R &= ~0xFF;
	
	GPIO_PORTE_DIR_R |= 0x38;
	GPIO_PORTE_DEN_R |=0x38;
	GPIO_PORTE_AFSEL_R &= ~0x38;
}


void LCD_Send_Command (unsigned char command)
{
 LCD_DATA_BUS = command;
	LCD_CONTROL_BUS = 0;
	Delay(1);
	LCD_CONTROL_BUS |= LCD_E_PIN;
	Delay (1);
	LCD_CONTROL_BUS &= ~(LCD_E_PIN);
	Delay (4);
	
}


void LCD_Send_Data (unsigned char data)
{
LCD_DATA_BUS = data;
	LCD_CONTROL_BUS = LCD_RS_PIN;
	
	Delay (1);
	LCD_CONTROL_BUS |= LCD_E_PIN;
	Delay (1);
	LCD_CONTROL_BUS &= ~(LCD_E_PIN);
	Delay(4);

}


void LCD_Init (void)
{
 LCD_CONTROL_BUS = 0;
	Delay (1500);
	
	LCD_Send_Command(0x38);
		LCD_Send_Command(0x10);
		LCD_Send_Command(0x0E);
		LCD_Send_Command(0x06);
}
	
void LCD_Clear (void)
{
LCD_Send_Command (0x01);
	Delay (170);
	LCD_Send_Command (0x02);
	Delay(170);
}

void LCD_Send_String (char *ptr)
{
while (*ptr)
{
 LCD_Send_Data (*ptr);
	ptr++;
}

}



void LCD_Goto_XY (unsigned char x, unsigned char y)
{
unsigned char row_start_address[] ={0x80, 0xC0};
LCD_Send_Command (row_start_address[y-1] + x-1);
Delay (170);

}

void LCDConfig(void)
{
  GPIO_Port_Init();
	LCD_Init();
	LCD_Clear();
}

void Delay (volatile unsigned int delay)
{
  volatile unsigned int i ,j;
	for (i = 0; i<delay ;i++)
	{
	  for (j=0;j<12;j++);
	}
}
