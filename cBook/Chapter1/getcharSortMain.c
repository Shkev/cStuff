#include <stdio.h>
#include <stdlib.h>
#include "getcharSort.h"
#define TRUE   1
#define FALSE  0

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
  //to give give error if any non-numeric character are entered
  //making array of nonDigitASCII values
  int nonDigitASCII[117];
  nonDigitASCII[0] = 0;
  int isChar = FALSE;
  for (int i = 0; i < j; i++)
  {
    if ((strch[i] == 48) | (strch[i] == 49) | (strch[i] == 50) |\
    (strch[i] == 51) | (strch[i] == 52) | (strch[i] == 53) |\
    (strch[i] == 54) | (strch[i] == 55) | (strch[i] == 56) |\
    (strch[i] == 57))
    {
      isChar = FALSE;
    }
    else
    {
      isChar = TRUE;
      break;
    }
  }

  if (isChar == FALSE)
  {
    printf("\nUnsorted list:\n");
    printArr(strch, j);
    sort(strch, j);
    printf("\n\nSorted List:\n");
    printArr(strch, j);
    printf("\n");
  }
  else
  {
    printf("\nSorry, only numerical characters are accepted\n");
  }
  exit(EXIT_SUCCESS);
}
