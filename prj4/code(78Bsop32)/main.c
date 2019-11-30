#define __main_c
#include "includeAll.h"
//=============================================================================

int model = 1;           //状态初始化为1

void main(){
  SysInit();
  VarsInit();
  //使能看门狗
  F_turnOnWDT();

  while (1) {
    //喂狗
    F_clearWDT();
    //业务代码
    TimeProcess();
    DisplayProcess();
    TaskSetting();
    TaskProcess();
  }

}


//============================================
void DisplayProcess() {}
//============================================
void TimeProcess() {}
//============================================
void TaskSetting(){	}
//=========单端口控制LED亮灭===================
void TaskProcess() {

	//设置为上拉模式，获取按键值
	    P1MODL = 0xa8;		
		GetKeyValue();
        DelayMs(100);		 //稍微延时，获取键值

	if (model== 1){          //状态标志为1时，设置为推挽输出	
		//按下按键
		if(D_keyValue1 == keyValue){
			model_Switch();	 //状态标志取反
		}
		P1MODL = 0xaa;		 //模式为推挽输出，点亮LED
		
	}
	  else {                  //未按下按键，为上拉模式
		//按下按键
		if(D_keyValue1 == keyValue){
			model_Switch();	  //状态标志取反
		
     	}

	} 

}


void DelayMs(int time){
	uint16_t i,j;
	for(i=0; i<time; i++){
		for(j=0; j<1000; j++){
		}
	}
}

      