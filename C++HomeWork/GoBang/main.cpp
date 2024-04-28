#include "Board.h"
#include "Player.h"
#include "windows.h"
#include <map>
using namespace std;

int main() {
	SetConsoleOutputCP(437);
	system("cls");
	char black = 249;
	char white = 248;
	Board* board = new Board;
	//board->PrintBoard();
	Player* player = new Player;
	player->setPiece(white);
	while (true) {
		player->PlayPiece(board);
	}
	return 0;
}