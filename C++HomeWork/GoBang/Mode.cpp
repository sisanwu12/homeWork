#include "Mode.h"

const char black = 249;
const char white = 248;

//简易模式
void Simple(Player* p1, Player* p2) {
	Board* board = new Board();
	Count* count = new Count();
	Piece* pi;
	p1->setStyle(black);
	p2->setStyle(white);
	while (true) {
		pi = p1->PlayPiece(board, true);
		if (p1 == nullptr) {
			PrintLose();
			return;
		}
		count->pushBlack(*pi);
		if (IsWin(count->getBlack(), false, board)) {
			PrintWin();
			cout << "the black piece player is win!" << endl;
			return;
		}
		pi = p2->PlayPiece(board, false);
		if (p1 == nullptr) {
			PrintLose();
			return;
		}
		count->pushWhite(*pi);
		if (IsWin(count->getWhite(), false, board)) {
			PrintWin();
			cout << "the white piece player is win!" << endl;
			return;
		}
	}
}

//标准模式
void Standard(Player* p1, Player* p2) {
	Board* board = new Board();
	Count* count = new Count();
	Piece* pi;
	p1->setStyle(black);
	p2->setStyle(white);
	PrintRules();
	cout << "if confirm these rules,please input the number '1'." << endl;
	string YN;
READY:
	cin >> YN;
	if (YN != "1") goto READY;
	int iftrue = IsThridSwap(board, p1, p2, count);
	if (iftrue == -1) return;
	else if (iftrue == 1) {
		p1->setStyle(white);
		p2->setStyle(black);
	}
	while (true) {
		if (p1->getStyle() == white) {
			pi = p1->PlayPiece(board, false);
			count->pushWhite(*pi);
			//判断白子
			if (IsWin(count->getWhite(), false, board)) {
				PrintWin();
				cout << "the white piece player is win!" << endl;
				return;
			}
			pi = p2->PlayPiece(board, true);
			count->pushBlack(*pi);
			//判断黑子
			if (IsWin(count->getBlack(), true, board) == 2) {
				IsFifth(board, p2, p1, count);
				if (IsWin(count->getBlack(), true, board) == 2) {
					PrintWin();
					cout << "the Black piece player is win!" << endl;
					return;
				}
			}
			else if (IsWin(count->getBlack(), true, board) == -1) {
				PrintLose();
				cout << "the black piece player is lose,because of the balance breaker" << endl;
				return;
			}
		}
		else {
			PrintPlayPiece();
			cout << "white piece player" << endl;
			count->pushWhite(*p2->PlayPiece(board,false));
			//判断白子
			if (IsWin(count->getWhite(), false, board)) {
				PrintWin();
				cout << "the white piece player is win!" << endl;
				return;
			}
			PrintPlayPiece();
			cout << "black piece player" << endl;
			count->pushBlack(*p1->PlayPiece(board,true));
			//判断黑子
			if (IsWin(count->getBlack(), true, board) == 2) {
				IsFifth(board, p1, p2, count);
				if (IsWin(count->getBlack(), true, board) == 2) {
					PrintWin();
					cout << "the Black piece player is win!" << endl;
					return;
				}
				else if (IsWin(count->getBlack(), true, board) == -1) {
					PrintLose();
					cout << "the black piece player is lose,because of the balance breaker" << endl;
					return;
				}
			}
		}
	}
}