#include "game.h"
#include "draw.h"

//vector< vector<int> > virt_board(3, vector<int>(3));

void goes_first(int t){
  if(t == 1){
    cout << "X goes first" << endl;
  }else{
    cout << "O goes first" << endl;
  }
}

bool check_win(int recent_x, int recent_y){
  //Check diagonals

  //Diagonal top left to bottom right
  if((recent_x == 0 && recent_y == 1) || (recent_x == 2 && recent_y == 5) || (recent_x == 4 && recent_y == 9)){
    if(board[0][1] == board[2][5] && board[2][5] == board[4][9]){
      return true;
    }
  }

  //Diagonal top right to bottom left
  if((recent_x == 0 && recent_y == 9) || (recent_x == 2 && recent_y == 5) || (recent_x == 4 && recent_y == 1)){
    if(board[0][9] == board[2][5] && board[2][5] == board[4][1]){
      return true;
    }
  }

  //Check Up-Down
  if(board[0][recent_y] == board[2][recent_y] && board[2][recent_y] == board[4][recent_y]){
    return true;
  }

  //Check Left-Right
  if(board[recent_x][1] == board[recent_x][5] && board[recent_x][5] == board[recent_x][9]){
    return true;
  }
  return false;
}

bool out_of_bounds(int x_pos, int y_pos){
  if(x_pos < 0 || x_pos > 2 || y_pos < 0 || y_pos > 2){
    return true;
  }
  return false;
}

bool occupied(int x_pos, int y_pos){
  if(out_of_bounds(x_pos, y_pos)){
    return false;
  }
  if(board[x_pos * 2][(y_pos * 4) + 1] != " "){
    return true;
  }
  return false;
}

pair<int,int> make_move(int turn){
  //Check who's turn it is
  if(turn == 1){
    cout << "Where would 'X' like to go?" << endl;
  }else if(turn == 0){
    cout << "Where would 'O' like to go?" << endl;
  }

  //Pick a spot
  int x_position;
  int y_position;
  cin >> x_position >> y_position;

  //Check validity of spot on board
  while(out_of_bounds(x_position, y_position) || occupied(x_position, y_position)){
    //Out of Bounds
    if(out_of_bounds(x_position, y_position)){
      cout << "Please pick numbers between 0 and 2 inclusive for your x and y positions" << endl;
      cout << "Seperate the values with a space" << endl;
      cout << "Try Again" << endl;
    }

    //Occupied
    if(occupied(x_position, y_position)){
      cout << "There's already a token in that spot" << endl;
      cout << "Try Again" << endl;
    }
    cin >> x_position >> y_position;
  }
  pair<int, int> coords(x_position, y_position);

  //Mark the spot on the board
  if(turn == 1){
    draw_X(x_position, y_position);
  }else if(turn == 0){
    draw_O(x_position, y_position);
  }
  return coords;
}

void game(){
  srand(time(NULL));
  int turn = rand() % 2;
  goes_first(turn);
  draw_init();
  bool win = false;
  while(!win){

    //Make a move
    pair<int,int> coords = make_move(turn);

    //Check win condition
    win = check_win(coords.first * 2, (coords.second*4+ 1));

    //Re-print board with new tokens
    update_board();

    //Annouce if there is a winner
    if(win && turn == 1){
      cout << "@@@@@@'X' WINS THE GAME@@@@@@" << endl;
    }else if(win && turn == 0){
      cout << "@@@@@@'O' WINS THE GAME@@@@@@" << endl;
    }

    //Alternate turns
    if(turn == 1){
      turn = 0;
    }else if(turn == 0){
      turn = 1;
    }
  }
}
