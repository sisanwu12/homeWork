#include "Player.h"


Player::Player() {};
Player::Player(string account, string password) {
	this->account = account;
	this->password = password;
}
string Player::getAccount() {
	return this->account;
}
string Player::getPassword() {
	return this->password;
}
char Player::getStyle() {
	return this->style;
}
void Player::setAccount(string account) {
	this->account = account;
}
void Player::setPassword(string password) {
	this->password = password;
}
void Player::setStyle(char style) {
	this->style = style;
}


//玩家落子函数
Piece* Player::PlayPiece(Board* board) {
	int x = 1, y = 1;
	char cursor = '@';
	char prior = board->SwapPiece(x, y, cursor);
	char move;
	while (true) {
		system("cls");
		PrintPlayPiece();
		board->PrintBoard();
		cout << "please use 'w','a','s','d' to move cursor" << endl;
		cout << "input '1' to play piece" << endl;
		cout << "input '0' to finish this play" << endl;
		move = _getch();
		switch (move) {
		case 'w':	//光标上移
			if (y == 15) break;
			cursor = board->SwapPiece(x, y, prior);
			y++;
			prior = board->SwapPiece(x, y, cursor);
			break;
		case 'a':	//光标左移
			if (x == 1) break;
			cursor = board->SwapPiece(x, y, prior);
			x--;
			prior = board->SwapPiece(x, y, cursor);
			break;
		case 's':	//光标下移
			if (y == 1) break;
			cursor = board->SwapPiece(x, y, prior);
			y--;
			prior = board->SwapPiece(x, y, cursor);
			break;
		case 'd':	//光标右移
			if (x == 15) break;
			cursor = board->SwapPiece(x, y, prior);
			x++;
			prior = board->SwapPiece(x, y, cursor);
			break;
		case '1':	//落子
			if (board->PlayPiece(x, y, this->style)) {
				Piece* p = new Piece(x, y, this->getStyle());
				return p;
			}
			PrintError();
			cout << "this position has been play piece!" << endl;
			Sleep(3000);
			break;
		case '0':	//退出
			return nullptr;
		default: break;
		}
	}
}

//注册函数
bool AddAccount(map<string, Player>& Map) {
	string Account, Password1, Password2;
AGAINaddAccount: // 账户 goto 点
	PrintAddAccount();
	cout << "please input new account (or input 0 close): " << endl;
	cin >> Account;
	if (Account == "0") return false;
	if (Map.find(Account) != Map.end()) {
		PrintError();
		cout << "the account has already registered!" << endl;
		cout << "please wait 3 second for continue" << endl;
		Sleep(3000);
		goto AGAINaddAccount;
	}
 
AGAINpassword: // 密码 goto 点
	PrintAddAccount();
	cout << "welcome " << Account << " !" << endl;
	cout << "please set your password (or input 0 close):" << endl;
	cin >> Password1;
	if (Password1 == "0") return false;
	PrintAddAccount();
	cout << "please input the password again:" << endl;
	cin >> Password2;
	if (Password1 != Password2) {
		PrintError();
		cout << "The passwords do not match!" << endl;
		cout << "please wait 3 second for continue" << endl;
		Sleep(3000);
		goto AGAINpassword;
	}
	PrintAddAccount();
	cout << "account: " << Account << endl;
	cout << "password: " << Password1 << endl;
	cout << "Do you confirm the registration? " << endl;
	cout << "right please input 1 ; input anothr cancel" << endl;
	string Y_N;
	cin >> Y_N;
	if (Y_N != "1") {
		cout << "Registration has been cancelled" << endl;
		cout << "please wait 3 second for continue" << endl;
		Sleep(3000);
		return false;
	}
	Player player(Account, Password1);
	Map.insert(pair<string, Player>(player.getAccount(), player));
	cout << "Successfully registered !" << endl;
	cout << "please wait 3 second for continue" << endl;
	Sleep(3000);
	return true;
}

//登录函数
Player* LogIn(map<string,Player> &Map) {
	Player* player = new Player;
	PrintLogIn();
	cout << "please input your account: " << endl;
	string account;
	cin >> account;
	map<string, Player>::iterator pos = Map.find(account);
	if (pos == Map.end()) {
		PrintError();
		cout << "can not find this account,please try again" << endl;
		return nullptr;
	}
	string password;
	cout << "welcome " << pos->first << " please input your password: " << endl;
	for (int i = 0; i < 3; i++) {
		if (i == 2) break;
		cin >> password;
		if (password == pos->second.getPassword()) {
			cout << "Verification succeeded!" << endl;
			Sleep(3000);
			return &pos->second;
		}
		PrintError();
		cout << "password error! " << endl;
		cout << "there are " << 2 - i << " times to try!" << endl;
		Sleep(3000);
		system("cls");
		cout << "welcome " << pos->first << " please input your password: " << endl;
	}
	PrintError();
	cout << "Too many password attempts!" << endl;
	Sleep(3000);
	return nullptr;
} 

