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

void option(int argc, char* argv[],string& playerOne,string& playerTwo, string& winnerplayer,int& numHeaps,bool isPlayerOnePlayed,string& computerplayer)
{
  if(argc <2)
      {
        free(heaps);
        gamelogic(0,0,numHeaps);
        cout << "\nFirst player name: ";
        cin >> playerOne;
        cout << "Second player name: ";
        cin >> playerTwo;
        while(!game_end(numHeaps))
        {
          TwoPlayersSwitch(winnerplayer,playerOne,playerTwo,computerplayer,isPlayerOnePlayed,numHeaps);
        }
        winTwoPlayers(winnerplayer,numHeaps);
        free(heaps);
      }
  else if(strcmp(argv[1], "-h")==0)
      {
          cout<< "Options:\n";
          cout<<"Please set the heap(-p) command before setting stone(-s) command"<<endl;
          cout << "-h   Show this text.\n";
          cout << "-c   Make player two the computer.  Default = false.\n";
          cout << "-p   Manually set the starting number of piles in the game.\n";
          cout << "-s   Manually set the starting number of stones in each pile.\n";
          cout << "        Max values for piles and stones: 20\n";
          cout << "        Min values for piles and stones: 1\n";

      }
  else if(strcmp(argv[1], "-c")==0)
    {
      if(argc == 2) 
      {  
          cout<<"You have chosen to play with the computer"<<endl;
          free(heaps);
          gamelogic(0,0,numHeaps);
          cout << "\nFirst player name: ";
          cin >> computerplayer;
          while(!game_end(numHeaps))
          {
            computerswitch(winnerplayer,computerplayer,isPlayerOnePlayed,numHeaps);
          }
            winComputer(winnerplayer,numHeaps);
            free(heaps);
      }
      else if(argc == 4)
      {
      cout<<"You have chosen to play with the computer "<<endl;
        if(strcmp(argv[2], "-p")==0)
          {
            if(atoi(argv[3])< 0||atoi(argv[3])<1|| isdigit(atoi(argv[3]) == false))
            {
              cout<<"Bad input, violated heap terms"<<endl;
              cout<<"Next time enter, at least 3 heaps or a maxiumum of 10 heaps"<<endl;
            }
            else
            {
              free(heaps);
              gamelogic(atoi(argv[3]),0,numHeaps);
              cout << "\nFirst player name: ";
              cin >> computerplayer;
              while(!game_end(numHeaps))
              {
                computerswitch(winnerplayer, computerplayer,isPlayerOnePlayed,numHeaps);
              }
              winComputer(winnerplayer,numHeaps);
            }
            free(heaps);
          }
          
      else if(strcmp(argv[2], "-s")==0)
          {
            if(atoi(argv[3])< 0||atoi(argv[3])<1|| isdigit(atoi(argv[3]) == false))
            {
              cout<<"Bad input, violated stone range"<<endl;
              cout<<"Next time enter at least 1 stone or a maxiumum of 20 stones"<<endl;
            }
            else
            {
            free(heaps);
            gamelogic(0,atoi(argv[3]),numHeaps);
            cout << "\nFirst player name: ";
            cin >> computerplayer;
            while(!game_end(numHeaps))
            {
            computerswitch(winnerplayer,computerplayer,isPlayerOnePlayed,numHeaps);
            }
            winComputer(winnerplayer,numHeaps);
            free(heaps);
          }
        }
  }
      else if(argc == 6)// for both stones and piles
      {
        if(atoi(argv[3])< 0||atoi(argv[3])<1|| isdigit(atoi(argv[3]) == false)||atoi(argv[5])< 0||atoi(argv[5])<1|| isdigit(atoi(argv[5]) == false))
            {
              cout<<"Bad input, violated heap or stone range"<<endl;
              cout<<"Next time enter, at least 3 heaps or a maxiumum of 10 heaps or at least 1 stone and a maximum of twenty stones "<<endl;
            }
            else
            {
              cout<<"You have chosen to play with the computer"<<endl;
              free(heaps);
              gamelogic(atoi(argv[3]),atoi(argv[5]),numHeaps);
              cout << "\nFirst player name: ";
              cin >> computerplayer;
              while(!game_end(numHeaps))
              {
                computerswitch(winnerplayer,computerplayer,isPlayerOnePlayed,numHeaps);
              }
                winComputer(winnerplayer,numHeaps);
              free(heaps);
            }
      }
  }  
    else if(strcmp(argv[1],"-p")== 0 && argc < 3)
    {
        free(heaps);
        gamelogic(0,0,numHeaps);
        cout << "\nFirst player name: ";
        cin >> playerOne;
        cout << "Second player name: ";
        cin >> playerTwo;
        while(!game_end(numHeaps))
        {
          TwoPlayersSwitch(winnerplayer,playerOne,playerTwo,computerplayer,isPlayerOnePlayed,numHeaps);
        }
        winTwoPlayers(winnerplayer,numHeaps);
        free(heaps); 
    }
    else if(strcmp(argv[1],"-p")== 0 && argc < 4)
    {
        if(atoi(argv[2])< 0||atoi(argv[2])<1|| isdigit(atoi(argv[2]) == false))
        {
          cout<<"Bad input, violated heap terms"<<endl;
          cout<<"Next time enter, at least 3 heaps or a maxiumum of 10 heaps"<<endl;
        }
        else
        {
        free(heaps);
        gamelogic(atoi(argv[2]),0,numHeaps);
        cout << "\nFirst player name: ";
        cin >> playerOne;
        cout << "Second player name: ";
        cin >> playerTwo;
        while(!game_end(numHeaps))
        {
          TwoPlayersSwitch(winnerplayer,playerOne,playerTwo,computerplayer,isPlayerOnePlayed,numHeaps);
        }
        winTwoPlayers(winnerplayer,numHeaps);
        free(heaps); 
        }
        
    }   

    else if((strcmp(argv[1], "-p")==0) && (strcmp(argv[3],"-s")==0)&& argc == 2)
    {
        free(heaps);
        gamelogic(0,0,numHeaps);
        cout << "\nFirst player name: ";
        cin >> playerOne;
        cout << "Second player name: ";
        cin >> playerTwo;
        while(!game_end(numHeaps))
        {
          TwoPlayersSwitch(winnerplayer,playerOne,playerTwo,computerplayer,isPlayerOnePlayed,numHeaps);
        }
        winTwoPlayers(winnerplayer,numHeaps);
        free(heaps); 
    }
    
    else if((strcmp(argv[1], "-p")==0) && (strcmp(argv[3],"-s")==0))
    {
        if(atoi(argv[2])< 0||atoi(argv[2])<1|| isdigit(atoi(argv[2]) == false)||atoi(argv[4])< 0||atoi(argv[4])<1|| isdigit(atoi(argv[4]) == false))
            {
              cout<<"Bad input, violated heap or stone range"<<endl;
              cout<<"Next time enter, at least 3 heaps or a maxiumum of 10 heaps or at least 1 stone and a maximum of twenty stones "<<endl;
            }
        else
        {
            free(heaps);
            gamelogic(atoi(argv[2]),atoi(argv[4]),numHeaps);
            cout << "\nFirst player name: ";
            cin >> playerOne;
            cout << "Second player name: ";
            cin >> playerTwo;
            while(!game_end(numHeaps))
            {
              TwoPlayersSwitch(winnerplayer,playerOne,playerTwo,computerplayer,isPlayerOnePlayed,numHeaps);
            }
            winTwoPlayers(winnerplayer,numHeaps);
            
            free(heaps);
        }
        
    }    
    else if(strcmp(argv[1],"-s")== 0 && argc < 3)
    {
        free(heaps);
        gamelogic(0,0,numHeaps);
        cout << "\nFirst player name: ";
        cin >> playerOne;
        cout << "Second player name: ";
        cin >> playerTwo;
        while(!game_end(numHeaps))
        {
          TwoPlayersSwitch(winnerplayer,playerOne,playerTwo,computerplayer,isPlayerOnePlayed,numHeaps);
        }
        winTwoPlayers(winnerplayer,numHeaps);
        free(heaps); 
    }
    else if(strcmp(argv[1], "-s")==0)
    {
        if(atoi(argv[2])< 0||atoi(argv[2])<1|| isdigit(atoi(argv[2]) == false))
        {
          cout<<"Bad input, violated stone range"<<endl;
          cout<<"Next time enter at least 1 stone or a maxiumum of 20 stones"<<endl;
        }
        else
        {
        free(heaps);
        gamelogic(0,atoi(argv[2]),numHeaps);
        cout << "\nFirst player name: ";
        cin >> playerOne;
        cout << "Second player name: ";
        cin >> playerTwo;
        while(!game_end(numHeaps))
        {
          TwoPlayersSwitch(winnerplayer,playerOne,playerTwo,computerplayer,isPlayerOnePlayed,numHeaps);
        }
        winTwoPlayers(winnerplayer,numHeaps);
       
        free(heaps);
        }
    } 
    else
    {
      cout <<"invalid input please try again ";
    }
}