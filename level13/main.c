typedef unsigned int uint;
typedef char byte;

char * ft_des(char *param_1)
{
  char cVar1;
  char *cp_param_1;
  uint uVar2;
  char *pcVar3;
  byte bVar4;
  uint index;
  int key_index;
  int local_18;
  int local_14;
  
  bVar4 = 0;
  cp_param_1 = strdup(param_1);
  key_index = 0;
  index = 0;
  do {
    uVar2 = 0xffffffff;
    pcVar3 = cp_param_1;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + (uint)bVar4 * -2 + 1;
    } while (cVar1 != '\0');
    if (~uVar2 - 1 <= index) {
      return cp_param_1;
    }
    if (key_index == 6) {
      key_index = 0;
    }
    if ((index & 1) == 0) {
      if ((index & 1) == 0) {
        for (local_14 = 0; local_14 < "0123456"[key_index]; local_14 = local_14 + 1) {
          cp_param_1[index] = cp_param_1[index] + -1;
          if (cp_param_1[index] == '\x1f') {
            cp_param_1[index] = '~';
          }
        }
      }
    }
    else {
      for (local_18 = 0; local_18 < "0123456"[key_index]; local_18 = local_18 + 1) {
        cp_param_1[index] = cp_param_1[index] + '\x01';
        if (cp_param_1[index] == '\x7f') {
          cp_param_1[index] = ' ';
        }
      }
    }
    index = index + 1;
    key_index = key_index + 1;
  } while( 1 );
}

#include <stdio.h>

int main()
{
    printf("%s\n", ft_des("boe]!ai0FB@.:|L6l@A?>qJ}I"));
}