#include "draw.h"

vector< vector<string> > board(5,vector<string> (11));

void draw_init(){
  string space = " ";
  string vert = "|";
  string line = "-";

  for(size_t x = 0 ; x < board.size(); x++){
    for(size_t y = 0; y < board[0].size(); y++){
      if(x % 2 == 1){
        board[x][y] = line;
      }else if(y == 3 || y == 7){
        board[x][y] = vert;
      }else{
        board[x][y] = space;
      }
      cout << board[x][y];
    }
    cout << endl;
  }
}

void draw_X(int x_pos, int y_pos){
  string tok = "X";
  board[x_pos*2][(y_pos*4) + 1] = tok;
}

void draw_O(int x_pos, int y_pos){
  string tok = "O";
  board[x_pos*2][(y_pos*4) + 1] = tok;
}

void update_board(){
  cout << "                     " << endl;
  for(size_t x = 0 ; x < board.size(); x++){
    for(size_t y = 0; y < board[0].size(); y++){
      cout << board[x][y];
    }
    cout << endl;
  }
}
