#define __display_c
#include "includeAll.h"

code const uint8_t displayFonts[19] = { 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x80,0x00};

void DisplayTenNumber(uint8_t number){
	uint16_t temp1,temp2,temp3,temp4;
	uint8_t i = 0,l=1;
	temp1 = P1MODH;
	temp2 = P3MODL;
	temp3 = P3MODH;
	temp4 = P1MODL;
	//1.7
	P1MODH = 0xAA;
	//3.2
	P3MODL = 0xAA;
	//3.4
	P3MODH = 0x2A;
	//1.2
	P1MODL = 0xAA;
	
	P1_6 = 1;
	P1_1 = 0;
	
		
	P1_4 = displayFonts[number]&l;
	l=l*2;
	P3_4 = displayFonts[number]&l;
	l=l*2;
	P3_5 = displayFonts[number]&l;
	l=l*2;
	P1_7 = displayFonts[number]&l;
	l=l*2;
	P3_6 = displayFonts[number]&l;
	l=l*2;
	P1_2 = displayFonts[number]&l;
	l=l*2;
	P3_2 = displayFonts[number]&l;
	

	
	P1MODH = temp1;
	P3MODL = temp2;
	P3MODH = temp3;
	P1MODL = temp4;

}

void DisplayBitNumber(uint8_t number){
	uint16_t temp1,temp2,temp3,temp4;
	uint8_t  i=0,l=1;
	temp1 = P1MODH;
	temp2 = P3MODL;
	temp3 = P3MODH;
	temp4 = P1MODL;
	//1.7
	P1MODH = 0xAA;
	//3.2
	P3MODL = 0xAA;
	//3.4
	P3MODH = 0x2A;
	//1.2
	P1MODL = 0xAA;
	
	P1_6 = 0;
	P1_1 = 1;
	
	P1_4 = displayFonts[number]&l;
	l=l*2;
	P3_4 = displayFonts[number]&l;
	l=l*2;
	P3_5 = displayFonts[number]&l;
	l=l*2;
	P1_7 = displayFonts[number]&l;
	l=l*2;
	P3_6 = displayFonts[number]&l;
	l=l*2;
	P1_2 = displayFonts[number]&l;
	l=l*2;
	P3_2 = displayFonts[number]&l;
	
	P1MODH = temp1;
	P3MODL = temp2;
	P3MODH = temp3;
	P1MODL = temp4;


}

void DisplayNumber(uint8_t number)
{
	uint8_t i,j;
	if(number>100)
		return;

	j = number % 10;
	DisplayBitNumber(j);

	i = (number - j)/10;
	DisplayTenNumber(i);

}

void ClearNumber(uint8_t number)
{
	uint16_t temp1,temp2,temp3,temp4;
	uint8_t  i=0,l=1;

	//1.7
	P1MODH = 0xAA;
	//3.2
	P3MODL = 0xAA;
	//3.4
	P3MODH = 0x2A;
	//1.2
	P1MODL = 0xAA;
	
	P1_6 = 0;
	P1_1 = 1;
	
	P1_4 = displayFonts[number]&l;	//a
	l=l*2;
	P3_4 = displayFonts[number]&l;	//b
	l=l*2;
	P3_5 = displayFonts[number]&l;	//c
	l=l*2;
	P1_7 = displayFonts[number]&l;	//d
	l=l*2;
	P3_6 = displayFonts[number]&l;	//e
	l=l*2;
	P1_2 = displayFonts[number]&l;	//f
	l=l*2;
	P3_2 = displayFonts[number]&l;	//g
	l=l*2;
	P1_3 = displayFonts[number]&l;	//dg
}