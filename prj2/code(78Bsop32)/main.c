#define __main_c
#include "includeAll.h"
//=============================================================================

void main() {
  SysInit();
  VarsInit();

  //初始点亮LED灯
  F_led1On();
  DelayMs(500);

 //使能看门狗
  F_turnOnWDT();
  while (1) {
   //喂狗
   F_clearWDT();

   //获取按键标志
   GetKeyValue();
   if (D_keyValue1 == keyValue) {
      F_led1Neg();
    }
    //初始化keyValue值
    keyValue = D_keyNull; 

  }
}

//=============================================================================
void DelayMs(uint16_t msCount) {
 uint16_t i,j;
  for ( i = 0; i < msCount; i++) {
          for ( j = 0; j < 1000; j++) {
            F_clearWDT();
    }
          }
  }



      