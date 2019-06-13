#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
  FILE* input;
  FILE* output;
  int Q, a, b;
  input = fopen("standard input", "r");
  output = fopen("standard output", "w");
  fscanf(input, "%d %d %d", &Q, &a, &b);
  //printf("%d %d %d\n", Q, a, b);
  int mod = pow(10, 5) + 7;
  //printf("%d\n", mod);
  int xArr[Q];
  int count[Q];
  memset(count, 0, 25);
  int num = 0;
  for (int i = 0; i >= 0; i++)
  {
    if (num == Q)
    {
      break;
    } 
    int j = i % Q;
    xArr[j] = ((a + (b * (j + 1))) % mod);
    //printf("%d\n", xArr[j]);
    int sum = 0;
    while (xArr[j] != 0)
    {
      if ((((xArr[j] / 10) < 1))
      {
        num++;
        break;
      }
      int digit = xArr[j] % 10;
      sum += pow(digit, 2);
      //printf("%d\n", sum);
      xArr[j] /= 10;
      count[j]++; 
    }
    xArr[j] = sum;
    printf("%d %d\n", xArr[j], num);
  }
  for (int i = 0; i < Q; i++)
  {
    printf("%d\n", count[i]);
  }
  fclose(input);
  fclose(output);
  exit(EXIT_SUCCESS);
}
