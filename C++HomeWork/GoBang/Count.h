#pragma once
#include <iostream>
#include <vector>
#include"Piece.h"
using namespace std;

class Count {
private:
	vector<Piece> black;
	vector<Piece> white;
public:
	vector<Piece>& getBlack();
	vector<Piece>& getWhite();
	void pushBlack(Piece& piece);
	void pushWhite(Piece& piece);
};