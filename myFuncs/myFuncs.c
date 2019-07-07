#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "myFuncs.h"
#define TRUE     0
#define FALSE    1
//the following two definition are subject to change
#define MAXROW      3
#define MAXCOL      3

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


void smallSelecSort(int input[], int size)
{
  int i, j;
  for (i = 0; i < size - 1; i++)
  {
    for(j = i + 1; j < size; j++)
    {
      if (input[i] > input[j])
      {
        int tmp = input[i];
        input[i] = input[j];
        input[j] = tmp;
      }
    }
  }
}


void largeSelecSort(long int input[], int size)
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


float shortDist3D(float start_x, float start_y, float start_z, float end_x, float end_y, float end_z)
{
  int xdist, ydist, zdist;
  xdist = abs(start_x - end_x);
  ydist = abs(start_y - end_y);
  zdist = abs(start_z - end_z);
  int shortest_dist = xdist + ydist + zdist;
  return shortest_dist;
}


void stringCompare(char* str1, char* str2)
{
  if (strcmp(str1, str2) == 0)
  {
    printf("they are the same\n");
  }
  else
  {
    printf("they are different\n");
  }
}


float areaOfCircle(float radius)
{
  float area = M_PI * radius * radius;
  return area;
}


void arrayAdd(int* arr, int size, int num) {
  for(int i = 0; i < size; i++) {
    arr[i] = (arr[i] + num);
    printf("%d\n", arr[i]);
  }
}


void binarySwap(int binaryNum[], int size) {
  int sizeIndex = size - 1;
  for (float loopCount = 0; loopCount <= floor(size / 2); loopCount++) {
    int tmp;
    tmp = binaryNum[(int)loopCount];
    binaryNum[(int)loopCount] = binaryNum[sizeIndex - (int)loopCount];
    binaryNum[sizeIndex - (int)loopCount] = tmp;
  }
}

//matrix manipulation functions


/*r1 and c1 are number of rows and columns in first matrix
*r2 and c2 are number of rows and columns in second matrix
*/
void multMat(int r1, int c1, int r2, int c2, float x[MAXROW][MAXCOL], float y[n1][n2], float result[n1][m2])
{
  /* debugging code                                                                                                   
  printf("\ny matrix\n");                                                                                             
  printf("%f\n", y[0][0]);                                                                                            
  printf("%f\n", y[1][0]);                                                                                            
  printf("%f\n", y[2][0]); */
  float total;
  /*Multiplying two matrices*/
  for(int r = 0; r < c2; r++)
  {
    for(int s = 0; s < r1; s++)
    {
      total = 0;
      for(int t = 0; t < r2; t++)
      {
        total += x[s][t] * y[t][r];
      }
      result[r][s] = total;
    }
  }
}


void scaleMatrix(int max, float inputMatrix[][max], float outputMatrix[][max], float scalar)
{
  for (int m = 0; m < max; m++)
  {
    for (int n = 0; n < max; n++)
    {
      float k = inputMatrix[m][n];
      outputMatrix[m][n] = k * scalar;
    }
  }
}


/* r0, r1... c1, c2 are indicators which indicate whether or not a row/column is empty (all 0's)
 * if a row or column only has 0's or does not exist, the variable corresponding to that row/column
 * is set to FALSE, and if it does exist/is not only 0's, then it is set to TRUE*/

void invMatrix(float matrix[][MAXCOL], float outputMatrix[][MAXCOL], int* r0, int* r1, int* r2, int* c0, int* c1, int\
* c2, int* cont)
{
  float deter;
  if ((*c2 == FALSE) & (*r2 == FALSE))
  {
    //if matrix[][] is a 2 by 2 matrix (array)                                                                        
    float adj[2][2];
    float invMat[2][2];
    float a = matrix[0][0];
    float b = matrix[0][1];
    float c = matrix[1][0];
    float d = matrix[1][1];
    deter = (a * d) - (b * c);
    //printf("\nDeterminant: %f\n", deter);                                                                           
    if (deter == 0)
    {
      printf("\nInfinite Solutions or No Solutions\n");
    }
    else
    {
      adj[0][0] = d;
      adj[0][1] = b * (-1);
      adj[1][0] = c * (-1);
      adj[1][1] = a;
      scaleMatrix(2, adj, invMat, (1 / deter));
      for (int m = 0; m < 2; m++)
      {
        for (int n = 0; n < 2; n++)
        {
          float arg = invMat[m][n];
          outputMatrix[m][n] = arg;
        }
      }
      //printf("%f %f \n", outputMatrix[0][0], outputMatrix[0][1]);                                                   
      //printf("%f %f \n", outputMatrix[1][0], outputMatrix[1][1]);                                                   
    }
  }
  else
  {
    if ((*c2 == TRUE) & (*r2 == TRUE))
    {
      //if matrix[][] is a 3 by 3 matrix (array)                                                                      
      float adj[3][3];
      float invMat[3][3];
      float matMinor[3][3];
      float a, b, c, d, e, f, g, h, i;
      a = matrix[0][0]; b = matrix[0][1]; c = matrix[0][2];
      d = matrix[1][0]; e = matrix[1][1]; f = matrix[1][2];
      g = matrix[2][0]; h = matrix[2][1]; i = matrix[2][2];
      //creating matrix of minors                                                                                     
      matMinor[0][0] = (e * i) - (f * h);
      matMinor[0][1] = (d * i) - (g * f);
      matMinor[0][2] = (d * h) - (g * e);
      matMinor[1][0] = (b * i) - (h * c);
      matMinor[1][1] = (a * i) - (g * c);
      matMinor[1][2] = (a * h) - (b * g);
      matMinor[2][0] = (b * f) - (e * c);
      matMinor[2][1] = (a * f) - (d * c);
      matMinor[2][2] = (a * e) - (b * d);
      /* Debugging code                                                                                               
      printf("\nMatrix of Minors\n");                                                                                 
      printf("%f %f %f\n", matMinor[0][0], matMinor[0][1], matMinor[0][2]);                                           
      printf("%f %f %f\n", matMinor[1][0], matMinor[1][1], matMinor[1][2]);                                           
      printf("%f %f %f\n", matMinor[2][0], matMinor[2][1], matMinor[2][2]); */
      float matCoFact[3][3];
      int var = 0;
      for (int m = 0; m < MAXROW; m++)
      {
        for (int n = 0; n < MAXCOL; n++)
        {
          if ((var % 2) == 0)
          {
            matCoFact[m][n] = matMinor[m][n];
          }
          else
          {
            float val = matMinor[m][n];
            matCoFact[m][n] = -1 * val;
          }
          var++;
        }
      }
      /* Debugging Code                                                                                               
      printf("\nMatrix of Cofactors\n");                                                                              
      printf("%f %f %f\n", matCoFact[0][0], matCoFact[0][1], matCoFact[0][2]);                                        
      printf("%f %f %f\n", matCoFact[1][0], matCoFact[1][1], matCoFact[1][2]);                                        
      printf("%f %f %f\n", matCoFact[2][0], matCoFact[2][1], matCoFact[2][2]); */
      //code to transpose matrix of cofactors to adjugate                                                             
      adj[0][0] = matCoFact[0][0];
      adj[0][1] = matCoFact[1][0];
      adj[0][2] = matCoFact[2][0];
      adj[1][0] = matCoFact[0][1];
      adj[1][1] = matCoFact[1][1];
      adj[1][2] = matCoFact[2][1];
      adj[2][0] = matCoFact[0][2];
      adj[2][1] = matCoFact[1][2];
      adj[2][2] = matCoFact[2][2];
      deter = (matCoFact[0][0] * a) + (matCoFact[0][1] * b) + (matCoFact[0][2] * c);
      //printf("Determinant: %f\n", deter);                                                                           
      if (deter == 0)
      {
        printf("Infinite Solutions or No Solutions\n");
        *cont = FALSE;
      }
      else
      {
        scaleMatrix(3, adj, invMat, (1 / deter));
        /* Debugging code                                                                                             
        printf("\nInverse Matrix\n");                                                                                 
        printf("%f %f %f\n", invMat[0][0], invMat[0][1], invMat[0][2]);                                               
        printf("%f %f %f\n", invMat[1][0], invMat[1][1], invMat[1][2]);                                               
        printf("%f %f %f\n", invMat[2][0], invMat[2][1], invMat[2][2]); */
        //using loop to copy invMat into outputMatrix
	for (int m = 0; m < 3; m++)
        {
          for (int n = 0; n < 3; n++)
          {
            float arg = invMat[m][n];
           outputMatrix[m][n] = arg;
          }
        }
      }
    }
  }
}


