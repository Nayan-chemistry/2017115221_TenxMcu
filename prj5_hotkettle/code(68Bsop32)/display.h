#ifndef __display_h
#define __display_h
// Hal: exp: #define P_led P10 -----------------
#define P_ledcom P1_0	
#define P_led2 P1_2
#define P_led1 P1_4

#define SMG_COM1 P1_1
#define SMG_COM2 P1_6

#define SMG_A P1_4
#define SMG_B P3_4
#define SMG_C P3_5
#define SMG_D P1_7
#define SMG_E P3_6
#define SMG_F P1_2
#define SMG_G P3_2
#define SMG_DG P1_3

// Const: exp: #define D_data 1 ----------------
#define D_ledOn 1  //高电位亮
#define D_ledOff 0 //低点位灭
// Globle Var -----------------------------------------
#ifdef __display_c

#else

#endif

// Action Macro: exp: #define F_getData() ------
#define F_ledOn() P_led = D_ledOn
#define F_ledOff() P_led = D_ledOff
#define F_ledNeg() P_led = ~P_led
// Function ------------------------------------
void SMG_Select(uint8_t position, uint8_t number);
void SMG_Display(uint8_t number);
void Set_Pin_Sta();
#endif