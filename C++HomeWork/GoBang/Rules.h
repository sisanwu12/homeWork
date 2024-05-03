#pragma once
#include <iostream>
#include "Board.h"
#include "Player.h"
#include "Piece.h"
#include "Count.h"
using namespace std;

// 判赢函数
int IsWin(vector<Piece>& count,bool BorW);
// 三手可交换
void IsThridSwap(Board* board, Player* black, Player* white,Count* count);
// 五手两打
void IsFifth(Board* board);
