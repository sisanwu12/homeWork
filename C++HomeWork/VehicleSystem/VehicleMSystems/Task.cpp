#include "Task.h"

static Parking& download() {
	CarOrder* carorder;
	string car_no;
	string btime;
	int park_num;
	string s;
	int end = -1;
	ifstream ifs;
	ifs.open("parkingData.txt", ios::in);
	getline(ifs, s);
	end = s.find(':');
	s.erase(s.begin(), s.begin() + end + 1);
	int num = stoi(s);
	Parking parking(num);
	while (ifs.eof()) {
		getline(ifs, s);
		if (s == "---- ---- ---- ---- ---- ----") continue;
		end = s.find(':');
		s.erase(s.begin(), s.begin() + end + 1);
		car_no = s;
		getline(ifs, s);
		end = s.find(':');
		s.erase(s.begin(), s.begin() + end + 1);
		park_num = stoi(s);
		getline(ifs, s);
		end = s.find('_');
		s.erase(s.begin(), s.begin() + end + 1);
		btime = s;
		carorder = new CarOrder(car_no, park_num);
		carorder->setBeginTime(btime);
		carorder->setOrderNP();
		parking.setInit(carorder, park_num);
		delete carorder;
		carorder = nullptr;
	}
	return parking;
}

void Task::End(Parking& parking) {
	system("cls");
	cout << "正在保存系统数据……" << endl;
	ofstream ofs("parkingData.txt", ios::out);
	ofs << "---- 大小:" << parking.getAllPlace() << endl;
	ofs << "---- ---- ---- ---- ---- ----" << endl;
	for (auto it = parking.getPark().begin(); it != parking.getPark().end(); it++) {
		ofs << "---- 车牌号:" << it->second.getCarNo() << endl;
		ofs << "---- 车位号:" << it->second.getParkNum() << endl;
		ofs << "---- 单号:" << it->second.getOrderNp() << endl;
		ofs << "---- ---- ---- ---- ---- ----" << endl;
	}
	ofs.close();
	cout << "数据已保存！" << endl;
	Sleep(3000);
	return;
}

static Parking& choose1() {
	system("cls");
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "----     初始化停车场     ----" << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << endl << endl << endl;
	cout << "输入停车场大小（车位数）：" << endl;
	cout << "注：该操作会覆盖上一个停车场系统的数据，请谨慎操作！" << endl;
	cout << "若已有系统数据，可以输入数字 -1 返回" << endl;
	int num;
	cin >> num;
	if (num >= 0 && num <= 1000000) {
		Parking parking(num);
		cout << "====   3秒后自动跳转至运行界面  ====" << endl;
		Sleep(3000);
		return parking;
	}
	return;
}

static Parking& choose2() {
	Parking& parking = download();
	Print::Finished();
	Sleep(3000);
	return parking;
}

static void choose3() {
	Print::ShowParking();
	Parking& p = download();
	cout << "当前停车场内有：" << p.getPark().size() << " 辆车" << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	for (auto it = p.getPark().begin(); it != p.getPark().end(); it++) {
		cout << "车牌号：" << it->first << endl;
		cout << "车位号：" << it->second.getParkNum() << endl;
		cout << "停入时间：" << it->second.getBTime() << endl;
		cout << "---- ---- ---- ---- ---- ----" << endl;
	}
	cout << "==== ==== ==== ==== ==== ====" << endl;
	cout << "便道内有：" << p.getAccess().size() << " 辆车" << endl;
}

Parking& choose() {
AGAINCHOOSE:
	Print::Admin();
	string INput;
	cin >> INput;
	if (INput == "1") {
		return choose1();
	}
	else if (INput == "2") {
		return choose2();
	}
	else if (INput == "3") {
		choose3();
		system("pause");
		goto AGAINCHOOSE;
	}
	else if (INput == "4") {
		return;
	}
	else {
		Print::Error();
		cout << "---- ---- ---- ---- ---- ----" << endl;
		cout << "----     输入内容有误！   ----" << endl;
		cout << "---- ---- ---- ---- ---- ----" << endl;
		Sleep(3000);
		goto AGAINCHOOSE;
	}
}


Parking& Task::Init() {
AGAINAMIN:
	Print::AdminMune();
	string INput;
	cin >> INput;
	if (INput == "1") {
		Parking& parking = choose();
		if (parking.getPark().empty()) goto AGAINAMIN;
		else return parking;
	} else if (INput == "2") {
		return;
	} else {
		Print::Error();
		cout << "---- ---- ---- ---- ---- ----" << endl;
		cout << "---- 输入内容有误！" << endl;
		cout << "---- ---- ---- ---- ---- ----" << endl;
		Sleep(3000);
		goto AGAINAMIN;
	}
}

void Task::Star(Parking& parking) {
AGAININPUT: // 车牌号输入 goto 点
	Print::INCarNo();
	string carno;
	cin >> carno;
	if (carno == "0000") {
		Task::End(parking);
		return;
	}
	if (!CarOrder::IsCarNo(carno)) {
		Print::Error();
		cout << "---- ---- ---- ---- ---- ----" << endl;
		cout << "----   车牌号格式有误！   ----" << endl;
		cout << "----   请重新输入车牌号   ----" << endl;
		Sleep(3000);
		goto AGAININPUT; // 跳转到 AGAININPUT 的位置顺序执行程序
	} else {
		auto it = parking.getPark().find(carno);
		if (it == parking.getPark().end()) {
			parking.CarIN(carno);
		}
		else {
			parking.CarOUT(carno);
		}
		goto AGAININPUT;
	}
}
