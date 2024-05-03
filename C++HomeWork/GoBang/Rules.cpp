#include "Rules.h"

// 五手两打
void IsFifth(Board* board, Player* black, Player* white, Count* count) {
	Board b;
	system("cls");
	board->PrintBoard();
	cout << "black piece player has 5 pieces on line" << endl;
	cout << "plaese choose 2 position to put pieces" << endl;
	char wait = '#', bla = black->getStyle();
	Piece *twopiece[2];
	black->setStyle(wait);
	for (int i = 0; i < 2; i++) {
		Piece* p = black->PlayPiece(board);
		if (p == nullptr) {
			i--;
			continue;
		}
		twopiece[i] = p;
	}
	black->setStyle(bla);
	system("cls");
	board->PrintBoard();
	cout << "plaese white piece player choose one position" << endl;
	cout << "1. (" << twopiece[0]->getX() << ", " << twopiece[0]->getY() << ")" << endl;
	cout << "2. (" << twopiece[1]->getX() << ", " << twopiece[1]->getY() << ")" << endl;
AGAINcin:
	string choose;
	cin >> choose;
	if (choose == "1") {
		board->board[board->getI(twopiece[0]->getY())][board->getI(twopiece[0]->getX())].setStyle(bla);
		board->board[board->getI(twopiece[1]->getY())][board->getI(twopiece[1]->getX())].setEmpty(true);
		board->board[board->getI(twopiece[1]->getY())][board->getI(twopiece[1]->getX())].setStyle(b.board[board->getI(twopiece[1]->getY())][board->getI(twopiece[1]->getX())].getStyle());
	}
	else if (choose == "2") {
		board->board[board->getI(twopiece[1]->getY())][board->getI(twopiece[1]->getX())].setStyle(bla);
		board->board[board->getI(twopiece[0]->getY())][board->getI(twopiece[0]->getX())].setEmpty(true);
		board->board[board->getI(twopiece[0]->getY())][board->getI(twopiece[0]->getX())].setStyle(b.board[board->getI(twopiece[0]->getY())][board->getI(twopiece[0]->getX())].getStyle());
	}
	else {
		PrintError();
		cout << "input error" << endl;
		Sleep(3000);
		goto AGAINcin;
	}
}

// 判断是否五子
bool checkWin(bool xCount[9], bool yCount[9], bool xyCount[9], bool yxCount[9]) {
	int xnum = 0, ynum = 0, xynum = 0, yxnum = 0;
	for (int i = 0; i < 9; i++) {
		if (xCount[i] == true) xnum++;
		else xnum = 0;
		if (yCount[i] == true) ynum++;
		else ynum = 0;
		if (xyCount[i] == true) xynum++;
		else xynum = 0;
		if (yxCount[i] == true) yxnum++;
		else yxnum = 0;
	}
	if (xnum == 5 || ynum == 5 || xynum == 5 || yxnum == 5) return true;
	else return false;
}

//禁手规则
bool Forbidden(bool xCount[9], bool yCount[9], bool xyCount[9], bool yxCount[9]) {
	int xcount = 0, ycount = 0, xycount = 0, yxcount = 0;
	for (int i = 0; i < 9; i++) {
		if (xCount[i] == true) xcount++;
		else {
			if (i + 1 != 9 && xCount[i + 1] == true) continue;
			xcount = 0;
		}
		if (yCount[i] == true) ycount++;
		else {
			if (i + 1 != 9 && yCount[i + 1] == true) continue;
			ycount = 0;
		}
		if (xyCount[i] == true) xycount++;
		else {
			if (i + 1 != 9 && xyCount[i + 1] == true) continue;
			xycount = 0;
		}
		if (yxCount[i] == true) yxcount++;
		else {
			if (i + 1 != 9 && yxCount[i + 1] == true) continue;
			yxcount = 0;
		}
	}
	int num = 0;
	if (xcount >= 3)num++;
	if (ycount >= 3)num++;
	if (xycount >= 3)num++;
	if (yxcount >= 3)num++;
	if (num >= 2) return true;
	return false;
}

//规则函数
int IsWin(vector<Piece>& count,bool BorW,Board* board){
	if (count.empty()) return 0;
	int x = (count.end() - 1)->getX();
	int y = (count.end() - 1)->getY();
	// 行
	bool yCount[9];
	yCount[4] = true;
	// 列
	bool xCount[9];
	xCount[4] = true;
	// 主对角线
	bool xyCount[9];
	xyCount[4] = true;
	// 副对角线
	bool yxCount[9];
	yxCount[4] = true;

	for (vector<Piece>::iterator it = count.begin(); it != count.end(); it++) {
		if (it->getX() == x) {
			if (it->getY() >= y - 4 && it->getY() < y) yCount[4 - y + it->getY()] = true;
			if (it->getY() <= y + 4 && it->getY() > y) yCount[4 - it->getY() + y] = true;
		}
		if (it->getY() == y) {
			if (it->getX() >= x - 4 && it->getX() < x) xCount[4 - x + it->getX()] = true;
			if (it->getX() <= x + 4 && it->getX() > x) xCount[4 - it->getX() + x] = true;
		}
		if ((it->getX() - x) + (it->getY() - y) == 0) {
			if (it->getX() >= x - 4 && it->getX() < x) xyCount[4 - x + it->getX()] = true;
			if (it->getX() <= x + 4 && it->getX() > x) xyCount[4 - it->getX() + x] = true;
		}
		if (it->getX() - x == it->getY() - y) {
			if (it->getX() >= x - 4 && it->getX() < x) yxCount[4 - x + it->getX()] = true;
			if (it->getX() <= x + 4 && it->getX() > x) yxCount[4 - it->getX() + x] = true;
		}
	}
	if (!BorW) {
		if (checkWin(xCount,yCount,xyCount,yxCount)) return 1;
	}
	else {
		if (Forbidden(xCount, yCount, xyCount, yxCount)) return -1;
		if (checkWin(xCount, yCount, xyCount, yxCount)) return 2;
	}
	return 0;
}

// 三手可交换
void IsThridSwap(Board* board,Player* black,Player* white,Count* count){
	system("cls");
	cout << "please black piece player put 3 pieces on the board" << endl;
	Sleep(3000);
	for (int i = 0; i < 3; i++) {
		Piece* p = black->PlayPiece(board);
		if (p == nullptr) {
			PrintLose();
			return;
		}
		count->pushBlack(*p);
	}
	cout << endl << endl << endl;
AGAINinput:
	system("cls");
	board->PrintBoard();
	cout << "please white piece player choose whitch piece do you want: " << endl;
	cout << "1. black piece" << endl;
	cout << "2. white piece" << endl;
	string choose;
	cin >> choose;
	if (choose == "1") {
		char tmp = black->getStyle();
		black->setStyle(white->getStyle());
		white->setStyle(tmp);
		return;
	}
	else if (choose == "2") return;
	else {
		PrintError();
		cout << "input error" << endl;
		Sleep(3000);
		goto AGAINinput;
	}
}

