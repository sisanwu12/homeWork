#include "Board.h"
#include "Player.h"
#include "windows.h"
#include "Rules.h"
#include "Mode.h"
#include <map>
#include <fstream>
using namespace std;
const char black = 249;
const char white = 248;


// 初始化函数
void Init(map<string, Player>& Map) {
	ifstream ifs;
	ifs.open("Player.txt", ios::in);
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


// 登出函数
void PlayerExit(map<string, Player>& Map) {
	ofstream ofs;
	ofs.open("Player.txt",ios::out);
	for (map<string, Player>::iterator it = Map.begin(); it != Map.end(); it++) {
		ofs << it->second.getAccount() << "\t" << it->second.getPassword() << endl;
	}
	ofs.close();
	cout << "Safely Exited" << endl;
	Sleep(3000);
	return;
}


// 游玩函数
void Play(map<string, Player>& Map) {
	system("cls");
	cout << "player 1 log in" << endl;
	Sleep(3000);
	Player* p1 = LogIn(Map);
	if (p1 == nullptr) return;
	system("cls");
	cout << "player 2 log in" << endl;
	Sleep(3000);
	Player* p2 = LogIn(Map);
	if (p2 == nullptr) return;
MODEAGAIN:
	system("cls");
	cout << "welcome " << p1->getAccount() << " and " << p2->getAccount() << endl;
	cout << "please choose the modes:" << endl;
	cout << "1. Simple Mode" << endl;
	cout << "2. Standard Mode" << endl;
	string s;
	cin >> s;
	if (s == "1") Simple(p1, p2);
	else if (s == "2") Standard(p1, p2);
	else goto MODEAGAIN;
	delete p1, p2;
	p1 = nullptr;
	p2 = nullptr;
	return;
}


int main() {
	SetConsoleOutputCP(437);
	map<string, Player> Map;
	Init(Map);
GAMEAGAIN:
	PrintWelcome();
	cout << "1. Log In" << endl;
	cout << "2. Add Account" << endl;
	cout << "3. Exit" << endl;
	string INPUT;
	cin >> INPUT;
	if (INPUT == "1") {
		Play(Map);
		goto GAMEAGAIN;
	}
	else if (INPUT == "2") {
		AddAccount(Map);
		goto GAMEAGAIN;
	}
	else if (INPUT == "3") {
		PlayerExit(Map);
		return 0;
	}
	else goto GAMEAGAIN;
}
