// Sean Prasertsit, 10-24-2014

#include <GL/glut.h>
#include <cstdlib>

using namespace std;

void init(){
  glEnable(GL_DEPTH_TEST);
  glShadeModel(GL_FLAT);
  /*glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  GLfloat lightpos[] = {0.5,1.,1.,0.};
  glLightfv(GL_LIGHT0, GL_POSITION, lightpos);*/
}

// Draw white square background
void drawBackground(){
  glBegin(GL_POLYGON);
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
  glVertex3f( 2.8, 2.8, 2.2);
  glVertex3f(-2.8, 2.8, 2.2);
  glVertex3f(-2.8, 2.8, 2.8);
  glVertex3f( 2.8, 2.8, 2.8);
  glEnd();
  
  // Bottom
  glBegin(GL_POLYGON);
  glVertex3f( 2.8, 2.2, 2.2);
  glVertex3f(-2.8, 2.2, 2.2);
  glVertex3f(-2.8, 2.2, 2.8);
  glVertex3f( 2.8, 2.2, 2.8);
  glEnd();
  
  // Back
  glBegin(GL_POLYGON);
  glVertex3f( 2.8, 2.8, 2.2);
  glVertex3f(-2.8, 2.8, 2.2);
  glVertex3f(-2.8, 2.2, 2.2);
  glVertex3f( 2.8, 2.2, 2.2);
  glEnd();
  
  // Front
  glBegin(GL_POLYGON);
  glVertex3f( 2.8, 2.8, 2.8);
  glVertex3f(-2.8, 2.8, 2.8);
  glVertex3f(-2.8, 2.2, 2.8);
  glVertex3f( 2.8, 2.2, 2.8);
  glEnd();
  
  // Left
  glBegin(GL_POLYGON);
  glVertex3f(-2.8, 2.8, 2.2);
  glVertex3f(-2.8, 2.8, 2.8);
  glVertex3f(-2.8, 2.2, 2.8);
  glVertex3f(-2.8, 2.2, 2.2);
  glEnd();
  
  // Right
  glBegin(GL_POLYGON);
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
  glVertex3f(   0, 1.0, 3.0);
  glVertex3f(-1.5,-1.0, 3.0);
  glVertex3f( 1.5,-1.0, 3.0);
  glEnd();
  
  // Back
  glBegin(GL_POLYGON);
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
  glVertex3f( 0.2, 1.0, 2.5);
  glVertex3f(-0.2, 1.0, 2.5);
  glVertex3f(-0.2, 1.0, 3.0);
  glVertex3f( 0.2, 1.0, 3.0);
  glEnd();
  
  // Bottom
  glBegin(GL_POLYGON);
  glVertex3f( 0.2,-1.0, 3.0);
  glVertex3f(-0.2,-1.0, 3.0);
  glVertex3f(-0.2,-1.0, 2.5);
  glVertex3f( 0.2,-1.0, 2.5);
  glEnd();
  
  // Back
  glBegin(GL_POLYGON);
  glVertex3f( 0.2, 1.0, 2.5);
  glVertex3f(-0.2, 1.0, 2.5);
  glVertex3f(-0.2,-1.0, 2.5);
  glVertex3f( 0.2,-1.0, 2.5);
  glEnd();
  
  // Front
  glBegin(GL_POLYGON);
  glVertex3f( 0.2, 1.0, 3.0);
  glVertex3f(-0.2, 1.0, 3.0);
  glVertex3f(-0.2,-1.0, 3.0);
  glVertex3f( 0.2,-1.0, 3.0);
  glEnd();
  
  // Left
  glBegin(GL_POLYGON);
  glVertex3f(-0.2, 1.0, 3.0);
  glVertex3f(-0.2, 1.0, 2.5);
  glVertex3f(-0.2,-1.0, 2.5);
  glVertex3f(-0.2,-1.0, 3.0);
  glEnd();
  
  // Right
  glBegin(GL_POLYGON);
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

  // Top
  glBegin(GL_POLYGON);
  glVertex3f( 2.5, 2.5, 2.5);
  glVertex3f(-2.5, 2.5, 2.5);
  glVertex3f(-2.5, 2.5,-2.5);
  glVertex3f( 2.5, 2.5,-2.5);
  glEnd();

  // Front
  glBegin(GL_POLYGON);
  glVertex3f( 2.5, 2.5, 2.5);
  glVertex3f(-2.5, 2.5, 2.5);
  glVertex3f(-2.5,-2.5, 2.5);
  glVertex3f( 2.5,-2.5, 2.5);
  glEnd();

  // Bottom
  glBegin(GL_POLYGON);
  glVertex3f( 2.5,-2.5, 2.5);
  glVertex3f(-2.5,-2.5, 2.5);
  glVertex3f(-2.5,-2.5,-2.5);
  glVertex3f( 2.5,-2.5,-2.5);
  glEnd();

  // Back
  glBegin(GL_POLYGON);
  glVertex3f( 2.5, 2.5,-2.5);
  glVertex3f(-2.5, 2.5,-2.5);
  glVertex3f(-2.5,-2.5,-2.5);
  glVertex3f( 2.5,-2.5,-2.5);
  glEnd();

  // Right
  glBegin(GL_POLYGON);
  glVertex3f( 2.5, 2.5, 2.5);
  glVertex3f( 2.5, 2.5,-2.5);
  glVertex3f( 2.5,-2.5,-2.5);
  glVertex3f( 2.5,-2.5, 2.5);
  glEnd();
  
  // Left
  glBegin(GL_POLYGON);
  glVertex3f( -2.5, 2.5, 2.5);
  glVertex3f( -2.5, 2.5,-2.5);
  glVertex3f( -2.5,-2.5,-2.5);
  glVertex3f( -2.5,-2.5, 2.5);
  glEnd();
  
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
  glVertex3f( 0.5, 2.5,-0.5);
  glVertex3f(-0.5, 2.5,-0.5);
  glVertex3f(-0.5, 2.5, 0.5);
  glVertex3f( 0.5, 2.5, 0.5);
  glEnd();
  
  // Bottom
  glBegin(GL_POLYGON);
  glVertex3f( 0.5,-2.5,-0.5);
  glVertex3f(-0.5,-2.5,-0.5);
  glVertex3f(-0.5,-2.5, 0.5);
  glVertex3f( 0.5,-2.5, 0.5);
  glEnd();
  
  // Back
  glBegin(GL_POLYGON);
  glVertex3f( 0.5, 2.5,-0.5);
  glVertex3f(-0.5, 2.5,-0.5);
  glVertex3f(-0.5,-2.5,-0.5);
  glVertex3f( 0.5,-2.5,-0.5);
  glEnd();
  
  // Front
  glBegin(GL_POLYGON);
  glVertex3f( 0.5, 2.5, 0.5);
  glVertex3f(-0.5, 2.5, 0.5);
  glVertex3f(-0.5,-2.5, 0.5);
  glVertex3f( 0.5,-2.5, 0.5);
  glEnd();
  
  // Left
  glBegin(GL_POLYGON);
  glVertex3f( 0.5, 2.5, 0.5);
  glVertex3f( 0.5, 2.5,-0.5);
  glVertex3f( 0.5,-2.5,-0.5);
  glVertex3f( 0.5,-2.5, 0.5);
  glEnd();
  
  // Right
  glBegin(GL_POLYGON);
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
  static float numZ = 0;
  static float rightX = 0;
  static float leftX = 0;
  
  // Move into the screen a bit
  glTranslatef( 0, 0, -35 );
  
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
  // stacked
  glPushMatrix(); 
  glTranslatef(-10,-10,-14);
  
  glPushMatrix();
  glTranslatef(leftX,0,numZ);
  drawNumber(1);
  glPopMatrix();
  
  glPushMatrix();
  glTranslatef(leftX,0,numZ);
  drawNumber(2);
  glPopMatrix();
  
  glPushMatrix();
  glTranslatef(leftX,0,numZ);
  drawNumber(3);
  glPopMatrix();
  
  glPushMatrix();
  glTranslatef(leftX,0,numZ);
  drawNumber(4);
  glPopMatrix();
  
  glPopMatrix();
  
  // Start drawing numbers 5-9 behind the right-most block
  // stacked
  glPushMatrix();
  glTranslatef(10,-10,-14);
  
  glPushMatrix();
  glTranslatef(rightX,0,numZ);
  drawNumber(5);
  glPopMatrix();
  
  glPushMatrix();
  glTranslatef(rightX,0,numZ);
  drawNumber(6);
  glPopMatrix();
  
  glPushMatrix();
  glTranslatef(rightX,0,numZ);
  drawNumber(7);
  glPopMatrix();
  
  glPushMatrix();
  glTranslatef(rightX,0,numZ);
  drawNumber(8);
  glPopMatrix();
  
  glPushMatrix();
  glTranslatef(rightX,0,numZ);
  drawNumber(9);
  glPopMatrix();
  
  glPopMatrix();
  
  // Initiate white background polygon
  glColor3ub(255,255,255);
  drawBackground();
  
  glutSwapBuffers();
  
  alpha += .3;
  beta -= .3;
  numZ += .03;
  rightX -= .03;
  leftX += .03; 
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
  return 0;
}
