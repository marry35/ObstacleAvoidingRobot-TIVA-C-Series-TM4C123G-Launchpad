#define SYSCTL_RCGCGPIO_R  *((volatile unsigned long *) 0x400FE608)
#define GPIO_PORTB_DATA_R  *((volatile unsigned long *) 0x400053FC)
#define GPIO_PORTB_DIR_R   *((volatile unsigned long *) 0x40005400)
#define GPIO_PORTB_DEN_R   *((volatile unsigned long *) 0x4000551C)
#define GPIO_PORTB_AFSEL_R *((volatile unsigned long *) 0x40005420)
	
#define GPIO_PORTE_DATA_R  *((volatile unsigned long *) 0x400240E0)
#define GPIO_PORTE_DIR_R   *((volatile unsigned long *) 0x40024400)
#define GPIO_PORTE_DEN_R   *((volatile unsigned long *) 0x4002451C)
#define GPIO_PORTE_AFSEL_R *((volatile unsigned long *) 0x40024420)
#define GPIO_PORTE_PD_R    *((volatile unsigned long *) 0x40024514)
//For DistanceSensor PE2 for Trigger and PE1 for ECHO
#define GPIO_PORTE_DATA_TRIG_R *((volatile unsigned long *) 0x40024010)
#define GPIO_PORTE_DATA_ECHO_R *((volatile unsigned long *) 0x40024008)
	
//NVIC Registers for Enabling Interrupts on ECHO (E1) Pin
#define GPIO_PORTE_IS_R    *((volatile unsigned long *) 0x40024404)
#define GPIO_PORTE_IBE_R   *((volatile unsigned long *) 0x40024408)
#define GPIO_PORTE_IEV_R   *((volatile unsigned long *) 0x4002440C)
#define GPIO_PORTE_IM_R    *((volatile unsigned long *) 0x40024410)
#define GPIO_PORTE_ICR_R   *((volatile unsigned long *) 0x4002441C)
	
#define NVIC_EN0_R         *((volatile unsigned long *) 0xE000E100)
#define NVIC_PRI1_R        *((volatile unsigned long *) 0xE000E404)
	
#define NVIC_INT4_EN 0x00000010
#define PRILEVEL_5   0x000000A0

#define GPIO_PORTA_BASE 0x40004000
#define GPIO_PORTA_DATA_R  *((volatile unsigned long *) (GPIO_PORTA_BASE + 0x3F0))
#define GPIO_PORTA_DIR_R   *((volatile unsigned long *) (GPIO_PORTA_BASE + 0x400))
#define GPIO_PORTA_DEN_R   *((volatile unsigned long *) (GPIO_PORTA_BASE + 0x51C))
	


	
