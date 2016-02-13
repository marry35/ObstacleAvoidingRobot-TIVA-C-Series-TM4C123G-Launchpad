#define LCD_E_PIN 0x08
#define LCD_RW_PIN 0x10
#define LCD_RS_PIN 0x20
#define LCD_DATA_BUS GPIO_PORTB_DATA_R
#define LCD_CONTROL_BUS GPIO_PORTE_DATA_R

void GPIO_Port_Init (void);
void Delay (volatile unsigned int delay);


void LCD_Clear (void);
void LCD_Send_Command (unsigned char command);
void LCD_Send_Data (unsigned char data);
void LCD_Goto_XY (unsigned char x, unsigned char y);
void LCD_Send_String (char *ptr);
void LCDConfig(void);
