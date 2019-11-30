#define __init_c
#include "includeAll.h"
//=============================================================================
void SysInit() {
 F_clearWDT();  //启动后立即清除看门狗
  //时钟初始化
 CLKCON = 0x03; // Clock div 1 7.3728mHz
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

  // IO 模式初始化为推挽输出
  P1MODL = 0xaa; 
  P1_0 = 1;  
  // IO 状态初始化
  F_ledOff();      //LED灯初始化为低电平状态（不亮）

}
//=============================================================================
void VarsInit() {} 