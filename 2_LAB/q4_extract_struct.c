#include <stdio.h>

struct pkt{
  char ch1;
  char ch2[2];
  char ch3;
};

int main(){
  int num;
  struct pkt data;

  printf("Enter a 4-byte integer number: ");
  scanf("%d", &num);

  data.ch1 = num & 0xFF;
  data.ch2[0] = (num >> 8) & 0xFF;
  data.ch2[1] = (num >> 16) & 0xFF;
  data.ch3 = (num >> 24) & 0xFF;

    printf("\nStored in structure:\n");
    printf("ch1      = %d\n", data.ch1 );
    printf("ch2[0]   = %d\n", data.ch2[0] );
    printf("ch2[1]   = %d\n", data.ch2[1] );
    printf("ch3      = %d\n", data.ch3 );

      return 0;
}