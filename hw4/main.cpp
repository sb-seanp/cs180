// Sean Prasertsit, 10-24-2025

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include "functions.h"

#define DIM 600
#define MAX_COLOR 255

using namespace std;

queue<vector<vector<float> > > polygon;
char canvas[DIM][DIM];
vector<vector<float> > pmatrix(4, vector<float>(4));

void initCanvas();
void drawCanvas(FILE*);
void drawLine(stack<vector<vector<float> > >);
void glBegin();
void glVertex3f(float, float, float);
void glEnd();
void Projection(float, float, float, float, float, float);
void drawBlock();

int main(int argc, char **argv){
  
  // Set up canvas
  initCanvas();

  //Projection(0, 300, 0, 300, 0, 300);
  setIdentity();
  glTranslatef(300, 300, -150);
  printStack();
  string image = "image";
  string ext = ".pgm";
  int r = 0;
  for (int u = 0; u < 300; u++){
    ostringstream temp;
    temp << u;
    string t = temp.str();
    string buffer = image + t + ext;
    // Open pgm
    FILE* pgm = fopen(buffer.c_str(), "wb");
    // Print header
    const char *comment = "# Sean Prasertsit, binary image";
    fprintf(pgm, "P5\n %s\n %d\n %d\n %d\n", comment, DIM, DIM, MAX_COLOR);
    glPushMatrix();
    glRotatef(r,1,0,0);
    //Scalef(.5,.5,1);
    drawBlock();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, -100, 0);
    glRotatef(-r,1,0,0);
    glScalef(1.3,1.3,1.3);
    drawBlock();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 100, 0);
    glRotatef(-r,1,0,0);
    glScalef(1.3,1.3,1.3);
    drawBlock();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 200, 0);
    glRotatef(r,1,0,0);
    glScalef(1.7,1.7,1.7);
    drawBlock();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, -200, 0);
    glRotatef(r,1,0,0);
    glScalef(1.7,1.7,1.7);
    drawBlock();
    glPopMatrix();
    drawCanvas(pgm);
    fclose(pgm);
    initCanvas();
    r += 10;
  }
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
  char black = 20;

  float x1 = origin[0][0];
  float x2 = end[0][0];
  float y1 = origin[1][0];
  float y2 = end[1][0];

 
  float x,y,dx,dy,dx1,dy1,px,py,xe,ye,i;
  dx=x2-x1;
  dy=y2-y1;
  dx1=fabs(dx);
  dy1=fabs(dy);
  px=2*dy1-dx1;
  py=2*dx1-dy1;
  if(dy1<=dx1)
    {
      if(dx>=0)
	{
	  x=x1;
	  y=y1;
	  xe=x2;
	}
      else
	{
	  x=x2;
	  y=y2;
	  xe=x1;
	}
      canvas[(int)x][(int)y] = black;
      for(i=0;x<xe;i++)
	{
	  x=x+1;
	  if(px<0)
	    {
	      px=px+2*dy1;
	    }
	  else
	    {
	      if((dx<0 && dy<0) || (dx>0 && dy>0))
		{
		  y=y+1;
		}
	      else
		{
		  y=y-1;
		}
	      px=px+2*(dy1-dx1);
	    }
	  canvas[(int)x][(int)y] = black;
	}
    }
  else
    {
      if(dy>=0)
	{
	  x=x1;
	  y=y1;
	  ye=y2;
	}
      else
	{
	  x=x2;
	  y=y2;
	  ye=y1;
	}
      canvas[(int)x][(int)y] = black;
      for(i=0;y<ye;i++)
	{
	  y=y+1;
	  if(py<=0)
	    {
	      py=py+2*dx1;
	    }
	  else
	    {
	      if((dx<0 && dy<0) || (dx>0 && dy>0))
		{
		  x=x+1;
		}
	      else
		{
		  x=x-1;
		}
	      py=py+2*(dx1-dy1);
	    }
	  canvas[(int)x][(int)y] = black;
	}
    }
}
  
void Projection(float l, float r, float b, float t, float n, float f){
  pmatrix[0][0] = (2*n)/(r - l);
  pmatrix[0][2] = (r + l)/(r - l);
  pmatrix[1][1] = (2*n)/(t - b);
  pmatrix[1][2] = (t + b)/(t - b);
  pmatrix[2][2] = -(f + n)/(f - n);
  pmatrix[2][3] = (-2*f*n)/(f - n);
  pmatrix[3][2] = -1;
}

void glBegin(){
  while (!polygon.empty())
    polygon.pop();
}
void glVertex3f(float x, float y, float z){
  vector<vector<float> > v(4, vector<float>(1));
  v[0][0] = x;
  v[1][0] = y;
  v[2][0] = z;
  v[3][0] = 1;
  polygon.push(v);
}

void glEnd(){
  vector<vector<float> > first = polygon.front();
  first = Multiply4x1(TopMatrix(), first);
  //first = Multiply4x1(pmatrix, first);
  int size = polygon.size();
  for (int s = 0; s < size - 1; s++){
    vector<vector<float> > origin = polygon.front();
    origin = Multiply4x1(TopMatrix(), origin);
    //origin = Multiply4x1(pmatrix, origin);
    polygon.pop();
    vector<vector<float> > end = polygon.front();
    end = Multiply4x1(TopMatrix(), end);
    // end = Multiply4x1(pmatrix, end);
    drawLine(origin, end);
  }
  vector<vector<float> > last = polygon.front();
  last = Multiply4x1(TopMatrix(), last);
  // last = Multiply4x1(pmatrix, last);
  drawLine(last, first);
  polygon.pop();
}

void drawBlock(){
  // Top
  glBegin();
  glVertex3f( 25, 25, 25);
  glVertex3f(-25, 25, 25);
  glVertex3f(-25, 25,-25);
  glVertex3f( 25, 25,-25);
  glEnd();

  // Front
  glBegin();
  glVertex3f( 25, 25, 25);
  glVertex3f(-25, 25, 25);
  glVertex3f(-25,-25, 25);
  glVertex3f( 25,-25, 25);
  glEnd();

  // Bottom
  glBegin();
  glVertex3f( 25,-25, 25);
  glVertex3f(-25,-25, 25);
  glVertex3f(-25,-25,-25);
  glVertex3f( 25,-25,-25);
  glEnd();

  // Back
  glBegin();
  glVertex3f( 25, 25,-25);
  glVertex3f(-25, 25,-25);
  glVertex3f(-25,-25,-25);
  glVertex3f( 25,-25,-25);
  glEnd();

  // Right
  glBegin();
  glVertex3f( 25, 25, 25);
  glVertex3f( 25, 25,-25);
  glVertex3f( 25,-25,-25);
  glVertex3f( 25,-25, 25);
  glEnd();
  
  // Left
  glBegin();
  glVertex3f( -25, 25, 25);
  glVertex3f( -25, 25,-25);
  glVertex3f( -25,-25,-25);
  glVertex3f( -25,-25, 25);
  glEnd();
}

