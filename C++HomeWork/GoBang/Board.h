#pragma once
#include <iostream>
#include "Piece.h"
using namespace std;

class Board {
public:
	Piece board[15][29];
	Board();
	void PointBoard();
	int getI(int y);
	int getJ(int x);
};