#define __display_c
#include "includeAll.h"

code const uint8_t displayFonts[19] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x80,0x00,0xff};

void SMG_Select(uint8_t position, uint8_t number)
{
    //选择数码管的位置
    //根据电路图，电平为低时该位被选中
    if (position == 1)
    {
        SMG_COM1 = 0;
        SMG_COM2 = 1;
    }
    else if (position == 2)
    {
        SMG_COM1 = 1;
        SMG_COM2 = 0;
    }

    //数位赋值
    SMG_A = 0x01 & (displayFonts[number] >> 0);
    SMG_B = 0x01 & (displayFonts[number] >> 1);
    SMG_C = 0x01 & (displayFonts[number] >> 2);
    SMG_D = 0x01 & (displayFonts[number] >> 3);
    SMG_E = 0x01 & (displayFonts[number] >> 4);
    SMG_F = 0x01 & (displayFonts[number] >> 5);
    SMG_G = 0x01 & (displayFonts[number] >> 6);
    SMG_DG = 0x01 & (displayFonts[number] >> 7);
}

void SMG_Display(uint8_t number)
{
		uint8_t i,j;
		
		if(number>100)
			return;
		//个位
		j = number % 10;
		SMG_Select(2, j);
		delayMs(10);
		//十位
		i = (number - j)/10;
		SMG_Select(1, i);
		delayMs(10);
}

void Set_Pin_Sta()
{
		P1_2 = 1;
		P1_7 = 1;
}
