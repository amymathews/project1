/*name:Amy Mathews
    ID:5550003627*/
#include <cstring>
#include <iostream>
#include <string>
#include <iomanip>
#include "game.h"
using namespace std;

void gamelogic(int p, int s, int& numHeaps)
{
  int maxHeaps = 10;
  int minHeaps = 3;
  int maxStones = 20;
  int minStones =1;
  int mini =0;

  if(p>0 && (p < minHeaps || p >  maxHeaps))
  {
    
    cout<<"bad input, violated heap terms"<<endl;
    cout<<"next time enter, at least 3 heaps and a maxiumum of 10 heaps"<<endl;
    exit(0);
  }
  if(s> 0 &&(s < minStones || s >  maxStones))
  {
    cout<<"bad input, violated stone terms"<<endl;
    cout<<"next time enter, at least 1 stone and a maxiumum of 20 stones";
    exit(0);
  }

  if(p>0 && s>0)
  {
   
    numHeaps = p;
    heaps = (int *)calloc(p, sizeof(int));
    cout << "Welcome to NIM!\n";
    for (int i = 0; i < numHeaps; i++)
    {
        heaps[i] = s;
    }

  } 
  else if(p>0 && s == 0)
  {
    numHeaps = p;
    heaps = (int *)calloc(p, sizeof(int));
    cout << "Welcome to NIM, you've entered the number of heaps to be: "<< p;
    for (int i = 0; i < numHeaps; i++)
    {
        
        heaps[i] = rand() % (maxStones + 1);
    }
  }
  
  else if(p == 0 && s>0)
  {
    
    numHeaps = rand() % (maxHeaps) +1;
    if (numHeaps < minHeaps)
    {
      numHeaps = minHeaps;
    }
    heaps = (int *)calloc(numHeaps, sizeof(int));
    cout << "Welcome to NIM!\n";
    for (int i = 0; i < numHeaps; i++)
    {
      heaps[i] = s;
    }
  }
  
  else
  {
      numHeaps = rand() % (maxHeaps) +1;
      if (numHeaps < minHeaps)
        {
        numHeaps = minHeaps;
        }
        heaps = (int *)calloc(numHeaps, sizeof(int) );
        cout << "Welcome to NIM!\n";
        for (int i = 0; i < numHeaps; i++)
        {
            heaps[i] = rand() %(maxStones + 1);
            if (heaps[i] < minStones)
            {
                heaps[i] = minStones;
            }
        }
  }
 
}

void showHeaps(int& numHeaps)
{
    for (int i = 0; i < numHeaps; i++)
    {
      if(heaps[i] == 0){continue;}
      cout <<  "Heap " << i+1 << " ["<< heaps[i] << "]:" << string(heaps[i], '*') << "\n";
    }
}

void playerMove(string& winnerplayer,string playerOne,string playerTwo,string computerplayer, int& numHeaps)
{
    string player = playerOne; 
    if(playerOne.empty() && playerTwo.empty()){player = computerplayer;}  
    else if(playerOne.empty()){player = playerTwo;}
    cout << "It is " << player << "'s turn.\n";
     int pile =0;
     int stones =1000;
    cout << "Which heap?\n";
    cin>>pile;
    while(std::cin.good()== false||pile>numHeaps|| (heaps[pile-1] == 0))
    {
      std::cin.clear();
      std::cin.ignore(INTMAX_MAX,'\n');
      cout<<"invalid heap, try again : "<<endl;
      cin>>pile;
      continue;
    }
    cout << "How many stones?\n";
    cin >> stones;
    while (std::cin.good()== false||
    (stones < 0) || (heaps[pile-1] < stones))
    {
      std::cin.clear();
      std::cin.ignore(INTMAX_MAX,'\n');
      cout<<"invalid stone number, try again :"<<endl;
      cin>>stones;
      continue;
    }
    heaps[pile-1] = heaps[pile-1] - stones;
    winnerplayer = player;  
}

void TwoPlayersSwitch(string& winnerplayer,string& playerOne,string& playerTwo,string& computerplayer, bool& isPlayerOnePlayed,int& numHeaps)
{
  cout << "Player 1: " << playerOne << "\n";
  cout << "Player 2: " << playerTwo << "\n";
  showHeaps(numHeaps);
  
    if (isPlayerOnePlayed == false)
    {
        playerMove(winnerplayer,playerOne,""," ", numHeaps);
        isPlayerOnePlayed = true;
    }
    else
    {
        playerMove(winnerplayer,"",playerTwo,"",numHeaps);
        isPlayerOnePlayed = false;
    }
        
}
void winTwoPlayers(string& winnerplayer,int& numHeaps)
{
    showHeaps(numHeaps);
    cout << "\nCongrats! You won "<< winnerplayer<<"!";
}


bool game_end(int& numHeaps)
{
  for (int i = 0; i < numHeaps; i++)
  {
    if (heaps[i] > 0)
    {
        return false;
    }
  }
  return true;
}
void setwinnerplayer(string& winnerplayer, string player)
{
  winnerplayer=player;
}