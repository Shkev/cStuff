#include <stdio.h>
#include <stdlib.h>

void sort(int input[], int size)
{
  int num1;
  int num2;
  int count = 0;
  int i = 0;
  int min = i;
  while (i < size)
  {
    if (i < size - 1)
    {
      int j = i + 1;
      if (j < size)
      {
        if (input[j] < input[min])
	{
	  int tmp = input[j];
	  input[j] = input[min];
	  input[min] = tmp;
	  min = j;
	}
      }
      else
      {
        int tmp = input[min];
	input[min] = input[i];
	input[i] = tmp;
      }
    }
    i++;
  }  
  /*for (int i = 0; i < size; i++)
  {
    num1 = input[i];
    for (int j = 1; j < size; j++)
    {
      if (j == i)
      {
	continue;
      }
      num2 = input[j];
      if (num1 < num2)
      {
        if ((j != 0) & (i < j))
        {
          sorted[j - 1] = num1;
          sorted[j] = num2;
          break;
        }
        else
        {
          sorted[j] = num1;
          sorted[j + 1] = num2;
          break;
        }
      }
      else
      {
        sorted[j] = num2;
        sorted[j + 1] = num1;
      }
    }
  }*/
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
  for (int i = 0; i < j; i++)
  {
    printf("%c", strch[i]);
    if (i == j)
    {
      printf("\n");
    }
  }
  sort(strch, j);
  printf("\nSorted List:\n");
  for (int i = 0; i < j; i++)
  {
    printf("%c", strch[i]);
    if (i == j)
    {
      printf("\n");
    }
  }
  printf("\n");
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
