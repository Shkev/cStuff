#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int binarySwapWithShift(int num, int bits)
{
  int tmp1 = 0, tmp2 = 0, tmp3 = 0;
  for (int loopCount = 0; loopCount < bits; loopCount++)
  {
    tmp3 = tmp3 << 1;  //shifting number left one to result in final shift of 7 (not 8)
    tmp1 = num >> loopCount;  //shifting num by loopCount to shift it to a different bit everytime  
    tmp2 = (tmp1 & 0x1);  //compares byte that is shifted to with 1 with `&` operator
    tmp3 = (tmp3 | tmp2);  //shifted tmp3 byte is compared to tmp2
  }
  return tmp3;
}
  
int main()
{
  int num = 0xdeadbeef;
  int swapped_num = binarySwapWithShift(num, 32);
  printf("Input: 0%x\nOutput: 0x%x\n", num, swapped_num);
}
