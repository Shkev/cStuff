#include <stdio.h>
#include <stdlib.h>

void sort(int input[], int sorted[], int size)
{
  int num1;
  int num2;
  for (int i = 0; i < (size + 1); i++)
  {
    num1 = input[i];
    for (int j = 0; j < (size + 1); j++)
    {
      if (j == i)
      {
	continue;
      }
      num2 = input[j];
      if (num1 < num2)
      {
        sorted[j] = num1;
        break;
      }
    }
  }
  /*MergeSort attempt :(
  while (i >= 0)
  {
    int mod = i % size;
    if ((iter != 2) & (mod == 1))
    {
      mod = 0;
    }
    for (int k = 1; k < (size + 1); k += iter)
    {
      num1 = input[mod + (k - 1)];
      if (k != size)
      {
        num2 = input[mod + k];
      }
      if (num1 > num2)
      {
        sorted[mod + (k - 1)] = num2;
        sorted[mod + k] = num1;
      }
      else
      {
        sorted[mod] = num1;
        sorted[mod + 1] = num2;
      }
    }
    iter = iter * 2;
    if (iter > size)
    {
      break;
    }
    i += iter;
  }*/
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
  printf("Unsorted list:\n");
  for (int i = 0; i < (j + 1); i++)
  {
    printf("%c", strch[i]);
    if (i == j)
    {
      printf("\n");
    }
  }
  int sortArr[50];
  sort(strch, sortArr, j);
  printf("Sorted List:\n");
  //printf("%d\n", sortArr[2]);
  for (int i = 0; i < (j + 1); i++)
  {
    printf("%c", sortArr[i]);
    if (i == j)
    {
      printf("\n");
    }
  }
  exit(EXIT_SUCCESS);
}

/* Example code:

int main(){
  int ch;
  ch = getchar();
  while(ch != 'a')
  {
   if(ch != '\n')
   printf("ch was %c, value %d\n", ch, ch);
   ch = getchar();
 }
 exit(EXIT_SUCCESS);
}
*/
