//Function that prints all items in an array
void printArr();

/*copies the values in one array (arr1[]) to
*second array (arr2[]). Values in first array
*are not modified*/
void arrcpy();

/*Function that sorts all items in the input array
*from smallest to largest
*and stores sorted values in input array using selection sort
*/
void smallSelecSort();

//sorts array from largest to smallest and stores in inputted array using selection sort
void largeSelecSort();

//returns the largers of two values
int max();

//finds all prime pairs between 3 and a max value
void primePair();

//returns shortest non diagonal distance between two points in three dimensional plane
float shortDist3D();

//compares two strings and outputs text to report whether they are the same or not
void stringCompare();

//returns area of circle with given radius
float areaOfCircle();

//add a constant value to each value in an array
void arrayAdd();

//add all the values in an array together and returns that value
int sumArray();

/* Swaps the bits of a binary digit
 *through the use of an array of character digits.
 *ex: Input: 10110010
 *Output: 01010101*/
void binarySwapWithArray();

/* Swaps the bits of a binary digit
 *by shifting the bits and using bitwise operators
 *ex: Input: 10110010
 *Output: 01010101*/
int binarySwapWithShift();

/*creates a substring of the input string.
*The substring starts on index 'start' of
*string and has a length of 'length'*/
void substr();

/*functions to deal with multidimensional arrays (matrices)*/

//multiplies two matrices
void multMat();

//scales a matrix by a scalar value
void scaleMatrix();

//finds the inverse of the inputted matrix given the dimensions of the matrix
void invMatrix();
