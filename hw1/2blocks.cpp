#include <GL/glut.h>
#include <cstdlib>

void init()
{
  glEnable(GL_DEPTH_TEST);
  glShadeModel(GL_FLAT);
}

void drawBackground(){
	glBegin(GL_POLYGON);
	glVertex3f( 100, 100, -40);
	glVertex3f(-100, 100, -40);
	glVertex3f(-100,-100, -40);
	glVertex3f( 100,-100, -40);
	glEnd();
}

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
  
  // Start a bit back
  glTranslatef( 0, 0, -35 );
  
  glPushMatrix();
  glTranslatef(0,-10,-20);
  glColor3ub(255,0,255);
  drawBlock();
  glPopMatrix();
  
  glPushMatrix();
  glTranslatef(5,-10,-10);
  glColor3ub(255,0,255);
  drawBlock();
  glPopMatrix();
  
  glPushMatrix();
  glTranslatef(10,-10,0);
  glColor3ub(255,0,255);
	drawBlock();
  glPopMatrix();
  
  glPushMatrix();
  glTranslatef(-5,-10,-10);
  glColor3ub(255,0,255);
  drawBlock();
  glPopMatrix();
  
  glPushMatrix();
  glTranslatef(-10,-10,0);
  glColor3ub(255,0,255);
  drawBlock();
  glPopMatrix();
  
  glPushMatrix();
  glTranslatef(-10,-10,-18);
  for (int i = 1; i < 5; i++){
  	drawNumber(i);
  }
  glPopMatrix();
  
  glPushMatrix();
  glTranslatef(10,-10,-18);
  for (int i = 5; i < 10; i++){
  	drawNumber(i);
  }
  glPopMatrix();
  
  glColor3ub(255,255,255);
  drawBackground();
  
  glutSwapBuffers();
}

void reshape(int w, int h)
{
  glViewport(0, 0, w, h);
}

int main(int argc, char **argv)
{
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
