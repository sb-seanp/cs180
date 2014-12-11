// Sean Prasertsit, 10-24-2014

#include <GL/glut.h>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <stack>
#include <vector>

using namespace std;

void init(){
  // Enable depth, lighting, position the light, and change materials
  GLfloat light_position[] = { 0.0, 10.0, -25.0, 1.0 };
  glEnable(GL_DEPTH_TEST);
  glShadeModel(GL_SMOOTH);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_COLOR_MATERIAL);
}

GLuint loadTexture(const char* filename) {
  //GLuint texture;
  char header[54];
  int width, height;
  int dataPos;
  int imageSize;
  char* data;
  FILE* file;
  file = fopen(filename, "rb");
  if (fread(header, 1, 54, file) != 54){
    cout << "Not bmp\n";
    return false;
  }
  if (header[0] != 'B' || header[1] != 'M'){
    cout << "Not bmp\n";
    return 0;
  }

  dataPos = *(int*)&(header[0x0A]);
  imageSize = *(int*)&(header[0x22]);
  width = *(int*)&(header[0x12]);
  height = *(int*)&(header[0x16]);

  if (imageSize == 0) imageSize = width*height*3;
  if (dataPos == 0) dataPos = 54;

  data = new char [imageSize];
  fread(data, 1, imageSize, file);
  fclose(file);

  /* for (int i = 0; i < width*height; i++){
    int index = i*3;
    char B, R;
    B = data[index];
    R = data[index + 2];
    data[index] = R;
    data[index + 2] = B;
    }*/
  
  GLuint textureID;
  glGenTextures(1, &textureID);
  glBindTexture(GL_TEXTURE_2D, textureID);
  glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  free( data );

  return textureID;
}

// Draw white square background
void drawBackground(){
  glBegin(GL_POLYGON);
  glNormal3f(0,0,1);
  glVertex3f( 100, 100, -40);
  glVertex3f(-100, 100, -40);
  glVertex3f(-100,-100, -40);
  glVertex3f( 100,-100, -40);
  glEnd();
}

// Draw single eave
void drawEave(){
  glColor3ub(0,0,255);
	
  // Top
  glBegin(GL_POLYGON);
  glNormal3f(0,1,0);
  glVertex3f( 2.8, 2.8, 2.2);
  glVertex3f(-2.8, 2.8, 2.2);
  glVertex3f(-2.8, 2.8, 2.8);
  glVertex3f( 2.8, 2.8, 2.8);
  glEnd();
  
  // Bottom
  glBegin(GL_POLYGON);
  glNormal3f(0,-1,0);
  glVertex3f( 2.8, 2.2, 2.2);
  glVertex3f(-2.8, 2.2, 2.2);
  glVertex3f(-2.8, 2.2, 2.8);
  glVertex3f( 2.8, 2.2, 2.8);
  glEnd();
  
  // Back
  glBegin(GL_POLYGON);
  glNormal3f(0,0,-1);
  glVertex3f( 2.8, 2.8, 2.2);
  glVertex3f(-2.8, 2.8, 2.2);
  glVertex3f(-2.8, 2.2, 2.2);
  glVertex3f( 2.8, 2.2, 2.2);
  glEnd();
  
  // Front
  glBegin(GL_POLYGON);
  glNormal3f(0,0,1);
  glVertex3f( 2.8, 2.8, 2.8);
  glVertex3f(-2.8, 2.8, 2.8);
  glVertex3f(-2.8, 2.2, 2.8);
  glVertex3f( 2.8, 2.2, 2.8);
  glEnd();
  
  // Left
  glBegin(GL_POLYGON);
  glNormal3f(-1,0,0);
  glVertex3f(-2.8, 2.8, 2.2);
  glVertex3f(-2.8, 2.8, 2.8);
  glVertex3f(-2.8, 2.2, 2.8);
  glVertex3f(-2.8, 2.2, 2.2);
  glEnd();
  
  // Right
  glBegin(GL_POLYGON);
  glNormal3f(1,0,0);
  glVertex3f( 2.8, 2.8, 2.8);
  glVertex3f( 2.8, 2.8, 2.2);
  glVertex3f( 2.8, 2.2, 2.2);
  glVertex3f( 2.8, 2.2, 2.8);
  glEnd();
  
}

// Draw triangular prism
void drawTriPrism(){
  glColor3ub(0,255,0);
  
  // Front
  glBegin(GL_POLYGON);
  glNormal3f(0,0,1);
  glVertex3f(   0, 1.0, 3.0);
  glVertex3f(-1.5,-1.0, 3.0);
  glVertex3f( 1.5,-1.0, 3.0);
  glEnd();
  
  // Back
  glBegin(GL_POLYGON);
  glNormal3f(0,0,-1);
  glVertex3f(   0, 1.0, 2.5);
  glVertex3f(-1.5,-1.0, 2.5);
  glVertex3f( 1.5,-1.0, 2.5);
  glEnd();
  
  // Right
  glBegin(GL_POLYGON);
  glVertex3f(   0, 1.0, 2.5);
  glVertex3f(   0, 1.0, 3.0);
  glVertex3f( 1.5,-1.0, 3.0);
  glVertex3f(	1.5,-1.0, 2.5);
  glEnd();
  
  // Left
  glBegin(GL_POLYGON);
  glVertex3f(   0, 1.0, 2.5);
  glVertex3f(   0, 1.0, 3.0);
  glVertex3f(-1.5,-1.0, 3.0);
  glVertex3f(-1.5,-1.0, 2.5);
  glEnd();
  
  // Bottom
  glBegin(GL_POLYGON);
  glNormal3f(0,-1,0);
  glVertex3f( 1.5,-1.0, 2.5);
  glVertex3f(-1.5,-1.0, 2.5);
  glVertex3f(-1.5,-1.0, 3.0);
  glVertex3f( 1.5,-1.0, 3.0);
  glEnd();
}

// Draw single rectangle for plus sign
void drawPlusRect(){
  // Top
  glBegin(GL_POLYGON);
  glNormal3f(0,1,0);
  glVertex3f( 0.2, 1.0, 2.5);
  glVertex3f(-0.2, 1.0, 2.5);
  glVertex3f(-0.2, 1.0, 3.0);
  glVertex3f( 0.2, 1.0, 3.0);
  glEnd();
  
  // Bottom
  glBegin(GL_POLYGON);
  glNormal3f(0,1,0);
  glVertex3f( 0.2,-1.0, 3.0);
  glVertex3f(-0.2,-1.0, 3.0);
  glVertex3f(-0.2,-1.0, 2.5);
  glVertex3f( 0.2,-1.0, 2.5);
  glEnd();
  
  // Back
  glBegin(GL_POLYGON);
  glNormal3f(0,0,-1);
  glVertex3f( 0.2, 1.0, 2.5);
  glVertex3f(-0.2, 1.0, 2.5);
  glVertex3f(-0.2,-1.0, 2.5);
  glVertex3f( 0.2,-1.0, 2.5);
  glEnd();
  
  // Front
  glBegin(GL_POLYGON);
  glNormal3f(0,0,1);
  glVertex3f( 0.2, 1.0, 3.0);
  glVertex3f(-0.2, 1.0, 3.0);
  glVertex3f(-0.2,-1.0, 3.0);
  glVertex3f( 0.2,-1.0, 3.0);
  glEnd();
  
  // Left
  glBegin(GL_POLYGON);
  glNormal3f(-1,0,0);
  glVertex3f(-0.2, 1.0, 3.0);
  glVertex3f(-0.2, 1.0, 2.5);
  glVertex3f(-0.2,-1.0, 2.5);
  glVertex3f(-0.2,-1.0, 3.0);
  glEnd();
  
  // Right
  glBegin(GL_POLYGON);
  glNormal3f(1,0,0);
  glVertex3f( 0.2, 1.0, 3.0);
  glVertex3f( 0.2, 1.0, 2.5);
  glVertex3f( 0.2,-1.0, 2.5);
  glVertex3f( 0.2,-1.0, 3.0);
  glEnd();
}

// Draw plus sign
void drawPlus(){
  glColor3ub(75,75,0);
  
  drawPlusRect();
  
  glPushMatrix();
  glRotatef(90,0.0f,0.0f,1.0f);
  glScalef(0.5f,1.0f,1.0f);
  drawPlusRect();
  glPopMatrix();
}

void drawBlock(){
  glEnable(GL_TEXTURE_2D);
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
  GLuint texture = loadTexture("./wood.bmp");
  glBindTexture(GL_TEXTURE_2D, texture);

  // Top
  glBegin(GL_POLYGON);
  glNormal3f(0,1,0);
  glTexCoord2f(0.0,0.0);
  glVertex3f( 2.5, 2.5, 2.5);
  glTexCoord2f(0.0,1.0);
  glVertex3f(-2.5, 2.5, 2.5);
  glTexCoord2f(1.0,1.0);
  glVertex3f(-2.5, 2.5,-2.5);
  glTexCoord2f(1.0,0.0);
  glVertex3f( 2.5, 2.5,-2.5);
  glEnd();

  // Front
  glBegin(GL_POLYGON);
  glNormal3f(0,0,1);
  glTexCoord2f(0.0,0.0);
  glVertex3f( 2.5, 2.5, 2.5);
  glTexCoord2f(0.0,1.0);
  glVertex3f(-2.5, 2.5, 2.5);
  glTexCoord2f(1.0,1.0);
  glVertex3f(-2.5,-2.5, 2.5);
  glTexCoord2f(1.0,0.0);
  glVertex3f( 2.5,-2.5, 2.5);
  glEnd();

  // Bottom
  glBegin(GL_POLYGON);
  glNormal3f(0,-1,0);
  glTexCoord2f(0.0,0.0);
  glVertex3f( 2.5,-2.5, 2.5);
  glTexCoord2f(0.0,1.0);
  glVertex3f(-2.5,-2.5, 2.5);
  glTexCoord2f(1.0,1.0);
  glVertex3f(-2.5,-2.5,-2.5);
  glTexCoord2f(1.0,0.0);
  glVertex3f( 2.5,-2.5,-2.5);
  glEnd();

  // Back
  glBegin(GL_POLYGON);
  glNormal3f(0,0,-1);
  glTexCoord2f(0.0,0.0);
  glVertex3f( 2.5, 2.5,-2.5);
  glTexCoord2f(0.0,1.0);
  glVertex3f(-2.5, 2.5,-2.5);
  glTexCoord2f(1.0,1.0);
  glVertex3f(-2.5,-2.5,-2.5);
  glTexCoord2f(1.0,0.0);
  glVertex3f( 2.5,-2.5,-2.5);
  glEnd();

  // Right
  glBegin(GL_POLYGON);
  glNormal3f(1,0,0);
  glTexCoord2f(0.0,0.0);
  glVertex3f( 2.5, 2.5, 2.5);
  glTexCoord2f(0.0,1.0);
  glVertex3f( 2.5, 2.5,-2.5);
  glTexCoord2f(1.0,1.0);
  glVertex3f( 2.5,-2.5,-2.5);
  glTexCoord2f(1.0,0.0);
  glVertex3f( 2.5,-2.5, 2.5);
  glEnd();
  
  // Left
  glBegin(GL_POLYGON);
  glNormal3f(-1,0,0);
  glTexCoord2f(0.0,0.0);
  glVertex3f( -2.5, 2.5, 2.5);
  glTexCoord2f(0.0,1.0);
  glVertex3f( -2.5, 2.5,-2.5);
  glTexCoord2f(1.0,1.0);
  glVertex3f( -2.5,-2.5,-2.5);
  glTexCoord2f(1.0,0.0);
  glVertex3f( -2.5,-2.5, 2.5);
  glEnd();

  glDisable(GL_TEXTURE_2D);
  
  // Draw triangular prisms on faces
  drawPlus();
  
  glPushMatrix();
  glRotatef(90, 0.0f, 1.0f, 0.0f);
  drawTriPrism();
  glPopMatrix();
  
  glPushMatrix();
  glRotatef(-90, 0.0f, 1.0f, 0.0f);
  drawTriPrism();
  glPopMatrix();
  
  glPushMatrix();
  glRotatef(180, 0.0f, 1.0f, 0.0f);
  drawTriPrism();
  glPopMatrix();
  
  glPushMatrix();
  glRotatef(90, 1.0f, 0.0f, 0.0f);
  drawTriPrism();
  glPopMatrix();
  
  glPushMatrix();
  glRotatef(-90, 1.0f, 0.0f, 0.0f);
  drawPlus();
  glPopMatrix();
  
  // Draw eaves
  drawEave();
  
  glPushMatrix();
  glRotatef(90, 0.0f, 1.0f, 0.0f);
  drawEave();
  glPopMatrix();
  
  glPushMatrix();
  glRotatef(-90, 0.0f, 1.0f, 0.0f);
  drawEave();
  glPopMatrix();
  
  glPushMatrix();
  glRotatef(180, 0.0f, 1.0f, 0.0f);
  drawEave();
  glPopMatrix();
  
  glPushMatrix();
  glRotatef(90, 1.0f, 0.0f, 0.0f);
  drawEave();
  glPopMatrix();
  
  glPushMatrix();
  glRotatef(-90, 1.0f, 0.0f, 0.0f);
  drawEave();
  glPopMatrix();
  
  glPushMatrix();
  glRotatef(180, 1.0f, 0.0f, 0.0f);
  drawEave();
  glPopMatrix();
  
  glPushMatrix();
  glRotatef(90, 0.0f, 1.0f, 0.0f);
  glRotatef(90, 0.0f, 0.0f, 1.0f);
  drawEave();
  glPopMatrix();
  
  glPushMatrix();
  glRotatef(90, 0.0f, 1.0f, 0.0f);
  glRotatef(-90, 0.0f, 0.0f, 1.0f);
  drawEave();
  glPopMatrix();
  
  glPushMatrix();
  glRotatef(90, 0.0f, 1.0f, 0.0f);
  glRotatef(180, 0.0f, 0.0f, 1.0f);
  drawEave();
  glPopMatrix();
  
  glPushMatrix();
  glRotatef(90, 0.0f, 1.0f, 0.0f);
  glRotatef(180, 1.0f, 0.0f, 0.0f);
  drawEave();
  glPopMatrix();
  
  glPushMatrix();
  glRotatef(90, 0.0f, 0.0f, 1.0f);
  glRotatef(-90, 1.0f, 0.0f, 0.0f);
  drawEave();
  glPopMatrix();
  
  glPushMatrix();
  glRotatef(90, 0.0f, 0.0f, 1.0f);
  glRotatef(180, 1.0f, 0.0f, 0.0f);
  drawEave();
  glPopMatrix();
  
  glPushMatrix();
  glRotatef(90, 0.0f, 0.0f, 1.0f);
  drawEave();
  glPopMatrix();

  glFlush();
}

// Draw single rectangle for numbers
void drawRect(){
  // Top
  glBegin(GL_POLYGON);
  glNormal3f(0,1,0);
  glVertex3f( 0.5, 2.5,-0.5);
  glVertex3f(-0.5, 2.5,-0.5);
  glVertex3f(-0.5, 2.5, 0.5);
  glVertex3f( 0.5, 2.5, 0.5);
  glEnd();
  
  // Bottom
  glBegin(GL_POLYGON);
  glNormal3f(0,-1,0);
  glVertex3f( 0.5,-2.5,-0.5);
  glVertex3f(-0.5,-2.5,-0.5);
  glVertex3f(-0.5,-2.5, 0.5);
  glVertex3f( 0.5,-2.5, 0.5);
  glEnd();
  
  // Back
  glBegin(GL_POLYGON);
  glNormal3f(0,0,-1);
  glVertex3f( 0.5, 2.5,-0.5);
  glVertex3f(-0.5, 2.5,-0.5);
  glVertex3f(-0.5,-2.5,-0.5);
  glVertex3f( 0.5,-2.5,-0.5);
  glEnd();
  
  // Front
  glBegin(GL_POLYGON);
  glNormal3f(0,0,1);
  glVertex3f( 0.5, 2.5, 0.5);
  glVertex3f(-0.5, 2.5, 0.5);
  glVertex3f(-0.5,-2.5, 0.5);
  glVertex3f( 0.5,-2.5, 0.5);
  glEnd();
  
  // Left
  glBegin(GL_POLYGON);
  glNormal3f(-1,0,0);
  glVertex3f( 0.5, 2.5, 0.5);
  glVertex3f( 0.5, 2.5,-0.5);
  glVertex3f( 0.5,-2.5,-0.5);
  glVertex3f( 0.5,-2.5, 0.5);
  glEnd();
  
  // Right
  glBegin(GL_POLYGON);
  glNormal3f(1,0,0);
  glVertex3f(-0.5, 2.5, 0.5);
  glVertex3f(-0.5, 2.5,-0.5);
  glVertex3f(-0.5,-2.5,-0.5);
  glVertex3f(-0.5,-2.5, 0.5);
  glEnd();
}

// Draw numbers
void drawNumber(int num){
  glPushMatrix();
  glTranslatef(0,0,10);
  if (num == 1){
    glColor3ub(255,0,0);
    drawRect();
  }
  if (num == 2){
    glColor3ub(0,155,0);
    
    glPushMatrix();
    glTranslatef(1.0,1.0,0);
    glScalef(1.0f,0.5f,1.0f);
    drawRect();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-1.0,-1,0);
    glScalef(1.0f,0.5f,1.0f);
    drawRect();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,2,0);
    glRotatef(90,0.0f,0.0f,1.0f);
    glScalef(1.0f,0.5f,1.0f);
    drawRect();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,-0,0);
    glRotatef(90,0.0f,0.0f,1.0f);
    glScalef(1.0f,0.5f,1.0f);
    drawRect();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,-2,0);
    glRotatef(90,0.0f,0.0f,1.0f);
    glScalef(1.0f,0.5f,1.0f);
    drawRect();
    glPopMatrix();
  }
  if (num == 3){
    glColor3ub(0,0,155);
    
    glPushMatrix();
    glTranslatef(1.0,0,0);
    drawRect();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,2,0);
    glRotatef(90,0.0f,0.0f,1.0f);
    glScalef(1.0f,0.5f,1.0f);
    drawRect();
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(90,0.0f,0.0f,1.0f);
    glScalef(1.0f,0.5f,1.0f);
    drawRect();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,-2,0);
    glRotatef(90,0.0f,0.0f,1.0f);
    glScalef(1.0f,0.5f,1.0f);
    drawRect();
    glPopMatrix();
  }
  if (num == 4){
    glColor3ub(155,155,0);
    
    glPushMatrix();
    glTranslatef(1.0,0,0);
    drawRect();
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(90,0.0f,0.0f,1.0f);
    glScalef(1.0f,0.5f,1.0f);
    drawRect();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-1.0,1,0);
    glScalef(1.0f,0.5f,1.0f);
    drawRect();
    glPopMatrix();
  }
  if (num == 5){
    glColor3ub(155,0,155);
    
    glPushMatrix();
    glTranslatef(-1.0,1,0);
    glScalef(1.0f,0.5f,1.0f);
    drawRect();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(1.0,-1,0);
    glScalef(1.0f,0.5f,1.0f);
    drawRect();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,2,0);
    glRotatef(90,0.0f,0.0f,1.0f);
    glScalef(1.0f,0.5f,1.0f);
    drawRect();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,-0,0);
    glRotatef(90,0.0f,0.0f,1.0f);
    glScalef(1.0f,0.5f,1.0f);
    drawRect();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,-2,0);
    glRotatef(90,0.0f,0.0f,1.0f);
    glScalef(1.0f,0.5f,1.0f);
    drawRect();
    glPopMatrix();
  }
  if (num == 6){
    glColor3ub(0,155,155);
    
    glPushMatrix();
    glTranslatef(-1.0,0,0);
    drawRect();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(1.0,-1.25,0);
    glScalef(1.0f,0.5f,1.0f);
    drawRect();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,2,0);
    glRotatef(90,0.0f,0.0f,1.0f);
    glScalef(1.0f,0.5f,1.0f);
    drawRect();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,0,0);
    glRotatef(90,0.0f,0.0f,1.0f);
    glScalef(1.0f,0.5f,1.0f);
    drawRect();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,-2,0);
    glRotatef(90,0.0f,0.0f,1.0f);
    glScalef(1.0f,0.5f,1.0f);
    drawRect();
    glPopMatrix();
  }
  if (num == 7){
    glColor3ub(155,0,0);
    
    glPushMatrix();
    glTranslatef(1.5,0,0);
    drawRect();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,2,0);
    glRotatef(-90,0.0f,0.0f,1.0f);
    glScalef(1.0f,0.5f,1.0f);
    drawRect();
    glPopMatrix();
  }
  if (num == 8){
    glColor3ub(155,155,155);
    
    glPushMatrix();
    glTranslatef(-1.0,0,0);
    drawRect();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(1.0,0,0);
    drawRect();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,2,0);
    glRotatef(90,0.0f,0.0f,1.0f);
    glScalef(1.0f,0.5f,1.0f);
    drawRect();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,0,0);
    glRotatef(90,0.0f,0.0f,1.0f);
    glScalef(1.0f,0.5f,1.0f);
    drawRect();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,-2,0);
    glRotatef(90,0.0f,0.0f,1.0f);
    glScalef(1.0f,0.5f,1.0f);
    drawRect();
    glPopMatrix();
  }
  if (num == 9){
    glColor3ub(0,75,155);
    
    glPushMatrix();
    glTranslatef(1.0,0,0);
    drawRect();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,2,0);
    glRotatef(90,0.0f,0.0f,1.0f);
    glScalef(1.0f,0.5f,1.0f);
    drawRect();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,0,0);
    glRotatef(90,0.0f,0.0f,1.0f);
    glScalef(1.0f,0.5f,1.0f);
    drawRect();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-1.0,1,0);
    glScalef(1.0f,0.5f,1.0f);
    drawRect();
    glPopMatrix();
  }
  
  glPopMatrix();
}

// Animate and draw numbers to screen
void drawNumbers(int value){
	static float numZ = 0;
  static float rightX = 0;
  static float leftX = 0;
  
	if (value <= 9){
		if (value%2 != 0){
			glPushMatrix();
			glTranslatef(leftX,0,numZ);
			drawNumber(value);
			glPopMatrix();
		}
		else{
			glPushMatrix();
			glTranslatef(rightX,0,numZ);
			drawNumber(value);
			glPopMatrix();
		}
  }
  numZ += .06;
  rightX -= .04;
  leftX += .04;
  glutPostRedisplay();
}

void drawNumbers2(int value){
	static float numZ = 0;
  static float rightX = 0;
  static float leftX = 0;
  
	if (value <= 9){
		if (value%2 != 0){
			glPushMatrix();
			glTranslatef(leftX,0,numZ);
			drawNumber(value);
			glPopMatrix();
		}
		else{
			glPushMatrix();
			glTranslatef(rightX,0,numZ);
			drawNumber(value);
			glPopMatrix();
		}
  }
  numZ += .06;
  rightX -= .04;
  leftX += .04;
  glutPostRedisplay();
}

void drawNumbers3(int value){
	static float numZ = 0;
  static float rightX = 0;
  static float leftX = 0;
  
	if (value <= 9){
		if (value%2 != 0){
			glPushMatrix();
			glTranslatef(leftX,0,numZ);
			drawNumber(value);
			glPopMatrix();
		}
		else{
			glPushMatrix();
			glTranslatef(rightX,0,numZ);
			drawNumber(value);
			glPopMatrix();
		}
  }
  numZ += .06;
  rightX -= .04;
  leftX += .04;
  glutPostRedisplay();
}

void drawNumbers4(int value){
	static float numZ = 0;
  static float rightX = 0;
  static float leftX = 0;
  
	if (value <= 9){
		if (value%2 != 0){
			glPushMatrix();
			glTranslatef(leftX,0,numZ);
			drawNumber(value);
			glPopMatrix();
		}
		else{
			glPushMatrix();
			glTranslatef(rightX,0,numZ);
			drawNumber(value);
			glPopMatrix();
		}
  }
  numZ += .06;
  rightX -= .04;
  leftX += .04;
  glutPostRedisplay();
}

void drawNumbers5(int value){
	static float numZ = 0;
  static float rightX = 0;
  static float leftX = 0;
  
	if (value <= 9){
		if (value%2 != 0){
			glPushMatrix();
			glTranslatef(leftX,0,numZ);
			drawNumber(value);
			glPopMatrix();
		}
		else{
			glPushMatrix();
			glTranslatef(rightX,0,numZ);
			drawNumber(value);
			glPopMatrix();
		}
  }
  numZ += .06;
  rightX -= .04;
  leftX += .04;
  glutPostRedisplay();
}

void drawNumbers6(int value){
	static float numZ = 0;
  static float rightX = 0;
  static float leftX = 0;
  
	if (value <= 9){
		if (value%2 != 0){
			glPushMatrix();
			glTranslatef(leftX,0,numZ);
			drawNumber(value);
			glPopMatrix();
		}
		else{
			glPushMatrix();
			glTranslatef(rightX,0,numZ);
			drawNumber(value);
			glPopMatrix();
		}
  }
  numZ += .06;
  rightX -= .04;
  leftX += .04;
  glutPostRedisplay();
}

void drawNumbers7(int value){
	static float numZ = 0;
  static float rightX = 0;
  static float leftX = 0;
  
	if (value <= 9){
		if (value%2 != 0){
			glPushMatrix();
			glTranslatef(leftX,0,numZ);
			drawNumber(value);
			glPopMatrix();
		}
		else{
			glPushMatrix();
			glTranslatef(rightX,0,numZ);
			drawNumber(value);
			glPopMatrix();
		}
  }
  numZ += .06;
  rightX -= .04;
  leftX += .04;
  glutPostRedisplay();
}

void drawNumbers8(int value){
	static float numZ = 0;
  static float rightX = 0;
  static float leftX = 0;
  
	if (value <= 9){
		if (value%2 != 0){
			glPushMatrix();
			glTranslatef(leftX,0,numZ);
			drawNumber(value);
			glPopMatrix();
		}
		else{
			glPushMatrix();
			glTranslatef(rightX,0,numZ);
			drawNumber(value);
			glPopMatrix();
		}
  }
  numZ += .06;
  rightX -= .04;
  leftX += .04;
  glutPostRedisplay();
}

void drawNumbers9(int value){
	static float numZ = 0;
  static float rightX = 0;
  static float leftX = 0;
  
	if (value <= 9){
		if (value%2 != 0){
			glPushMatrix();
			glTranslatef(leftX,0,numZ);
			drawNumber(value);
			glPopMatrix();
		}
		else{
			glPushMatrix();
			glTranslatef(rightX,0,numZ);
			drawNumber(value);
			glPopMatrix();
		}
  }
  numZ += .06;
  rightX -= .04;
  leftX += .04;
  glutPostRedisplay();
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  GLint viewport[4];
  glGetIntegerv(GL_VIEWPORT, viewport);
  double aspect = (double)viewport[2] / (double)viewport[3];
  gluPerspective(60, aspect, 1, 100);
  
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  
  static float alpha = 0;
  static float beta = 0;
  static float timer = 0;
  
  // Move into the screen a bit
  glTranslatef( 0, 0, -30 );
  
  // Start drawing the 5 blocks
  glPushMatrix();
  glTranslatef(0,-10,-20);
  glColor3ub(255,0,255);
  glRotatef(alpha,0.0f,1.0f,0.0f);
  drawBlock();
  glPopMatrix();
  
  glPushMatrix();
  glTranslatef(5,-10,-10);
  glColor3ub(255,0,255);
  glRotatef(beta,0.0f,1.0f,0.0f);
  drawBlock();
  glPopMatrix();
  
  glPushMatrix();
  glTranslatef(10,-10,0);
  glColor3ub(255,0,255);
  glRotatef(alpha,0.0f,1.0f,0.0f);
  drawBlock();
  glPopMatrix();
  
  glPushMatrix();
  glTranslatef(-5,-10,-10);
  glColor3ub(255,0,255);
  glRotatef(beta,0.0f,1.0f,0.0f);
  drawBlock();
  glPopMatrix();
  
  glPushMatrix();
  glTranslatef(-10,-10,0);
  glColor3ub(255,0,255);
  glRotatef(alpha,0.0f,1.0f,0.0f);
  drawBlock();
  glPopMatrix();
  
  // Start drawing numbers 1-4 behind the left-most block
  glPushMatrix(); 
  glTranslatef(-10,-10,-18);
  
  // Set timer for every MainLoop
  drawNumbers(1);
  if (timer > 800){
    drawNumbers3(3);
  }
  if (timer > 1600){
    drawNumbers5(5);
  }
  if (timer > 2400){
    drawNumbers7(7);
	}
  if (timer > 3200){
    drawNumbers9(9);
  }
  glPopMatrix();
	
  // Start drawing numbers 5-9 behind the right-most block

  glPushMatrix();
  glTranslatef(10,-10,-18);
  
  if (timer > 400){
    drawNumbers2(2);
  }
  if (timer > 1200){
    drawNumbers4(4);
  }
  if (timer > 2000){
    drawNumbers6(6);
  }
  if (timer > 2800){
    drawNumbers8(8);
  }
  glPopMatrix();

  // Initiate white background polygon
  glColor3ub(255,255,255);
  drawBackground();

  // Draw a horizontal one
  glColor3ub(255,255,255);
  glPushMatrix();
  glRotatef(-90,1.0f,0.0f,0.0f);
  glTranslatef(0.0,-12,0.0);
  drawBackground();
  glPopMatrix();
  
  glutSwapBuffers();
  
  alpha += .3;
  beta -= .3;
  timer += 1;

  glutPostRedisplay();
}

// Set viewport
void reshape(int w, int h){
  glViewport(0, 0, w, h);
}

int main(int argc, char **argv){
  glutInit(&argc, argv);
  glutInitWindowSize(640,480);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
  glutCreateWindow("Brainy Baby");
    
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  
  init();
  
  glutMainLoop();
  glDisable(GL_TEXTURE_2D);
  return 0;
}
