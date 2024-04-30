#pragma once
#include <iostream>
#include "Board.h"
#include "Player.h"
#include "Piece.h"
#include "Count.h"
using namespace std;

// ��Ӯ����
bool IsWin(vector<Piece>& count);

// ���ֿɽ���
void IsThridSwap(Board* board, Player* black, Player* white,Count* count);

// ��������
void IsFifth(Board* board);

// ��������
bool IsThreeThree(Board* board);

//���Ľ���
bool IsFourFour(Board* board);

//��������
bool IsLongSequential(Board* board);