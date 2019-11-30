#define __keys_c
#include "includeAll.h"

//=============================================================================
void GetKeyValue() {
  static uint8_t tempKeyValue = D_keyNull;
  if (P_key == 0) {
      tempKeyValue = D_keyValue1;
  } else {
    keyValue = tempKeyValue;
    tempKeyValue = D_keyNull;
  }
} 