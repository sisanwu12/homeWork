#include "Print.h"

void Print::INCarNo() {
	system("cls");
	cout << "==== ==== ==== ==== ==== ==== ====" << endl;
	cout << "==== ====   请输入车牌号  ==== ====" << endl;
	cout << "==== ==== ==== ==== ==== ==== ====" << endl;
	cout << endl << endl << endl;
}

void Print::Order() {
	system("cls");
	cout << "==== ==== ==== ==== ==== ==== ====" << endl;
	cout << "==== ====   您的账单如下  ==== ====" << endl;
	cout << "==== ==== ==== ==== ==== ==== ====" << endl;
	cout << endl << endl << endl;
	cout << "---- ---- ---- ---- ---- ---- ----" << endl;
}

void Print::Error(){
	system("cls");
	cout << "==== ==== ==== ==== ==== ==== ====" << endl;
	cout << "==== ==== ！！！错误 ！！！==== ====" << endl;
	cout << "==== ==== ==== ==== ==== ==== ====" << endl;
	cout << endl << endl << endl;
}

void Print::Welcome() {
	system("cls");
	cout << "==== ==== ==== ==== ==== ==== ====" << endl;
	cout << "==== ====  ！已成功停入！ ==== ====" << endl;
	cout << "==== ==== ==== ==== ==== ==== ====" << endl;
	cout << endl << endl << endl;
}

void Print::Bye() {
	system("cls");
	cout << "==== ==== ==== ==== ==== ==== ====" << endl;
	cout << "==== ====  ！已成功驶出！ ==== ====" << endl;
	cout << "==== ==== ==== ==== ==== ==== ====" << endl;
	cout << endl << endl << endl;
}
