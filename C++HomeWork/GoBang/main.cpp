#include "Board.h"
#include "Player.h"
#include "windows.h"
#include "Rules.h"
#include <map>
#include <fstream>
using namespace std;
const char black = 249;
const char white = 248;

void Init(map<string, Player>& Map) {
	ifstream ifs;
	ifs.open("Player.dat", ios::in);
	Player* p = new Player;
	string s;
	int end = -1;
	while (getline(ifs, s)) {
		end = s.find('\t');
		p->setAccount(s.substr(0, end));
		s.erase(s.begin(), s.begin() + end + 1);
		p->setPassword(s);
		Map.insert(pair<string, Player>(p->getAccount(), *p));
	}
	ifs.close();
	delete p;
	p = nullptr;
}



void PlayerExit(map<string, Player>& Map) {
	ofstream ofs;
	ofs.open("Player.dat",ios::out);
	for (map<string, Player>::iterator it = Map.begin(); it != Map.end(); it++) {
		ofs << it->second.getAccount() << "\t" << it->second.getPassword() << endl;
	}
	ofs.close();
}

int main() {
	SetConsoleOutputCP(437);
	system("cls");
	map<string, Player> Map;
	Init(Map);



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
	
}