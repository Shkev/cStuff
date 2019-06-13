#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define TRUE       0
#define FALSE      1

int main()
{
  FILE* input;
  FILE* output;
  int Q, a, b;
  input = fopen("standard input", "r");
  output = fopen("standard output", "w");
  fscanf(input, "%d %d %d", &Q, &a, &b);
  int mod = pow(10, 5) + 7;
  int xArr[Q];
  int count[Q];
  int sum[Q];
  int single = FALSE;
  int k = 0, numDigit = 0;
  for (int i = 0; i < 3; i++)
  {     
    sum[i] = 100;
    count[i] = 0;
    printf("i: %d\n", i);
    xArr[i] = ((a + (b * (i + 1))) % mod);
    //printf("%d\n", xArr[i]);
    while ((sum[i] / 10) != 0)
    {
      int j = k % Q; 
      printf("arr: %d\n", xArr[i]);
      if (((xArr[i] / 10) < 1) & (count[i] == 0))
      {
        single = TRUE;
      }
      else
      {
        single = FALSE;
      }
      sum[i] = 0;
      numDigit = 0;
      //loop to separate digits
      while (xArr[i] != 0)
      {
        if ((single == TRUE) & ((xArr[i] / 10) < 1))
        {
          count[i] = 0;
          sum[i] = 0;
          numDigit = 1;
          break;
        }
        int digit = xArr[i] % 10;
        numDigit++;
        sum[i] += pow(digit, 2);
        xArr[i] /= 10;
      }
      printf("numDigit: %d\n", numDigit);
      if (single == FALSE)
      {
        count[i]++;
      }
      else
      {
        continue;
      }
      xArr[i] = sum[i];
      k++;
    }
  }
  for (int i = 0; i < Q; i++)
  {
    fprintf(output, "%d\n", count[i]);
  }
  fclose(input);
  fclose(output);
  exit(EXIT_SUCCESS);
}
