#ifndef __keys_h
#define __keys_h
// Hal: exp: #define P_led P10 -----------------
#define P_key3 P1_7
#define P_key4 P1_2
//#define P_key1 P1_1
// Const: exp: #define D_data 1 ----------------
#define D_keyNull 0
#define D_keyValue1 1
#define D_keyValue2 2
// Globle Var -----------------------------------------
#ifdef __keys_c
uint8_t keyValue;
uint8_t keyValue3;
#else
extern uint8_t keyValue;
extern uint8_t keyValue3;
#endif

// Action Macro: exp: #define F_getData() ------

// Function ------------------------------------
void GetKeys();
#endif