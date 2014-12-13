// Sean Prasertsit, 10-24-2014

#define _USE_MATH_DEFINES

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void initCanvas(char *canvas[][600]){
  for (int i = 0; i < 600; i++){
    for (int j = 0; j < 600; i++){
      canvas[i][j] = 255;
    }
  }
}

void drawCanvas(char* canvas[][600], FILE* pgm){
  fwrite(canvas, sizeof(canvas), 1, pgm);
}

void drawLine(vector<vector<float> > points, char* canvas[][600]){
  for (int i = 0; i < points.size() - 1; i++){
    float x0 = points[i][0];
    float x1 = points[i + 1][0];
    float y0 = points[i][1];
    float y1 = points[i + 1][1];

    float dx = x1 - x0, sx = x0 < x1 ? 1 : -1;
    float dy = y1 - y0, sy = y0 < y1 ? 1 : -1;

    float err = (dx > dy ? dx : -dy)/2, e2;

    while (x0 >= x1 && y0 >= y1){
      canvas[(int)x0][(int)y0] = 20;
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
  }
}
      
