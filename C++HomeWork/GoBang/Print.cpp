#include "Print.h"

//µÇÂ¼
void PrintLogIn() {
	system("cls");
	cout << "--- --- --- --- --- --- ---" << endl;
	cout << "--- log in Gobang play  ---" << endl;
	cout << "--- --- --- --- --- --- ---" << endl;
	cout << endl << endl << endl;
}

//´íÎó
void PrintError() {
	system("cls");
	cout << "--- --- --- --- --- --- ---" << endl;
	cout << "--- ---    ERROR    --- ---" << endl;
	cout << "--- --- --- --- --- --- ---" << endl;
	cout << endl << endl << endl;
}

//×¢²á
void PrintAddAccount() {
	system("cls");
	cout << "--- --- --- --- --- --- ---" << endl;
	cout << "--- --- add account --- ---" << endl;
	cout << "--- --- --- --- --- --- ---" << endl;
	cout << endl << endl << endl;
}

//Âä×Ó
void PrintPlayPiece() {
	system("cls");
	cout << "--- --- --- --- --- --- ---" << endl;
	cout << "--- ---  play piece --- ---" << endl;
	cout << "--- --- --- --- --- --- ---" << endl;
	cout << endl << endl << endl;
}

//¹æÔò
void PrintRules() {
	system("cls");
	cout << "--- --- --- --- --- --- ---" << endl;
	cout << "--- ---    Rules    --- ---" << endl;
	cout << "--- --- --- --- --- --- ---" << endl;
	cout << endl << endl << endl;
	cout << "1. Each side of the game holds one piece." << endl;
	cout << "2. Open with an empty board." << endl;
	cout << "3. Black first, white after, alternate down, each time can only be the next piece." << endl;
	cout << "4. A piece is placed on a blank spot on the board and cannot be moved or taken away after it has been set." << endl;
	cout << "5. The first piece of the black side must be placed on the celestial point, the central crossing point." << endl;
	cout << "6. In the start at a play, the first player put 3 black pieces on the board, and the second player choose who play black." << endl;
	cout << "7. Black piece player must choose two position(it can not be a symmetrical position)," << endl;
	cout << "   white piece player choose one position to put black piece,when black piece player put the fifth piece." << endl;
	cout << "8. Balance breaker in black piece player." << endl;
	cout << endl << endl << endl;
}

//½ûÊÖ
void PrintBalanceBreaker() {
	system("cls");
	cout << "--- --- --- --- --- --- ---" << endl;
	cout << "---   balance breaker   ---" << endl;
	cout << "--- --- --- --- --- --- ---" << endl;
	cout << endl << endl << endl;
}

//Ó®
void PrintWin() {
	system("cls");
	cout << "--- --- --- --- --- --- ---" << endl;
	cout << "--- ---!!!you WIN!!!--- ---" << endl;
	cout << "--- --- --- --- --- --- ---" << endl;
	cout << endl << endl << endl;
}

//ÈÏÊä
void PrintLose() {
	system("cls");
	cout << "--- --- --- --- --- --- ---" << endl;
	cout << "--- ---  you lose   --- ---" << endl;
	cout << "--- --- --- --- --- --- ---" << endl;
	cout << endl << endl << endl;
}
