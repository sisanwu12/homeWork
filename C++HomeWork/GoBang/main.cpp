#include "Board.h"
#include "Player.h"
#include "windows.h"
#include "Rules.h"
#include <map>
using namespace std;

int main() {
	SetConsoleOutputCP(437);
	system("cls");
	char black = 249;
	char white = 248;
	Board* board = new Board;
	Count* count = new Count;
	//board->PrintBoard();
	Player* player = new Player;
	player->setPiece(white);
	while (true) {
		Piece* p = player->PlayPiece(board);
		if (p == nullptr) {
			PrintLose();
			return 0;
		}
		count->pushWhite(*p);
		if (IsWin(count->getWhite())) {
			PrintWin();
			return 0;
		}
	}
	return 0;
}