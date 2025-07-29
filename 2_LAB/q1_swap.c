#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main(int argc, char *argv[]){
  int x = atoi(argv[1]);
  int y = atoi(argv[2]);

  printf("Before swapping: x = %d, y = %d\n", x, y);

  swap(&x, &y);

  printf("After swapping:  x = %d, y = %d\n", x, y);

  return 0;

}