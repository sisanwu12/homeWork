#pragma once
#include <iostream>
#include <string>
#include <map>
#include <conio.h>
#include "Board.h"
#include "Print.h"
#include "Windows.h"

using namespace std;

class Player {
private:
	string account;
	string password;
	char style;
public:
	Player(string account, string password);
	Player();
	Piece* PlayPiece(Board* board);
	string getAccount();
	string getPassword();
	char getStyle();
	void setAccount(string account);
	void setPassword(string password);
	void setStyle(char style);
};

bool AddAccount(map<string, Player>& Map);
Player* LogIn(map<string, Player>& Map);