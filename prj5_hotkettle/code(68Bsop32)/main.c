#define __main_c
#include "includeAll.h"
//=============================================================================
void main() {
  SysInit();
  VarsInit();
	//使能看门狗
	F_turnOnWDT();
	modeValue = 1; //初始值为1
	P_buzz = 0;
	P_ledcom=0;
	//P_smgcom1=1;
	//P_smgcom2=0;
	// num = 0;
	//P_led1=0;
	
	//P_led2=1;
	//P_D=0;
	/*
	uint8_t i;
　uint8_t code duan_ma[]= { 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};//共阴
	//uint8_t code duan_ma[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};//共阳
　　while(1) { 
	 P1=0xfe; 
	 for(i=1;i<<=6;i++) { 
		P0=duan_ma[i];
　　	delay_ms(400);
　　	P1=(P1<<1)|0x01;
　　}
　　}
	*/
	
	while(1){
		//清看门狗
		F_clearWDT();
		//业务代码
		//TimeProcess();
		//TaskSetting();
		//TaskProcess();
		DisplayProcess();
	}
}

//=============================================================================
	void TimeProcess(){
		static uint8_t timer5ms = 0;

		if (b1ms) {
			// 1ms 执行一次
			b1ms = 0;
			timer5ms++;
		}
		if (timer5ms >= 5) {
			P1MODL = 0x8a;
			GetKeys();
			
			//P_buzz = ~P_buzz;
			//P_led1 = ~P_led1;
			//P_led2 = ~P_led2;
			//P_D = ~P_D;
			
		}
	}
//=============================================================================
	void TaskSetting(){	
	//**单端口复用控制LED亮灭**
	if (modeValue == 1){//模式标志为1时，该模式为推挽输出
		//LED状态转换
		if(D_keyValue1 == keyValue){
			Mode_Neg();		//模式标志为取反
		}
		P1MODL = 0xaa;		//将模式置为推挽输出，使LED显示
		} else {//否则，该模式为上拉输入
			if(D_keyValue1 == keyValue){
				Mode_Neg();		
			}
		}
	} 
//=============================================================================
	void TaskProcess(){
		//P_ledcom=0;
		/*
		P_led1=0;
		P_led2=1;
		delayMs(400);
		P_led1=1;
		P_led2=0;
		delayMs(400);*/
		/*
    P_buzz=1;
		delayMs(100);
     P_buzz=0;
		delayMs(50);
		*/
		//P_D=1;
	}
//=============================================================================
	void DisplayProcess(){
       	close_led();   
		    num = (9<=num)?num=-1:num;
        num++;
        close_led();
        disp_num(num);
				delayMs(200);
       
	}
//=============================================================================
//延时函数
void delayMs(uint16_t time){
	uint16_t i,j;
	for(i=0; i<time; i++){
		for(j=0; j<1000; j++){
		}
	}
	//while(time--);
}

//led数码管显示
void led_disp()
{
	//com0_disp(buffer[3]);	  //显示按键S4加1计数的值
	//com1_disp(buffer[2]);	  //显示按键S3加1计数的值
	//com2_disp(buffer[1]);	  //显示AD转换值的高4位
	//com3_disp(buffer[0]);	  //显示AD转换值的低4位
}

//显示程序
void disp_num(uint8_t i)
{
      /*  switch(i)
        {
                case 0:{
                        led_a = 1;                        
                        led_b = 1;
                        led_c = 1;
                        led_d = 1;
                        led_e = 1;
                        led_f = 1;
                }break;

                case 1:{                
                        led_b = 1;
                        led_c = 1;
                }break;

                case 2:{                
                        led_a = 1;
                        led_b = 1;
                        led_g = 1;                        
                        led_e = 1;
                        led_d = 1;
                
                }break;

                case 3:{
                        led_a = 1;
                        led_b = 1;
                        led_g = 1;
                        led_c = 1;
                        led_d = 1;
                }break;

                case 4:{
                        led_f = 1;
                        led_g = 1;                
                        led_b = 1;
                        led_c = 1;
                }break;

                case 5:{
                        led_a = 1;
                        led_f = 1;
                        led_g = 1;
                        led_c = 1;
                        led_d = 1;                
                }break;

                case 6:{
                        led_a = 1;
                        led_f = 1;
                        led_g = 1;
                        led_c = 1;
                        led_d = 1;
                        led_e = 1;
                }break;

                case 7:{
                        led_a = 1;
                        led_b = 1;
                        led_c = 1;                
                }break;

                case 8:{
                        led_a = 1;
                        led_b = 1;
                        led_c = 1;
                        led_d = 1;
                        led_e = 1;
                        led_f = 1;
                        led_g = 1;
                }break;

                case 9:{
                        led_a = 1;
                        led_b = 1;
                        led_c = 1;
                        led_d = 1;
                        led_f = 1;
                        led_g = 1;
                
                }break;
				}*/
}

//关闭所有灯
void close_led()
{
     P_smgcom1 = 0;
     //led_dot = 0;
}