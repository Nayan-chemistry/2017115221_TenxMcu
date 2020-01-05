#define __keys_c
#include "includeAll.h"
//=============================================================================
//=============================================================================
//按键信息获取
void GetKeys() {
	static uint8_t tempKeyValue = D_keyNull;
	static uint8_t tempKeySelect = 0;
	
	//按键按下
	if(P_key4==0 || P_key3==0){
		tempKeyValue = D_keyValue1;
		
		//检测按下选择的按键
		if(P_key4==0)
			tempKeySelect = 4;
		else if(P_key3==0)
			tempKeySelect = 3;		
	}	
	else{
		keyValue = tempKeyValue;
		keySelect = tempKeySelect;
		tempKeyValue = D_keyNull;
		tempKeySelect = 0;
	}
}
