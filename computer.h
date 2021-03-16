/*name:Amy Mathews
    ID:5550003627*/
#ifndef COMPUTER_H
#define COMPUTER_H
#include <cstring>
#include <iostream>
#include <string>
#include <iomanip>
extern int* heaps;

using namespace std;

int nimSum(int& numHeaps);
void computerMove(string& winnerplayer,int& numHeaps);
void computerswitch(string& winnerplayer, string& computerplayer, bool& isPlayerOnePlayed,int& numHeaps);
void winComputer(string winnerplayer,int& numHeaps);

#endif