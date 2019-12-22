#ifndef __display_h
#define __display_h
// Hal: exp: #define P_led P10 -----------------
#define P_ledcom P1_0	
#define P_led2 P1_2
#define P_led1 P1_4
#define P_buzz P1_5
#define P_smgcom1 P1_1
#define P_smgcom2 P1_6
//#define P_D P1_7

// Const: exp: #define D_data 1 ----------------
#define D_ledOn 1  //高电位亮
#define D_ledOff 0 //低点位灭
// Globle Var -----------------------------------------
#ifdef __display_c
bit bflag0;
bit bflag;
uint8_t num;
#else
extern bit bflag0;
extern bit bflag;
extern uint8_t num;
#endif

// Action Macro: exp: #define F_getData() ------
#define F_ledOn() P_led = D_ledOn
#define F_ledOff() P_led = D_ledOff
#define F_ledNeg() P_led = ~P_led
// Function ------------------------------------
void DisplayNumber(uint8_t number);
void DisplayTenNumber(uint8_t number);
void DisplayBitNumber(uint8_t number);
void ClearNumber(uint8_t number);
#endif