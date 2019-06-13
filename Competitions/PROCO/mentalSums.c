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
  input = fopen("./standard_input.txt", "r");
  output = fopen("./standard_output.txt", "w");
  fscanf(input, "%d %d %d", &Q, &a, &b);
  //printf("%d %d %d\n", Q, a, b);
  int mod = pow(10, 5) + 7;
  //printf("%d\n", mod);
  int xArr[Q];
  int count[Q];
  memset(count, 0, 25);
  int sum = 0;
  int single = FALSE;
  for (int i = 0; i >= 0; i++)
  {
    int num = 0;
    int j = i % Q;
    if (i < Q)
    {
      xArr[j] = ((a + (b * (j + 1))) % mod);
    }
    //printf("%d\n ", xArr[j]);
    for (int k = 0; k < Q; k++)
    {
      num += (xArr[j]/ 10);
    }   
    if (num == 0)
    {
      break;
    }
    if ((xArr[j] / 10) < 1)
    {
      single = TRUE;
      continue;
    }
    sum = 0;
    //loop to separate digits
    while (xArr[j] != 0)
    {
      if ((single == TRUE) & ((xArr[j] / 10) < 1))
      {
        break;
      }
      int digit = xArr[j] % 10;
      sum += pow(digit, 2);
      xArr[j] /= 10;
      printf("%d\n", xArr[j]);
      if (xArr[j] != 0)
      {
        count[j]++;
      }
    }
    xArr[j] = sum;
    printf("%d\n", xArr[j]);
  }
  for (int i = 0; i < Q; i++)
  {
    fprintf(output, "%d\n", count[i]);
  }
  fclose(input);
  fclose(output);
  exit(EXIT_SUCCESS);
}
