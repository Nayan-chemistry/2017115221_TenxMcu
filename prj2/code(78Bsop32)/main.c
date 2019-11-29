#define __main_c
#include "includeAll.h"
//=============================================================================

void main() {
  SysInit();
  VarsInit();

  //初始点亮LED灯
  F_led1On();
  DelayMs(500);

  while (1) {
   //喂狗
   F_clearWDT();


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



      