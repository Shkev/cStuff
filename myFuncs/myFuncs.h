//Function that prints all items in an array
void printArr(int arr[], int size);

/*copies the values in one array (arr1[]) to
*second array (arr2[]). Values in first array
*are not modified*/
void arrcpy(int arr1[], int arr2[], int size);

/*Function that sorts all items in the input array
*from smallest to largest
*and stores sorted values in input array using selection sort
*/
void smallSelecSort(int input[], int size);

//sorts array from largest to smallest and stores in inputted array using selection sort
void largeSelecSort(int input[], int size);

//returns the largers of two values
int max(int num1, int num2);
//finds all prime pairs between 3 and a max value
void primePair(long int max_val);

//returns shortest non diagonal distance between two points in three dimensional plane
float shortDist3D(float start_x, float start_y, float start_z, float end_x, float end_y, float end_z);

//compares two strings and outputs text to report whether they are the same or not
void stringCompare(char* str1, char* str2);

//returns area of circle with given radius
float areaOfCircle(float radius);

//add a constant value to each value in an array
void arrayAdd(int* arr, int size, int num);

//add all the values in an array together and returns that value
int sumArray(int arr[], int size);

/*finds sum of values in array from index start to end
* arr is the array that is being accessed,
* start is the starting index and end is the ending index
*/
int arr_sum(int arr[], int start, int end);

/* Swaps the bits of a binary digit
 *through the use of an array of character digits.
 *ex: Input: 10110010
 *Output: 01010101*/
void binarySwapWithArray(int binaryNum[], int size);

/* Swaps the bits of a binary digit
 *by shifting the bits and using bitwise operators
 *ex: Input: 10110010
 *Output: 01010101*/
int binarySwapWithShift(int num, int bits);

/*creates a substring of the input string.
*The substring starts on index 'start' of
*string and has a length of 'length'*/
void substr(char string[], char substring[], int start, int length);

/*
determines is a given string is a palindrome
*/

int isPalindrome(char* s);


/*converts a given number, num, to base b,
*and stores it as a string in s.
*/

void baseChange(char* s, int num, int b);

/* determines if arr contains val. len is the length of the array */
int arr_contains(int arr[], int len, int val);

/* finds the minimum value in an array
* arr is the array being searched and len is its length
*/
int arr_min(int arr[], int len);

/* Recursively finds the greatest common divisor
 * of two numbers, a and b.
*/  
  int gcd(int a, int b);
  
/*functions to deal with multidimensional arrays (matrices)*/

//multiplies two matrices
/*r1 and c1 are number of rows and columns in first matrix
*r2 and c2 are number of rows and columns in second matrix
*x and y are being multiplied, and result is the result of the operation.
*/
void multMat(int r1, int c1, int r2, int c2, float x[MAXROW][MAXCOL], float y[c1][c2], float result[c1][r2]);

/*
 *scales a matrix by a scalar value
 *max is maximum number if elements in rows and columns in the matrix.
 *scalar is the value the values in the matrix are being scaled by.
 */
void scaleMatrix(int max, float inputMatrix[][max], float outputMatrix[][max], float scalar);

//finds the inverse of the inputted matrix given the dimensions of the matrix
/* r0, r1... c1, c2 are indicators which indicate whether or not a row/column is empty (all 0's)
 * if a row or column only has 0's or does not exist, the variable corresponding to that row/column
 * is set to FALSE, and if it does exist/is not only 0's, then it is set to TRUE
 *cont tells the program whether or not to continue.
 */
void invMatrix(float matrix[][MAXCOL], float outputMatrix[][MAXCOL], int* r0, int* r1, int* r2, int* c0, int* c1, int\
* c2, int* cont);
