#pragma once
#include <iostream>
#include "Board.h"
#include "Player.h"
#include "Piece.h"
#include "Count.h"
using namespace std;

// ��Ӯ����
int IsWin(vector<Piece>& count,bool BorW);
// ���ֿɽ���
void IsThridSwap(Board* board, Player* black, Player* white,Count* count);
// ��������
void IsFifth(Board* board);
