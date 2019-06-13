#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
  int num = 0;
  for (int i = 0; i >= 0; i++)
  {
    if (num == Q)
    {
      break;
    } 
    int j = i % Q;
    xArr[j] = ((a + (b * (j + 1))) % mod);
    int sum = 0;
    while (xArr[j] != 0)
    {
      if ((xArr[j] / 10) < 1)
      {
        num++;
        break;
      }
      int digit = xArr[j] % 10;
      sum += pow(digit, 2);
      xArr[j] /= 10;
      count[j]++; 
    }
    xArr[j] = sum;
  }
  for (int i = 0; i < Q; i++)
  {
    fprintf(output, "%d\n", xArr[i]);
  }
  //int c, d, e;
  //fscanf(output, "%d\n%d\n%d", &c, &d, &e);
  //printf("%d %d %d", c, d, e);
  fclose(input);
  fclose(output);
  exit(EXIT_SUCCESS);
}
