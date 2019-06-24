#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define TRUE       0
#define FALSE      1

int main()
{
  clock_t begin = clock();
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
    xArr[i] = ((a + (b * (i + 1))) % mod);
    //printf("%d\n", xArr[i]);
    while ((sum[i] / 10) != 0)
    { 
      if (((xArr[i] / 10) < 1) & (count[i] == 0))
      {
        single = TRUE;
      }
      else
      {
        single = FALSE;
      }
      sum[i] = 0;
      //loop to separate digits
      while (xArr[i] != 0)
      {
        if ((single == TRUE) & ((xArr[i] / 10) < 1))
        {
          count[i] = 0;
          sum[i] = 0;
          break;
        }
        int digit = xArr[i] % 10;
        sum[i] += pow(digit, 2);
        xArr[i] /= 10;
      }
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
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("time = %f sec", time_spent);
  exit(EXIT_SUCCESS);
}
