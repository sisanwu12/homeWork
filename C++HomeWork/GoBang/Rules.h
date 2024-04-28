#pragma once
#include <iostream>
#include "Board.h"
#include "Piece.h"
#include "Count.h"
using namespace std;

// 判赢函数
bool IsWin(Board* board, vector<Piece>& count);

// 黑子入天元
bool IsCelestial(Board* board);

// 三手可交换
bool IsThridSwap(Board* board);

// 五手两打
bool IsFifth(Board* board);

// 三三禁手
bool IsThreeThree(Board* board);

//四四禁手
bool IsFourFour(Board* board);

//长连禁手
bool IsLongSequential(Board* board);