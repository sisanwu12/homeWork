#include "Player.h"
#include "Print.h"
#include "Board.h"
#include "Windows.h"

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
char Player::getPiece() {
	return this->piece;
}
void Player::setAccount(string account) {
	this->account = account;
}
void Player::setPassword(string password) {
	this->password = password;
}
void Player::setPiece(char piece) {
	this->piece = piece;
}

//玩家落子函数
bool Player::PlayPiece(Board &board) {
	int x, y;
AGAINplayPiece:
	PrintPlayPiece();
	board.PrintBoard();
	cout << "please input next piece location:" << endl;
	cout << "X = ";
	cin >> x;
	cout << endl << "Y = ";
	cin >> y;
	if (x <= 0 || x > 15 || y <= 0 || y > 15) {
		PrintError();
		cout << "Error location!" << endl;
		cout << "please input again" << endl;
		cout << "please wait 3 second for continue" << endl;
		Sleep(3000);
		goto AGAINplayPiece;
	}
	if (board.board[board.getI(y)][board.getJ(x)].getEmpty()) {
		PrintError();
		cout << "This point has a piece already!" << endl;
		cout << "please input again" << endl;
		cout << "please wait 3 second for continue" << endl;
		Sleep(3000);
		goto AGAINplayPiece;
	}
	char style = board.board[board.getI(y)][board.getJ(x)].getStyle();
	board.board[board.getI(y)][board.getJ(x)].setStyle(this->getPiece());
	cout << endl << endl << endl;
	board.PrintBoard();
	cout << "Do you confirm this play piece?" << endl;
	cout << "right please input 1 ; input anothr cancel" << endl;
	string Y_N;
	cin >> Y_N;
	if (Y_N == "1") return true;
	cout << "this play piece has been cancelled" << endl;
	cout << "please wait 3 second for continue" << endl;
	Sleep(3000);
	return false;
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
			cout << "please wait 3 second for continue" << endl;
			Sleep(3000);
			return &pos->second;
		}
		PrintError();
		cout << "password error! " << endl;
		cout << "there are " << 2 - i << " times to try!" << endl;
		cout << "please wait 3 second for continue" << endl;
		Sleep(3000);
		system("cls");
		cout << "welcome " << pos->first << " please input your password: " << endl;
	}
	PrintError();
	cout << "Too many password attempts!" << endl;
	cout << "please wait 3 second for continue" << endl;
	Sleep(3000);
	return false;
} 

