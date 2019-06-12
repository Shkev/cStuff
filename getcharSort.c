#include <stdio.h>
#include <stdlib.h>

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
  int i, j, min;
  for (i = 0; i < size - 1; i++)
  {
    min = i;
    for(j = i + 1; j < size; j++)
    {
      if (input[min] > input[j])
      {
        min = j;
        if (min != i)
        {
            int tmp = input[i];
            input[i] = input[min];
            input[min] = tmp;
        }
      }
    }
  }
}

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
  printf("Unsorted list:\n");
  printArr(strch, j);
  sort(strch, j);
  printf("\nSorted List:\n");
  printArr(strch, j);
  printf("\n");
  exit(EXIT_SUCCESS);
}


/* Example code:

int main(){
  int ch;
  ch = getchar();
  while(ch != 'a')
  {
   if(ch != '\n')
   printf("ch was %c, value %d\n", ch, ch);
   ch = getchar();
 }
 exit(EXIT_SUCCESS);
}
*/
