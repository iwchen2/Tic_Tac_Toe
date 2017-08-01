#ifndef GAME_H
#define GAME_H

#include <vector>
#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;


//extern vector< vector<int> > virt_board;
void out_of_bounds();
bool check_win(int recent_x, int recent_y);
void goes_first(int t);
void game();

#endif
