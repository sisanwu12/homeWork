#include "Print.h"

void Print::INCarNo() {
	system("cls");
	cout << "==== ==== ==== ==== ==== ==== ====" << endl;
	cout << "==== ====   请输入车牌号  ==== ====" << endl;
	cout << "==== ==== ==== ==== ==== ==== ====" << endl;
	cout << endl << endl << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "---- 请输入您的车牌号：";
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

void Print::AdminMune() {
	system("cls");
	cout << "==== ==== ==== ==== ==== ==== ====" << endl;
	cout << "====         管理员界面        ====" << endl;
	cout << "==== ==== ==== ==== ==== ==== ====" << endl;
	cout << endl << endl << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "----    1.   启动系统     ----" << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "----    2.   退出系统     ----" << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << endl << endl << endl;
	cout << "---- 请输入操作：";
}

void Print::Admin() {
	system("cls");
	cout << "==== ==== ==== ==== ==== ==== ====" << endl;
	cout << "====         管理员界面        ====" << endl;
	cout << "==== ==== ==== ==== ==== ==== ====" << endl;
	cout << endl << endl << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "----   1. 初始化停车场    ----" << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "----   2. 重加载停车场    ----" << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "----   3.  展示停车场     ----" << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "----   4.   退出系统     ----" << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << endl << endl << endl;
	cout << "---- 请输入操作：";
}

void Print::INAccess() {
	system("cls");
	cout << "==== ==== ==== ==== ==== ==== ====" << endl;
	cout << "====    ！已成功驶入便道 ！     ====" << endl;
	cout << "==== ==== ==== ==== ==== ==== ====" << endl;
	cout << endl << endl << endl;
}

void Print::OUTAccess() {
	system("cls");
	cout << "==== ==== ==== ==== ==== ==== ====" << endl;
	cout << "====        ！已离开 ！        ====" << endl;
	cout << "==== ==== ==== ==== ==== ==== ====" << endl;
	cout << endl << endl << endl;
}

void Print::Finished() {
	system("cls");
	cout << "==== ==== ==== ==== ==== ==== ====" << endl;
	cout << "==== ==== ！初始化完成 ！ ==== ====" << endl;
	cout << "==== ==== ==== ==== ==== ==== ====" << endl;
	cout << endl << endl << endl;
	cout << "====   3秒后自动跳转至运行界面  ====" << endl;
}

