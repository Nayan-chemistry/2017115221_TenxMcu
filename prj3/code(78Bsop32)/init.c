#define __init_c;
#include "includeAll.h"

//=============================================================================
void SysInit() {
 F_clearWDT();  //启动后立即清除看门狗
  //时钟初始化
 CLKCON = 0x03; // Clock div 1// Clock div 1
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
  
  // IO 模式初始化
 P1MODL = 0xa8;       //将模式置为上拉输入

  // IO 状态初始化
  F_led1Off();      //LED灯初始化为低电平状态（不亮）

  TH2 = (65536 - 900) / 256; // 0.25ms==4khz timer2 interrupt
  RCP2H = TH2;
  TL2 = (65536 - 900) % 256;
  RCP2L = TL2;

  EA = 1;  // 开总中断
  ET2 = 1; // timer2中断使能
  TR2 = 1; // timer2运行
  
}
//=============================================================================
void VarsInit() {} 