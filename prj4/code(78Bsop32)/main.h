#ifndef __main_h
#define __main_h
// Hal: exp: #define P_led1 P11 -----------------

// Const: exp: #define D_data 1 ----------------

// 定义基准时间
#define D_5ms 5
#define D_1000ms 1000


// Globle Var -----------------------------------------
#ifdef _main_c

#else

#endif

//定义状态位取反函数
#define model_Switch() model = ~model

//业务函数声明
void TimeProcess();
void DisplayProcess();
void TaskSetting();
void TaskProcess();

// 延时函数声明
void DelayMs(int time);

#endif 