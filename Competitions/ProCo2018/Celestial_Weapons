#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//prints inputted array into output file
void printArr(int arr[], int size, FILE* output)
{
  for (int i = 0; i < size; i++)
  {
    fprintf(output, "%d ", arr[i]);
  }
}

//sorts array from largest to smallest and stores in inputted array
void selecSort(long int input[], int size)
{
  int i, j;
  for (i = 0; i < size - 1; i++)
  {
    for(j = i + 1; j < size; j++)
    {
      if (input[i] < input[j])
      {
        int tmp = input[i];
        input[i] = input[j];
        input[j] = tmp;
      }
    }
  }
}

void buyWeapons(signed int bought[], int n, long int x[n], long int p[n])
{
  for (int i = 0; i < n; i++)
  {
    int k = 0;
    while (x[i] == x[i])
    {
      if (x[i] >= p[k])
      {
        bought[i] = p[k];
        p[k] = 1 * pow(10, 10);
        break;
      }
      else
      {
        if (k == (n - 1))
        {
          bought[i] = -1;
          break;
        }
      }
      k++;
    }
  }
}

int main()
{
  clock_t begin = clock();
  FILE* input;
  FILE* output;
  input = fopen("standard input", "r");
  output = fopen("standard output", "w");
  int n;
  fscanf(input, "%d", &n);
  long int p[n];
  long int x[n];
  //to read all inputs in input file
  for (int i = 0; i < 2 * n; i++)
  {
    int j = i % n;
    if (i < n)
    {
      fscanf(input, "%ld", &x[j]);
    }
    else
    {
      fscanf(input, "%ld", &p[j]);
    }
  }
  selecSort(p, n);
  signed int somethingBought[n];
  buyWeapons(somethingBought, n, x, p);
  printArr(somethingBought, n, output);
  fclose(input);
  fclose(output);
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("time = %f sec", time_spent);
  exit(EXIT_SUCCESS);
}
