#include "draw.h"
#include "game.h"


int main(){
  cout << "Would you like to play a game of Tic-Tac-Toe?(Y or N)" << endl;
  string reply;
  cin >> reply;

  while(reply == "Y"){
    game();
    cout << "Would you like to play again?(Y or N)" << endl;
    cin >> reply;
  }
  cout << "Thank You for playing a game created by Ivan Chen Coding, Inc." << endl;
}
