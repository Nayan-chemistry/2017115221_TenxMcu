#ifndef __display_h
#define __display_h
// 分别定义P_led1为p10引脚
#define P_led1 P1_0

// 定义高低电平变量
#define D_ledOn 1  //高电位亮
#define D_ledOff 0 //低点位灭
// Globle Var -----------------------------------------
#ifdef __display_c

#else

#endif

// 定义LED1亮灯、关灯、取反函数
#define F_ledOn()  P_led1 = D_ledOn
#define F_ledOff() P_led1 = D_ledOff
#define F_ledNeg() P_led1 = ~P_led1  

// Function ------------------------------------

#endif 