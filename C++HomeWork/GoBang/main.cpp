#include "Board.h"
#include"windows.h"
using namespace std;

int main() {
	SetConsoleOutputCP(437);
	Board* board = new Board;
	board->PointBoard();
	char black = 249;
	char white = 248;
	cout << black << endl;
	cout << white << endl;
	return 0;
}