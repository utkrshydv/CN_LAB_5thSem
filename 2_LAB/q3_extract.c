#include <stdio.h>

int main(){
  int num;
  unsigned char byte1, byte2, byte3, byte4;

  printf("Enter a 4-byte integer number: ");
  scanf("%d", &num);

  byte1 = num&0xFF;
  byte2 = (num >> 8) & 0xFF;
  byte3 = (num >> 16) & 0xFF;
  byte4 = (num >> 24) & 0xFF;

  printf("\nExtracted Bytes:\n");
  printf("Byte 1: 0x%02X\n", byte1);
  printf("Byte 2: 0x%02X\n", byte2);
  printf("Byte 3: 0x%02X\n", byte3);
  printf("Byte 4: 0x%02X\n", byte4);

  return 0;

}