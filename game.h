/*name:Amy Mathews
    ID:5550003627*/
#ifndef GAME_H
#define GAME_H
#include <cstring>
#include <iostream>
#include <string>
#include <iomanip>
extern int* heaps;
using namespace std;

void gamelogic(int p, int s, int& numHeaps);
void showHeaps(int& numHeaps);
void playerMove(string& winnerplayer,string playerOne,string playerTwo,string computerplayer, int& numHeaps);
void TwoPlayersSwitch(string& winnerplayer,string& playerOne,string& playerTwo,string& computerplayer, bool& isPlayerOnePlayed,int& numHeaps);
void winTwoPlayers(string& winnerplayer,int& numHeaps);
bool game_end(int& numHeaps);
void setwinnerplayer(string& winnerplayer, string player);

#endif