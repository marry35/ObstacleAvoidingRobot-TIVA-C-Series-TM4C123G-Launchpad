

//Parameters for Systick Timer
#define ST_CTRL_R (*((volatile unsigned long *)   0xE000E010))
#define ST_RELOAD_R (*((volatile unsigned long *) 0xE000E014))
#define ST_CURRENT_R (*((volatile unsigned long *)0xE000E018))

#define ST_ENABLE  0x00000001
#define ST_INT_EN  0x00000002
#define ST_CLK_SRC 0x00000004
#define ST_COUNT   0x00010000

#define ST_RELOAD_VALUE 0x000EA600


void configureSystickTimer(void);
