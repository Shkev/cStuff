#include <stdio.h>
#include <stdlib.h>

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
  for (int i = 0; i < (j + 1); i++)
  {
    printf("%c", strch[i]);
    if (i == j)
    {
      printf("\n");
    }
  }
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
