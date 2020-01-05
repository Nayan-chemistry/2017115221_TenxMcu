#define __main_c
#include "includeAll.h"
//=============================================================================
void main() {
  SysInit();
  VarsInit();
	//使能看门狗
	F_turnOnWDT();
	modeValue = 1; //初始值为1
	buzzCounter = 0; //初始值为0
	//P_buzz = 0;
	P_ledcom=1;
   // BuzzCount(3); //设置蜂鸣器响3下
   	num = 0;	//初始化数值位0
	status = 0;	//初始化0（关）状态
	
	while(1){
	    //使能看门狗
	    F_turnOnWDT();
		//业务代码
		TimeProcess();
		TaskSetting();
		TaskProcess();
		DisplayProcess();
	}
}

//=============================================================================
	void TimeProcess(){
        static uint8_t timer5ms = 0;  //按键计时
		static uint8_t timer250ms = 0;  //蜂鸣器计时
	
		if (b1ms) {
			// 1ms 执行一次
			b1ms = 0;
			timer250ms++;
			timer5ms++;
			
			if (buzzLastTimer > 0) {
				buzzLastTimer--;
			}
		}
		
		if (timer250ms >= 250){
			timer250ms = 0;
			if (buzzCounter > 0) { 	//为0时蜂鸣器不响
				Buzz();
				buzzCounter--;
			}
		}
		
		if (timer5ms >= 5) {
			timer5ms = 0;
			P1MODL = 0x8a;
			GetKeys();
		}
	}
//=============================================================================
	void TaskSetting(){	
        switch(keySelect){
			case 4:	//按下Key4
				if(modeValue == 1){//模式标志为1,将开关状态进行转换
						status = temp1+1;					
						Mode_Neg();		//保证按下按键为1次
				}
			  break;
			case 3:	//按下Key3
				if(modeValue == 1){
						//蜂鸣器响一声,数值累加1
						BuzzCount(1);
						num = temp+1;
					  Mode_Neg();	//保证按下按键为1次
				}
		  	break;
			case 0:
				if(modeValue == 1){
					P1MODL = 0xaa;
					P1MODH = 0xaa;
				}
				else {
					Mode_Neg();	//取反,重新去获取按键按下情况
				}
				break;
		}//switch	
	} 
//=============================================================================
	void TaskProcess(){
      //SMG_Select(2, num);
		
		/*
		//按键控制数码管开关显示
		SMG_ON_or_OFF(status);
		if (status > 1)
			status = 0;
		temp1 = status;
		*/
		
		//按键控制数码管计数
		SMG_Display(num);
		if (num > 9)
			num = 0;
	  	temp = num;
	}
//=============================================================================
	void DisplayProcess(){
       	Set_Pin_Sta(); //设置pin脚状态
	}
//=============================================================================
//延时函数
void delayMs(uint16_t time){
	uint16_t i,j;
	for(i=0; i<time; i++){
		for(j=0; j<1000; j++){
		}
	}
}
