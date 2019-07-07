#include <stdio.h>

void primePair(long int max_val)
{
  int mod1;
  int mod2;
  int count = 0;
  for (int j = 3; j < max_val; j++)
  {
    for (int i = 2; i < j; i++)
    {
      mod1 = j % i;
      mod2 = (j + 2) % i;
      if ((mod1 != 0) & (mod2 != 0))
      {
        count++;
      }
    }
    if (count == (j - 2))
    {
      printf("%d and %d are a Prime Pair\n", j, j + 2);
    }
    count = 0;
  }
}

int main()
{
  char input[50];
  long int k;
  //int mod1;
  //int mod2;
  //int count = 0;
  printf("What is the max number you would like to check?\n");
  fgets(input, 10, stdin);
  sscanf(input, "%ld", &k);
  /*for (int j = 3; j < k; j++)
  {
    for (int i = 2; i < j; i++)
    {
      mod1 = j % i;
      mod2 = (j + 2) % i;
      if ((mod1 != 0) & (mod2 != 0))
      {
        count++;
      }
    }
    if (count == (j - 2))
    {
      printf("%d and %d are a Prime Pair\n", j, j + 2);
    }
    count = 0;
  }*/
  primePair(k);
}
