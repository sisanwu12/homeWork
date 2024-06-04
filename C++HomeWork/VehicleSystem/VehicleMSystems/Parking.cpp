#include "Parking.h"

Parking::Parking(int all_place):all_place(all_place), occupied_place(all_place) {
	memset(this->emptyPark, 0, sizeof this->emptyPark);
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "--- ͣ�����ѳ�ʼ���ɹ���" << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "---- ��ͣ��λ��" << this->all_place << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
}

void Parking::setInit(CarOrder* car,int parknum) {
	this->park.insert(pair<string, CarOrder>(car->getCarNo(), *car));
	this->emptyPark[parknum] = true;
}

void Parking::CarIN(string car_no) {
	// ����λ
	if (this->occupied_place == 0) {
		Print::Error();
		cout << "---- ---- ---- ---- ---- ----" << endl;
		cout << "----       ��λ������     ----" << endl;
		cout << "---- ---- ---- ---- ---- ----" << endl;
		cout << endl << endl << endl;
		cout << "�Ƿ�������ȴ���(�������� 1 ȷ�ϣ�������������ȡ��)" << endl;
		cout << "��ǰ������� " << this->getAccess().size() << " ����" << endl;
		string INput;
		cin >> INput;
		if (INput == "1") {
			this->INaccess(car_no);
			Print::INAccess();
		}
		else {
			Print::OUTAccess();
		}
		Sleep(3000);
		return;
	}

	int parknum = this->getParkNum();
	CarOrder* order = new CarOrder(car_no, parknum);
	// ���ó�����ͣ����
	this->park.insert(pair<string, CarOrder>(order->getCarNo(), *order));
	// ʣ��ͣ��λ��һ
	this->occupied_place -= 1;
	system("cls");
	Print::Welcome();
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "---- ���ƺţ�"<< order->getCarNo() << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "---- ��λ�ţ�" << order->getParkNum() << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "---- ͣ��ʱ�䣺" << order->getBTime() << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "---- ���ţ�" << order->getOrderNp() << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	// �ͷŶ����ڴ�
	delete order;
	// ��ָ��ָ���ָ�룬��ֹ����Ұָ��
	order = nullptr;
	Sleep(3000);
	return;
}

void Parking::INaccess(string car_no) {
	this->access.push(car_no);
}

void Parking::CarOUT(string car_no) {
	auto it = this->park.find(car_no);
	// ��ȡ����ʱ��
	it->second.setEndTime();
	// �������
	it->second.setMoney();
	Print::Bye();

	// д����û���СƱ�ĵ�
	ofstream ofs(it->second.getOrderNp() + ".txt", ios::out);
	ofs << "---- ���ƺţ�" << it->second.getCarNo() << endl;
	ofs << "---- ��λ�ţ�" << it->second.getParkNum() << endl;
	ofs << "---- ͣ��ʱ�䣺" << it->second.getBTime() << endl;
	ofs << "---- ʻ��ʱ�䣺" << it->second.getETime() << endl;
	ofs << "---- ͣ��ʱ����" << it->second.getTSpan() << endl;
	ofs << "---- �ϼƷ��ã�" << it->second.getMoney() << endl;
	ofs << "---- ���ţ�" << it->second.getOrderNp() << endl;
	ofs.close();
	
	// д��ϵͳ�ڲ��ĵ�
	ofstream ofs1("order.txt", ios::app);
	ofs1 << "---- ���ƺţ�" << it->second.getCarNo() << endl;
	ofs1 << "---- ��λ�ţ�" << it->second.getParkNum() << endl;
	ofs1 << "---- ͣ��ʱ�䣺" << it->second.getBTime() << endl;
	ofs1 << "---- ʻ��ʱ�䣺" << it->second.getETime() << endl;
	ofs1 << "---- ͣ��ʱ����" << it->second.getTSpan() << endl;
	ofs1 << "---- �ϼƷ��ã�" << it->second.getMoney() << endl;
	ofs1 << "---- ���ţ�" << it->second.getOrderNp() << endl;
	ofs1 << "---- ---- ---- ---- ---- ----" << endl;
	ofs1.close();
	// ��ӡ����Ļ
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "---- ���ƺţ�" << it->second.getCarNo() << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "---- ��λ�ţ�" << it->second.getParkNum() << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "---- ͣ��ʱ�䣺" << it->second.getBTime() << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "---- ʻ��ʱ�䣺" << it->second.getETime() << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "---- ͣ��ʱ����" << it->second.getTSpan() << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "---- �ϼƷ��ã�" << it->second.getMoney() << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "---- ���ţ�" << it->second.getOrderNp() << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;

	this->emptyPark[it->second.getParkNum()] = false;
	// ������û����ʣ�೵λ��1
	if (!this->access.empty()) {
		this->occupied_place += 1;

	} else {
		// �����һ�������
		this->CarIN(this->OUTaccess());
	}
	// ��������ͣ����ɾ��
	this->park.erase(it);
	Sleep(3000);
}

string Parking::OUTaccess() {
	string car_no = this->access.front();
	this->access.pop();
	return car_no;
}

queue<string> Parking::getAccess() {
	return this->access;
}

map<string, CarOrder> Parking::getPark() {
	return this->park;
}

int Parking::getParkNum() {
	int i = 0;
	for (i = 0; i < this->all_place; i++) {
		if (!this->emptyPark[i]) break;
	}
	emptyPark[i] = true;
	return i;
}

int Parking::getAllPlace(){
	return this->all_place;
}
