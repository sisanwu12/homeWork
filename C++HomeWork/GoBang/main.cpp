#include "Board.h"
#include "Player.h"
#include "windows.h"
#include "Rules.h"
#include <map>
#include <fstream>
using namespace std;
const char black = 249;
const char white = 248;

void EasyPlay();

void PlayerExit(map<string, Player>& Map) {
	ofstream ofs;
	ofs.open("Player.dat",ios::out|ios::binary);
	ofs.write((const char*)&Map, sizeof(Map));
}

int main() {
	SetConsoleOutputCP(437);
	system("cls");
	map<string, Player> Map;
	ifstream ifs;
	ifs.open("Player.dat", ios::in | ios::binary);
	ifs.read((char*)&Map, sizeof(Map));
	
	Board* board = new Board;
	Count* count = new Count;
	//board->PrintBoard();
	Player* player = new Player;
	player->setStyle(white);
	bool BorW = true;
	while (true) {
		Piece* p = player->PlayPiece(board);
		if (p == nullptr) {
			PrintLose();
			return 0;
		}
		count->pushWhite(*p);
		if (IsWin(count->getWhite(), BorW,board)) {
			PrintWin();
			return 0;
		}
		BorW = !BorW;
	}
	return 0;
}

void EasyPlay() {
	Board* board = new Board();
	Count* count = new Count();
	Player* p1 = new Player();
	Player* p2 = new Player();
	p1->setStyle(black);
	p2->setStyle(white);
	while (true) {
		count->pushBlack(*p1->PlayPiece(board));
		if (IsWin(count->getBlack(), false, board)) {
			PrintWin();
			cout << "the black piece player is win!" << endl;
			return;
		}
		count->pushWhite(*p2->PlayPiece(board));
		if (IsWin(count->getWhite(), false, board)) {
			PrintWin();
			cout << "the white piece player is win!" << endl;
			return;
		}
	}
}