#ifndef DRAW_H
#define DRAW_H

#include <cstdio>
#include <vector>
#include "draw.cpp"

using namespace std;

void initCanvas(char* init[][600]);
void drawCanvas(char* name[][600], FILE*);
void drawLine(vector<vector<float> >, char* canvas[][600]);

#endif
