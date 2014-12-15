#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include "functions.cpp"

void glPushMatrix();
vector<vector<float> > TopMatrix();
void glPopMatrix();

void glRotatef(float, float, float, float);
void glTranslatef(float, float, float);
void glScalef(float, float, float);
void setIdentity();
vector<vector<float> > Multiply4x4(vector<vector<float> >, vector<vector<float> >);
vector<vector<float> > Multiply4x1(vector<vector<float> >, vector<float>);
vector<vector<float> > Multiply1x1(vector<vector<float> >, vector<vector<float> >);

void printStack();
void printVector(vector<vector<float> >);
void printMatrix(vector<vector<float> >);

#endif
