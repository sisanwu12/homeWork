#pragma once
#include <iostream>
#include "Board.h"
#include "Player.h"
#include "Piece.h"
#include "Count.h"
using namespace std;

// 判赢函数
bool IsWin(vector<Piece>& count);

// 三手可交换
void IsThridSwap(Board* board, Player* black, Player* white,Count* count);

// 五手两打
void IsFifth(Board* board);

// 三三禁手
bool IsThreeThree(Board* board);

//四四禁手
bool IsFourFour(Board* board);

//长连禁手
bool IsLongSequential(Board* board);