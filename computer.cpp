/*name:Amy Mathews
    ID:5550003627*/
#include <cstring>
#include <iostream>
#include <string>
#include <iomanip>
#include "game.h"
#include "computer.h"
#include "options.h"
using namespace std;

int nimSum(int& numHeaps)
{
    int nim = 0;
    for (int i = 0; i < numHeaps; i++)
    {
        nim = nim ^ heaps[i];
    }
    return nim;
}
void computerMove(string& winnerplayer,int& numHeaps)
{
    int nim = nimSum(numHeaps);
    int i = 0;
    if (nim == 0)
    {
        while (heaps[i] == 0)
        {
            i++;
        }
        cout << "\n Computer took 1 stone from the heap # "<< i+1 << ".\n";
        heaps[i]--;
    }
    else
    {
        while(((heaps[i] ^ nim) >= heaps[i]) && (i < numHeaps))
        {
            i++;
        }
        cout << "\n Computer took "<< heaps[i] - (heaps[i] ^ nim) << " stones from the heap # "<< i+1 << ".\n\n";
        heaps[i] = (heaps[i] ^ nim);
    }
    winnerplayer = "computer ";
}

void computerswitch(string& winnerplayer, string& computerplayer, bool& isPlayerOnePlayed,int& numHeaps)        
{ 
  cout << "Player 1: " << computerplayer << "\n";
  cout << "Player 2: Computer\n";
  showHeaps(numHeaps);
  if (isPlayerOnePlayed == false)
  {
      playerMove(winnerplayer,"","",computerplayer,numHeaps);
      isPlayerOnePlayed = true;
  }
  else
  {
        computerMove(winnerplayer,numHeaps);
        isPlayerOnePlayed = false;

  }        
}

void winComputer(string winnerplayer,int& numHeaps)
{
    showHeaps(numHeaps);
    cout << "\nCongrats " << winnerplayer<<"!"<< "You won "<<"!";
}