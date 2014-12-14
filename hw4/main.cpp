// Sean Prasertsit, 10-24-2014

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include "functions.h"

#define DIM 300
#define MAX_COLOR 255

using namespace std;

queue<vector<vector<float> > > polygon;
char canvas[DIM][DIM];
vector<vector<float> > pmatrix(4, vector<float>(4));

void initCanvas();
void drawCanvas(FILE*);
void drawLine(stack<vector<vector<float> > >);
void clearPolygon();
void vertex(float, float, float);
void drawPolygon();
void Projection(float, float, float, float, float, float);

int main(int argc, char **argv){
  // Open pgm
  FILE* pgm = fopen("image1.pgm", "wb");
  // Print header
  const char *comment = "# Sean Prasertsit, binary image";
  fprintf(pgm, "P5\n %s\n %d\n %d\n %d\n", comment, DIM, DIM, MAX_COLOR);
  // Set up canvas
  initCanvas();

  Projection(0, 300, 300, 0, 0, 100);
  setIdentity();
  Translatef(150, 150, 0);
  printStack();

  clearPolygon();
  vertex(50,50,0);
  vertex(50,80,0);
  vertex(80,80,0);
  vertex(80,50,0);
  cout << polygon.size() << endl;
  drawPolygon();
  /*setIdentity();
  vector<vector<float> > point(4, vector<float>(1,2));
  point[3][0] = 1;
  setIdentity();
  printStack();
  Scalef(1,2,1);
  printStack();
  vector<vector<float> > result = Multiply4x1(mystack.top(), point);
  printVector(result);*/

  drawCanvas(pgm);
  fclose(pgm);
  return 0;
}

void initCanvas(){
  char white = 255;
  for (int i = 0; i < DIM; i++){
    for (int j = 0; j < DIM; j++){
      canvas[i][j] = white;
    }
  }
}

void drawCanvas(FILE* pgm){
  fwrite(canvas, sizeof(canvas), 1, pgm);
}

void drawLine(vector<vector<float> > origin, vector<vector<float> > end){
  float x0 = origin[0][0];
  float x1 = end[0][0];
  float y0 = origin[1][0];
  float y1 = end[1][0];

  float dx = x1 - x0, sx = x0 < x1 ? 1 : -1;
  float dy = y1 - y0, sy = y0 < y1 ? 1 : -1;

  float err = (dx > dy ? dx : -dy)/2, e2;

  char black = 20;
  while (x0 <= x1 && y0 <= y1){
    canvas[(int)x0][(int)y0] = black;
    e2 = err;
    if (e2 > -dx){
      err -= dy;
      x0 += sx;
    }
    if (e2 < dy){
      err += dx;
      y0 += sy;
    }
  }
  cout << "running" << endl;
}

void Projection(float l, float r, float b, float t, float n, float f){
  pmatrix[0][0] = 2/(r - l);
  pmatrix[0][3] = -(r + l)/(r - l);
  pmatrix[1][1] = 2/(t - b);
  pmatrix[1][3] = -(t + b)/(t - b);
  pmatrix[2][2] = -2/(f - n);
  pmatrix[2][3] = -(f + n)/(f - n);
  pmatrix[3][3] = 1;
}

void clearPolygon(){
  while (!polygon.empty())
    polygon.pop();
}
void vertex(float x, float y, float z){
  vector<vector<float> > v(4, vector<float>(1));
  v[0][0] = x;
  v[1][0] = y;
  v[2][0] = z;
  polygon.push(v);
}

void drawPolygon(){
  vector<vector<float> > first = polygon.front();
  polygon.pop();
  vector<vector<float> > second = polygon.front();
  polygon.pop();
  vector<vector<float> > third = polygon.front();
  polygon.pop();
  vector<vector<float> > fourth = polygon.front();
  polygon.pop();
  printVector(first);
  printVector(second);
  printVector(third);
  printVector(fourth);
  drawLine(first, second);
  drawLine(second, third);
  drawLine(fourth,third);
  drawLine(first, fourth);
  /* int size = polygon.size();
  for (int s = 0; s < size - 1; s++){
    vector<vector<float> > origin = polygon.top();
    polygon.pop();
    vector<vector<float> > end = polygon.top();
    drawLine(origin, end);
    cout << "loop ";
  }
  vector<vector<float> > last = polygon.top();
  drawLine(last, first);
  polygon.pop();*/
}
