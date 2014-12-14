#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include "functions.cpp"

void PushMatrix();
void PopMatrix();

void Rotatef(float, float, float, float);
void Translatef(float, float, float);
void Scalef(float, float, float);
void setIdentity();
vector<vector<float> > Multiply4x4(vector<vector<float> >, vector<vector<float> >);
vector<vector<float> > Multiply4x1(vector<vector<float> >, vector<vector<float> >);

void printStack();
void printVector(vector<vector<float> >);
void printMatrix(vector<vector<float> >);

#endif
