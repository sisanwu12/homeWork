#include "Rules.h"

// 判断行
bool row(vector<Piece>& count,int y) {
	bool yCount[9];
	yCount[4] = true;
	for (vector<Piece>::iterator it = count.begin(); it != count.end(); it++) {
		if (it->getY() >= y - 4 && it->getY() < y) yCount[4 - y - it->getY()] = true;
		if (it->getY() <= y + 4 && it->getY() > y) yCount[4 - it->getY() - y] = true;
	}
	int num = 0;
	for (int i = 0; i < 9; i++) {
		if (yCount[i] == true) num++;
		else num = 0;
		if (num == 5) return true;
	}
	return false;
}

// 判断列
bool col(vector<Piece>& count, int x) {
	bool xCount[9];
	xCount[4] = true;
	for (vector<Piece>::iterator it = count.begin(); it != count.end(); it++) {
		if (it->getX() >= x - 4 && it->getX() < x) xCount[4 - x - it->getX()] = true;
		if (it->getX() <= x + 4 && it->getX() > x) xCount[4 - it->getX() - x] = true;
	}
	int num = 0;
	for (int i = 0; i < 9; i++) {
		if (xCount[i] == true) num++;
		else num = 0;
		if (num == 5) return true;
	}
	return false;
}

// 判赢函数
bool IsWin(vector<Piece>& count){
	int x = (count.end() - 1)->getX();
	int y = (count.end() - 1)->getY();
	// 行
	if (row(count, y)) return true;
	// 列
	if (col(count, x)) return true;
}


// 三手可交换
bool IsThridSwap(Board* board){
	return false;
}

// 五手两打
bool IsFifth(Board* board){
	return false;
}

// 三三禁手
bool IsThreeThree(Board* board){
	return false;
}

//四四禁手
bool IsFourFour(Board* board){
	return false;
}

//长连禁手
bool IsLongSequential(Board* board)
{
	return false;
}
