#include <stdio.h>
#include <stdlib.h>
#include "getcharSort.h"

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

void sort(int input[], int size)
{
  int i, j;
  for (i = 0; i < size - 1; i++)
  {
    for(j = i + 1; j < size; j++)
    {
      if (input[i] > input[j])
      {
        int tmp = input[i];
        input[i] = input[j];
        input[j] = tmp;
      }
    }
  }
}
