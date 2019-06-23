//incomplete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*int main()
{
  int x = log2(2);
  printf("%d\n", x);
}*/
void printArr(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%c", arr[i]);
    if (i == size)
    {
      printf("\n");
    }
  }
}

void makeNum(int arr[], int size)
{
  for (int i = size - 1; i > -1; i--)
  {
    int x = arr[i];
    printf("%c\n", x);
    for (int j = 0; j < i - 1; j++)
    {
      arr[i] = (x * 100) + 48;
    }
    printf("%d\n", arr[i]);
  }
}

int convertBinary(int input[], int size, int num2[])
{
  //printf("%d\n", size);
  int num10;
  makeNum(input, size); 
  //printf("\n%d\n", num10);
  int placeValMax;
  float store1;
  int count = 0;
  store1 = floor(log2(num10));
  int store = store1;
  placeValMax = store;
  while (num10 != 0)
  {
    int val1 = placeValMax;
    placeValMax = floor(log2(num10));
    int val2 = placeValMax;
    num10 -= (2 ^ placeValMax);
    if ((count != 0) & (val2 = val1 - 1))
    {
      num2[store - count - 1] = 1;
    }
    else
    {
      if (val2 != val1 - 1)
      {
        int dif = val1 - val2;
        for (int j = 1; j <= dif; j++)
        {
        num2[store - count - j] = 0;
        }
      }
    }
    count++;
  }
  if (placeValMax != 0)
  {
    for (int j = 0; j < store - count; j++)
    {
      num2[j] = 0;
    }
  }
  return store + 1;
}

int main()
{
  int ch;
  int strch[50];
  ch = getchar();
  int j = 0;
  while (ch != '\n')
  {
    strch[j] = ch;
    ch = getchar();
    j++;
  }
  int hexadecimal[25];
  printf("\nDecimal:\n");
  printArr(strch, j);
  int binaryNum[150];
  printf("\nBinary\n");
  int f = convertBinary(strch, j, binaryNum);
  printArr(binaryNum, f);
  printf("\nHexadecimal\n");

  exit(EXIT_SUCCESS);
}
