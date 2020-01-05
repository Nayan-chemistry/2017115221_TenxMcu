#ifndef __main_h
#define __main_h
// Hal: exp: #define P_led P10 -----------------

// Const: exp: #define D_data 1 ----------------

// Globle Var -----------------------------------------
#ifdef __main_c
uint8_t modeValue; //pin脚模式标志
uint8_t num;
uint8_t temp;		//暂存num
uint8_t temp1;	//暂存status
uint8_t status;
#else
extern uint8_t modeValue;
extern uint8_t num;
extern uint8_t temp;
extern uint8_t temp1;
extern uint8_t status;
#endif


// Action Macro: exp: #define F_getData() ------
#define Mode_Neg() modeValue = ~modeValue		//模式标志取反
// Function ------------------------------------
void delayMs(uint16_t time);
void TimeProcess();
void TaskSetting();
void TaskProcess();
void DisplayProcess();
#endif