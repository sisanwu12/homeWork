#include "Rules.h"

// �ж��Ƿ�����
bool checkWin(bool Count[9]) {
	int num = 0;
	for (int i = 0; i < 9; i++) {
		if (Count[i] == true) num++;
		else num = 0;
		if (num == 5) return true;
	}
	return false;
}

// ��Ӯ����
bool IsWin(vector<Piece>& count){
	if (count.empty()) return false;
	if (count.size() < 5) return false;
	int x = (count.end() - 1)->getX();
	int y = (count.end() - 1)->getY();
	// ��
	bool yCount[9];
	yCount[4] = true;
	// ��
	bool xCount[9];
	xCount[4] = true;
	// ���Խ���
	bool xyCount[9];
	xyCount[4] = true;
	// ���Խ���
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
	if (checkWin(xCount)) return true;
	if (checkWin(yCount)) return true;
	if (checkWin(xyCount)) return true;
	if (checkWin(yxCount)) return true;
	return false;
}


// ���ֿɽ���
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
	else if (choose == "2") { return; }
	else {
		PrintError();
		cout << "input error" << endl;
		Sleep(3000);
		goto AGAINinput;
	}
}

// ��������
void IsFifth(Board* board){
	
}

// ��������
bool IsThreeThree(Board* board){
	return false;
}

//���Ľ���
bool IsFourFour(Board* board){
	return false;
}

//��������
bool IsLongSequential(Board* board)
{
	return false;
}
