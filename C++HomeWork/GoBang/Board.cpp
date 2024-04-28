#include "Board.h"


int Board::getI(int y) {
	return 15 - y;
}
int Board::getJ(int x) {
	return x * 2 - 2;
}

//��ʽ��������
char Board::SwapPiece(int x, int y, char piece) {
	char tmp = board[getI(y)][getJ(x)].getStyle();
	board[getI(y)][getJ(x)].setStyle(piece);
	return tmp;
}

//���Ӻ���
bool Board::PlayPiece(int x, int y, char piece) {
	if (!board[getI(y)][getJ(x)].getEmpty()) return false;
	board[getI(y)][getJ(x)].setStyle(piece);
	board[getI(y)][getJ(x)].setEmpty(false);
	return true;
}

// ���̳�ʼ������
Board::Board() {
	Piece p;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 29; j++) {
			if (i == 0) {
				if (j == 0) {
					p.setPiece(p.getX(j), p.getY(i), 218);
					p.setEmpty(true);
					board[i][j] = p;
				}
				else if (j == 28) {
					p.setPiece(p.getX(j), p.getY(i), 191);
					p.setEmpty(true);
					board[i][j] = p;
				}
				else if (j != 28 && j % 2 == 0){
					p.setPiece(p.getX(j), p.getY(i), 194);
					p.setEmpty(true);
					board[i][j] = p;
				}
				else {
					p.setPiece(p.getX(j), p.getY(i), 196);
					p.setEmpty(true);
					board[i][j] = p;
				}
			}
			else if (i == 14) {
				if (j == 0) {
					p.setPiece(p.getX(j), p.getY(i), 192);
					p.setEmpty(true);
					board[i][j] = p;
				}
				else if (j == 28) {
					p.setPiece(p.getX(j), p.getY(i), 217);
					p.setEmpty(true);
					board[i][j] = p;
				}
				else if (j != 28 && j % 2 == 0) {
					p.setPiece(p.getX(j), p.getY(i), 193);
					p.setEmpty(true);
					board[i][j] = p;
				}
				else {
					p.setPiece(p.getX(j), p.getY(i), 196);
					p.setEmpty(true);
					board[i][j] = p;
				}
			}
			else {
				if (j == 0) {
					p.setPiece(p.getX(j), p.getY(i), 195);
					p.setEmpty(true);
					board[i][j] = p;
				}
				else if (j == 28) {
					p.setPiece(p.getX(j), p.getY(i), 180);
					p.setEmpty(true);
					board[i][j] = p;
				}
				else if (j != 28 && j % 2 == 0) {
					p.setPiece(p.getX(j), p.getY(i), 197);
					p.setEmpty(true);
					board[i][j] = p;
				}
				else {
					p.setPiece(p.getX(j), p.getY(i), 196);
					p.setEmpty(true);
					board[i][j] = p;
				}
			}
		}
	}
}

// ���̴�ӡ����
void Board::PrintBoard() {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 29; j++) {
			if (j == 0) {
				cout << 15 - i << ' ';
				if (i > 5) cout << ' ';
			}
			cout << board[i][j].getStyle();
		}
		cout << endl;
	}
	for (int i = 0; i < 29; i++) {
		if (i == 0) cout << "   ";
		if (i % 2 == 0){
			cout << i / 2 + 1;
			if (i / 2 < 9) cout << ' ';
		}
	}
	cout << endl << endl << endl;
}
 