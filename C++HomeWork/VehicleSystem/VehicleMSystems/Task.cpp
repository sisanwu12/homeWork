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
	cout << "���ڱ���ϵͳ���ݡ���" << endl;
	ofstream ofs("parkingData.txt", ios::out);
	ofs << "---- ��С:" << parking.getAllPlace() << endl;
	ofs << "---- ---- ---- ---- ---- ----" << endl;
	for (auto it = parking.getPark().begin(); it != parking.getPark().end(); it++) {
		ofs << "---- ���ƺ�:" << it->second.getCarNo() << endl;
		ofs << "---- ��λ��:" << it->second.getParkNum() << endl;
		ofs << "---- ����:" << it->second.getOrderNp() << endl;
		ofs << "---- ---- ---- ---- ---- ----" << endl;
	}
	ofs.close();
	cout << "�����ѱ��棡" << endl;
	Sleep(3000);
	return;
}

static Parking& choose1() {
	system("cls");
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "----     ��ʼ��ͣ����     ----" << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << endl << endl << endl;
	cout << "����ͣ������С����λ������" << endl;
	cout << "ע���ò����Ḳ����һ��ͣ����ϵͳ�����ݣ������������" << endl;
	cout << "������ϵͳ���ݣ������������� -1 ����" << endl;
	int num;
	cin >> num;
	if (num >= 0 && num <= 1000000) {
		Parking parking(num);
		cout << "====   3����Զ���ת�����н���  ====" << endl;
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
	cout << "��ǰͣ�������У�" << p.getPark().size() << " ����" << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	for (auto it = p.getPark().begin(); it != p.getPark().end(); it++) {
		cout << "���ƺţ�" << it->first << endl;
		cout << "��λ�ţ�" << it->second.getParkNum() << endl;
		cout << "ͣ��ʱ�䣺" << it->second.getBTime() << endl;
		cout << "---- ---- ---- ---- ---- ----" << endl;
	}
	cout << "==== ==== ==== ==== ==== ====" << endl;
	cout << "������У�" << p.getAccess().size() << " ����" << endl;
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
		cout << "----     ������������   ----" << endl;
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
		cout << "---- ������������" << endl;
		cout << "---- ---- ---- ---- ---- ----" << endl;
		Sleep(3000);
		goto AGAINAMIN;
	}
}

void Task::Star(Parking& parking) {
AGAININPUT: // ���ƺ����� goto ��
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
		cout << "----   ���ƺŸ�ʽ����   ----" << endl;
		cout << "----   ���������복�ƺ�   ----" << endl;
		Sleep(3000);
		goto AGAININPUT; // ��ת�� AGAININPUT ��λ��˳��ִ�г���
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
