#ifndef __main_h
#define __main_h
// Hal: exp: #define P_led P10 -----------------

// Const: exp: #define D_data 1 ----------------

// Globle Var -----------------------------------------
#ifdef __main_c
uint8_t modeValue; //pin脚模式标志
uint8_t num;
#else
extern uint8_t modeValue;
extern uint8_t num;

#endif


// Action Macro: exp: #define F_getData() ------
#define Mode_Neg() modeValue = ~modeValue		//模式标志取反
// Function ------------------------------------
void delayMs(uint16_t time);
void TimeProcess();
void TaskSetting();
void TaskProcess();
void DisplayProcess();
void led_disp();
void disp_num(uint8_t i);
void close_led();
#endif