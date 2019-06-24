#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  clock_t begin = clock();
  FILE* input;
  FILE* output;
  input = fopen("standard input", "r");
  output = fopen("standard output", "w");
  unsigned int dimension;
  int x1, y1, z1, x2, y2, z2;
  fscanf(input, "%d \n %d %d %d \n %d %d %d", &dimension, &x1, &y1, &z1, &x2, &y2, &z2);
  int xdist, ydist, zdist;
  xdist = abs(x1 - x2);
  ydist = abs(y1 - y2);
  zdist = abs(z1 - z2);
  int shortest_dist = xdist + ydist + zdist;
  fprintf(output, "%d\n", shortest_dist);
  fclose(input);
  fclose(output);
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  /*long double total_mem = sizeof(input) + sizeof(output) + sizeof(dimension) + sizeof(x1) + sizeof(y1) + sizeof(z1) + sizeof(x2) + sizeof(y2) + sizeof(z2) + sizeof(xdist) + sizeof(ydist) + sizeof(zdist) + sizeof(shortest_dist);
  total_mem *= 0.000001;
  printf("total memory usage = %Lf MB\n", total_mem);*/
  printf("time = %f sec", time_spent);
  exit(EXIT_SUCCESS);
}
