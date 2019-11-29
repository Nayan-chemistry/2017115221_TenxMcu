#define __init_c
#include "includeAll.h"
//=============================================================================
void SysInit() {
  F_clearWDT();  //启动后立即清除看门狗
  //时钟初始化
  CLKCON = 0x03; // Clock div 1  7.3728Mhz
  STPPCK = 0;
  STPFCK = 0;
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  SELFCK = 1;
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();

  //将IO模式置为上拉输入
  P1MODL = 0xa8;

  // IO 状态初始化
  F_ledOff();      //LED灯初始化为低电平状态（不亮）

  // T2 初始化  7.3728Mhz/2 = 3686400Hz
  //  3686400Hz/3686.4 = 1000Hz = 1ms timer2 interrupt
  TH2 = (65536 - 900) / 256;
  RCP2H = TH2;
  TL2 = (65536 - 900) % 256;
  RCP2L = TL2;
     
   
  EA = 1;   // 开总中断
  ET2 = 1;  // timer2中断使能
  TR2 = 1;  // timer2运行
}

//=============================================================================
void VarsInit() {}