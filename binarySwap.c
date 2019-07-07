#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printArr(int arr[], int size) {
  for (int loopCount = 0; loopCount <= size; loopCount++) {
    if (loopCount == size) {
      printf("\n");
      break;
    }
    printf("%c", arr[loopCount]);
  }
}

void binarySwap(int binaryNum[], int size) {
  int sizeIndex = size - 1;
  for (float loopCount = 0; loopCount <= floor(size / 2); loopCount++) {
    int tmp;
    tmp = binaryNum[(int)loopCount];
    binaryNum[(int)loopCount] = binaryNum[sizeIndex - (int)loopCount];
    binaryNum[sizeIndex - (int)loopCount] = tmp;
  }
}
  
int main() {
  char ch;
  int binaryDigits[64];
  ch = getchar();
  int count = 0;    //count variable also counts how many digits are entered
  while(ch != '\n') {
    binaryDigits[count] = ch;
    ch = getchar();
    count++;
  }
  printf("Input: ");
  printArr(binaryDigits, count);
  binarySwap(binaryDigits, count);
  printf("Output (swapped bits): ");
  printArr(binaryDigits, count);
}
