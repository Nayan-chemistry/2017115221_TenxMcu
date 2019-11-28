#ifndef __keys_h
#define __keys_h
// 定义按键的
#define P_key P1_0

// 声明变量值
#define D_keyNull 0
#define D_keyValue1 1
#define D_keyValue2 2

// 声明全局变量
#ifdef __keys_c
uint8_t keyValue;
#else
extern uint8_t keyValue;
#endif

// Action Macro: exp: #define F_getData() ------

// 声明GetKeys()函数
void GetKeys();
#endif 