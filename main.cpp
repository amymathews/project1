/*name:Amy Mathews
    ID:5550003627*/
#include <cstring>
#include <iostream>
#include <string>
#include <iomanip>
#include "options.h"
#include "game.h"
#include "computer.h"

using namespace std;
int* heaps; 

int main(int argc, char* argv[]) 
{
  int numHeaps;
  bool isPlayerOnePlayed = false;
  string computerplayer;
  string playerOne;
  string playerTwo;
  string winnerplayer;

  option(argc,argv,playerOne, playerTwo,winnerplayer,numHeaps,
  isPlayerOnePlayed,computerplayer);
  return 0;  
}