#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int getcharLoop(int text[], int ch)
{
  ch = getchar();
  int countText = 0; //variable that counts size of text array                                                                                                                                           
  while (ch != '\n')
  {
    //to prevent spaces, and characters which are already capital, from being shifted                                                                                                                                                                
    if (ch >= 97)
    {
      text[countText] = ch - 32; //subtracting 32 to make lowercase letters uppercase                                                                                                                
      ch = getchar();
      countText++;
    }
    else
    {
      text[countText] = ch;
      ch = getchar();
      countText++;
    }
  }
  return countText;
}

/*
int removeSpaces(int input[], int size)
{
  goes through every element in input[]
  * and removes an element if it is a space 
  *(ASCII 32).
  *Other elements in the set are shifted to fill up all indices in middle.
  *End will be left empty.

  for(int index = 0; index < size; index++)
  {
    if (input[index] == 32)
    {
      for(int loopCount = index; loopCount < size; loopCount++)
      {	
	input[loopCount] = input[loopCount + 1];
      }
      size--;
      index--;
    }
  }
  return size;
}*/


void VigenereEncrypt(int key[], int keySize, int plainText[], int textSize, int cipherText[])
{
  int loopKeyCount = 0;
  for(int loopCount = 0; loopCount < textSize; loopCount++)
  {
    if (plainText[loopCount] != 32)
    {
      //65 must be added to each element of cipherText[] to make the numbers the ASCII equivalents of the capital letters.
      cipherText[loopCount] = (((plainText[loopCount] - 65) + (key[loopKeyCount % keySize] - 65)) % 26) + 65;
      loopKeyCount++;
    }
    else
    {
      cipherText[loopCount] = plainText[loopCount];
    }
  }
}

void VigenereDecrypt(int key[], int keySize, int cipherText[], int textSize, int plainText[])
{
  int loopKeyCount = 0;
  for(int loopCount = 0; loopCount < textSize; loopCount++)
  {
    if (cipherText[loopCount] != 32)
    {
      int cipherNum = (cipherText[loopCount] - 65) - (key[loopKeyCount % keySize] - 65);
      if (cipherNum >= 0)
      {
	//65 must be added to each element of cipherText[] to make the numbers the ASCII equivalents of the capital letters.
	plainText[loopCount] = (cipherNum % 26) + 65;
      }
      else
      {
	//loop necessary to take modulo of negative number and get positive value
	while (cipherNum < 0)
	{
	  cipherNum += 26;
	}
	plainText[loopCount] = cipherNum + 65;
      }
      loopKeyCount++;
    }
    else
    {
      plainText[loopCount] = cipherText[loopCount];
    }
  }
}

int main()
{
  int ch;
  int encryptKey[25];
  printf("Enter Key (lowercase; automatically made uppercase): \n");
  ch = getchar();
  int countKey = 0; //variable that counts size of encryptKey[]
  while (ch != '\n')
  {
    encryptKey[countKey] = ch - 32;
    ch = getchar();
    countKey++;
  }
  char input[7];
  printf("Encrypt/Decrypt? ");
  ch = getchar();
  int countInput = 0;
  while (ch != '\n')
  {
    input[countInput] = ch;
    ch = getchar();
    countInput++;
  }
  if ((input[0] == 'E') | (input[0] == 'e'))
  {
    int plainText[100];
    //creating array to store encrypted message in
    int encryptedMessage[100];
    printf("\nEnter Plaintext to encrypt (lowercase): \n");
    int countText = getcharLoop(plainText, ch);
    VigenereEncrypt(encryptKey, countKey, plainText, countText, encryptedMessage);
    printf("\nEncrypted Message: \n");
    printArr(encryptedMessage, countText);
    printf("\n");
  }
  else
  {
    if ((input[0] == 'D') | (input[0] == 'd'))
    {
      int encryptedText[100];
      //creating array to store encrypted message in                                                                                                                                              
      int decryptedMessage[100];
      printf("\nEnter encrypted text to decrypt (lowercase): \n");
      int countText = getcharLoop(encryptedText, ch);
      VigenereDecrypt(encryptKey, countKey, encryptedText, countText, decryptedMessage);
      printf("\nDecrypted Message: \n");
      printArr(decryptedMessage, countText);
      printf("\n");
    }
  }
  exit(EXIT_SUCCESS);
}
