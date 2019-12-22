#define __keys_c
#include "includeAll.h"
//=============================================================================
//按键信息获取
void GetKeys() {
	static uint8_t tempKeyValue = D_keyNull;
	
//	delayMs(10); //去抖，提高按键的稳定性
	if(P_key4 == 0){
		tempKeyValue = D_keyValue1;
	}	else{
		keyValue = tempKeyValue;
		tempKeyValue = D_keyNull;
	}
	/*
	if(P_key3 == 0){
		tempKeyValue = D_keyValue1;
	}	else{
		keyValue3 = tempKeyValue;
		tempKeyValue = D_keyNull;
	}
	*/
}