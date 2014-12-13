// Sean Prasertsit, 10-24-2014

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <stack>
#include <vector>
#include "functions.h"
#include "draw.h"

using namespace std;

int main(int argc, char **argv){
  // Open pgm
  const int dimx = 600, dimy = 600;
  const int MaxColor = 255;
  FILE* pgm = fopen("image1.pgm", "wb");
  // Print header
  const char *comment = "# Sean Prasertsit, binary image";
  fprintf(pgm, "P5\n %s\n %d\n %d\n %d\n", comment, dimx, dimy, MaxColor);
  // Set up canvas
  char* canvas[dimx][dimy];
  initCanvas(canvas);

  setIdentity();
  vector<vector<float> > point(4, vector<float>(1,2));
  point[3][0] = 1;
  setIdentity();
  printStack();
  Scalef(1,2,1);
  printStack();
  vector<vector<float> > result = Multiply4x1(mystack.top(), point);
  printVector(result);

  fclose(pgm);
  return 0;
}
