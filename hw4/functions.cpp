// Sean Prasertsit, 10-24-2014

#define _USE_MATH_DEFINES

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <stack>
#include <vector>

using namespace std;

vector<vector<float> > mymatrix(4, vector<float>(4));

stack<vector<vector<float> > > mystack;

void PushMatrix(){
  vector<vector<float> > copy = mystack.top();
  mystack.push(copy);
}

void PopMatrix(){
  mystack.pop();
}

void Rotatef(float angle, float x, float y, float z){
  vector<vector<float> > matrix = mystack.top();

  float a = angle*M_PI/180.0;
  float s = sin(a);
  float c = cos(a);
  float t = 1.0 - c;
	
  float tx = t * x;
  float ty = t * y;
  float tz = t * z;
	
  float sz = s * z;
  float sy = s * y;
  float sx = s * x;
	
  matrix[0][0]  = tx * x + c;
  matrix[0][1]  = tx * y + sz;
  matrix[0][2]  = tx * z - sy;
  //matrix[0][3]  = 0;

  matrix[1][0]  = tx * y - sz;
  matrix[1][1]  = ty * y + c;
  matrix[1][2]  = ty * z + sx;
  //matrix[1][3]  = 0;

  matrix[2][0]  = tx * z + sy;
  matrix[2][1]  = ty * z - sx;
  matrix[2][2] = tz * z + c;
  //matrix[2][3] = 0;

  matrix[3][0] = 0;
  matrix[3][1] = 0; 
  matrix[3][2] = 0;
  //matrix[3][3] = 1; 
	
  mystack.pop();
  mystack.push(matrix);
}

void Translatef(float x, float y, float z){
  vector<vector<float> > matrix = mystack.top();
	
  matrix[0][3] += matrix[0][0]*x + matrix[0][1]*y + matrix[0][2]*z;
  matrix[1][3] += matrix[1][0]*x + matrix[1][1]*y + matrix[1][2]*z;
  matrix[2][3] += matrix[2][0]*x + matrix[2][1]*y + matrix[2][2]*z;
  matrix[3][3] += matrix[3][0]*x + matrix[3][1]*y + matrix[3][2]*z;
	
  mystack.pop();
  mystack.push(matrix);
}

void Scalef(float x, float y, float z){
  vector<vector<float> > matrix = mystack.top();
	
  matrix[0][0] *= x; 
  matrix[1][1] *= y;
  matrix[2][2] *= z;
	
  mystack.pop();
  mystack.push(matrix);
}

void setIdentity(){
  for (int i = 0; i < 4; i++)
    mymatrix[i][i] = 1;
  mystack.push(mymatrix);
}

vector<vector<float> > Multiply4x4(vector<vector<float> > a, vector<vector<float> > b){
  vector<vector<float> > result(4, vector<float>(4));
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      result[i][j] = 0;
      for (int k = 0; k < 4; k++){
	result[i][j] = result[i][j] + a[i][k]*b[k][j];
      }
    }
  }
  return result;
}

vector<vector<float> > Multiply4x1(vector<vector<float> > a, vector<vector<float> > b){
  vector<vector<float> > result(4, vector<float>(1));
  for (int i = 0; i < 4; i++){
    int j = 0;
    result[i][j] = 0;
    for (int k = 0; k < 4; k++){
      result[i][j] = result[i][j] + a[i][k]*b[k][j];
    }
  }
  result[4][0] = 1;
  return result;
}

void printStack(){
  vector<vector<float> > matrix = mystack.top();
	
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++)
      cout << matrix[i][j] << " ";
    cout << endl;
  }
  cout << endl;
}

void printVector(vector<vector<float> > point){
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 1; j++)
      cout << point[i][j] << " ";
    cout << endl;
  }
  cout << endl;
}

void printMatrix(vector<vector<float > > matrix){
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++)
      cout << matrix[i][j] << " ";
    cout << endl;
  }
  cout << endl;
}

/*FILE* openFile(char* input){
  const int dimx = 600, dimy = 600;
  const int MaxColor = 255;
  FILE* pgm = fopen(input, "wb");
  const char *comment = "# Sean Prasertsit, binary image";
  // Print header
  fprintf(pgm, "P5\n %s\n %d\n %d\n %d\n", comment, dimx, dimy, MaxColor);

  char data[dimx][dimy];
  int i, j;
  
  for (i = 0; i < dimx; ++i) {
    for (j = 0; j < dimy; ++j) {
      data[i][j] = (i + j) & 255;
    }
  }
  fwrite(data, sizeof(data), 1, pgm);
  cout << sizeof(pgm);
  fclose(pgm);*/
