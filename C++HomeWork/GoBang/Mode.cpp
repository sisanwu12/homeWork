#include "Mode.h"

const char black = 249;
const char white = 248;

//简易模式
void Easy(){
	Board* board = new Board();
	Count* count = new Count();
	Player* p1 = new Player();
	Player* p2 = new Player();
	p1->setStyle(black);
	p2->setStyle(white);
	while (true) {
		PrintPlayPiece();
		cout << "black piece player" << endl;
		count->pushBlack(*p1->PlayPiece(board));
		if (IsWin(count->getBlack(), false, board)) {
			PrintWin();
			cout << "the black piece player is win!" << endl;
			return;
		}
		PrintPlayPiece();
		cout << "white piece player" << endl;
		count->pushWhite(*p2->PlayPiece(board));
		if (IsWin(count->getWhite(), false, board)) {
			PrintWin();
			cout << "the white piece player is win!" << endl;
			return;
		}
	}
}

//标准模式
void Standard() {
	Board* board = new Board();
	Count* count = new Count();
	Player* p1 = new Player();
	Player* p2 = new Player();
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
			PrintPlayPiece();
			cout << "white piece player" << endl;
			count->pushWhite(*p1->PlayPiece(board));
			if (IsWin(count->getWhite(), false, board)) {
				PrintWin();
				cout << "the white piece player is win!" << endl;
				return;
			}
			PrintPlayPiece();
			cout << "black piece player" << endl;
			count->pushBlack(*p2->PlayPiece(board));
			if (IsWin(count->getWhite(), true, board) == 2) {
				PrintWin();
				cout << "the white piece player is win!" << endl;
				return;
			}
			else if (IsWin(count->getWhite(), true, board) == -1) {
				PrintLose();
				cout << "the black piece player is lose,because of the balance breaker" << endl;
				return;
			}
		}
		else {
			PrintPlayPiece();
			cout << "white piece player" << endl;
			count->pushWhite(*p2->PlayPiece(board));
			if (IsWin(count->getWhite(), false, board)) {
				PrintWin();
				cout << "the white piece player is win!" << endl;
				return;
			}
		}
	}
}
