//Timer 2 Base Address
#define TM_BASE 0x40032000

//Clock enabling for Timer and GPIO
#define RCGC_TIMER_R *(volatile unsigned long *) 0x400FE604

#define CLOCK_GPIOF 0x00000020
#define CLOCK_GPIOE 0x00000010
#define CLOCK_GPIOB 0x00000002
#define SYS_CLOCK_FREQUENCY 16000000

//Timer configuration Registers
#define TRIG_ECHO_PIN_EN 0x06
#define TRIG_PINE2 0x04
#define ECHO_PINE1 0x02

#define PORTE_CLK_EN 0x10;

//Timer configuration Registers
#define GPTM_CONFIG_R *(volatile unsigned long *)(TM_BASE + 0x000)
#define GPTM_TA_MODE_R *(volatile unsigned long *)(TM_BASE + 0x004)
#define GPTM_CONTROL_R *(volatile unsigned long *)(TM_BASE + 0x00C)
#define GPTM_INT_MASK_R *(volatile unsigned long *)(TM_BASE + 0x018)
#define GPTM_INT_CLEAR_R *(volatile unsigned long *)(TM_BASE + 0x024)
#define GPTM_TA_IL_R *(volatile unsigned long *)(TM_BASE + 0x028)
#define GPTM_TA_MATCH_R *(volatile unsigned long *)(TM_BASE + 0x030)
#define GPTM_TA_PRESCALE_R *(volatile unsigned long *)(TM_BASE + 0x038)
#define GPTM_TA_COUNT_R *(volatile unsigned long *)(TM_BASE + 0x048)
	
// IRQ 0 to 31 Enable and Disable Registers
	
#define NVIC_EN0_R *((volatile unsigned long *) 0xE000E100)
#define NVIC_DIS0_R *((volatile unsigned long *) 0xE000E180)

//GPIO alternate function Configuration
#define GPIO_PORTF_AFSEL_R *((volatile unsigned long *) 0x40025420)
#define GPIO_PORTF_PCTL_R *((volatile unsigned long *) 0x4002552C)
#define GPIO_PORTF_DEN_R *((volatile unsigned long *) 0x4002551C)
	
//Timer2 A interrupt is assigned to NVIC IRQ23
#define NVIC_EN0_INT23 0x00800000

//Timer2 A bit field definitions for mode configuration
#define TIM_16_BIT_CONFIG 0x00000004
#define TIM_EDGE_TIME_MODE 0x00000004
#define TIM_CAPTURE_MODE 0x00000003

//Timer event Type bit field definitions
#define TIM_A_EVENT_POS_EDGE 0x00000000
#define TIM_A_EVENT_NEG_EDGE 0x00000004
#define TIM_A_EVENT_BOTH_EDGES 0x0000000C
#define TIM_A_ENABLE 0x00000001

//Timer A capture mode interrupt mask/clear
#define TIM_A_CAP_EVENT_IM 0x00000004
#define TIM_A_CAP_EVENT_IC 0x00000004

// Reload values for Timer A with prescale
#define TIM_A_INTERVAL 0x0000FFFF
#define TIM_A_PRESCALE 0x000000FF

//The value required to give to the Delay function for 1sec Delay
#define SECOND 100000

//Function Prototypes
void Timer2A_Init(void);
void distanceSensorConfig(void);
void triggerSensor (void);
int getDistance(void);

