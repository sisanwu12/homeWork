#pragma once
#include <iostream>
#include "Board.h"
#include "Piece.h"
#include "Count.h"
using namespace std;

// ��Ӯ����
bool IsWin(xy& xy);

// ���ֿɽ���
bool IsThridSwap(Board* board);

// ��������
bool IsFifth(Board* board);

// ��������
bool IsThreeThree(Board* board);

//���Ľ���
bool IsFourFour(Board* board);

//��������
bool IsLongSequential(Board* board);