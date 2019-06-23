#include <stdio.h>
#include <stdlib.h>
#include "getcharSort.h"

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
  printf("\nUnsorted list:\n");
  printArr(strch, j);
  sort(strch, j);
  printf("\n\nSorted List:\n");
  printArr(strch, j);
  printf("\n");
  exit(EXIT_SUCCESS);
}
