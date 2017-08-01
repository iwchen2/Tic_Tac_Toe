#ifndef DRAW_H
#define DRAW_H

#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

extern vector< vector<string> > board;

void draw_init();
void update_board();
void draw_X(int x_pos, int y_pos);
void draw_O(int x_pos, int y_pos);

#endif
