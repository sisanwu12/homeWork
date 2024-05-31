#include "Parking.h"

Parking::Parking(int all_place):all_place(all_place), occupied_place(all_place) {
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "--- ͣ�����ѳ�ʼ���ɹ���" << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "---- ��ͣ��λ��" << this->all_place << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
}

void Parking::CarIN(string car_no) {
	CarOrder* order = new CarOrder(car_no);
	// ���ó�����ͣ����
	this->park.insert(pair<string, CarOrder>(order->getCarNo(), *order));
	// ʣ��ͣ��λ��һ
	this->occupied_place -= 1;
	system("cls");
	Print::Welcome();
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "---- ���ƺţ�"<< order->getCarNo() << endl;
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
}

void Parking::CarOUT(string car_no) {
	auto it = this->park.find(car_no);
	// ��ȡ����ʱ��
	it->second.setEndTime();
	// �������
	it->second.setMoney();
	Print::Bye();
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "---- ���ƺţ�" << it->second.getCarNo() << endl;
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

	// д����û���СƱ�ĵ�
	ofstream ofs(".\\Order\\user\\" + it->second.getOrderNp() + ".txt", ios::out);
	ofs << "---- ���ƺţ�" << it->second.getCarNo() << endl;
	ofs << "---- ͣ��ʱ�䣺" << it->second.getBTime() << endl;
	ofs << "---- ʻ��ʱ�䣺" << it->second.getETime() << endl;
	ofs << "---- ͣ��ʱ����" << it->second.getTSpan() << endl;
	ofs << "---- �ϼƷ��ã�" << it->second.getMoney() << endl;
	ofs << "---- ���ţ�" << it->second.getOrderNp() << endl;
	ofs.close();

	// д��ϵͳ�ڲ��洢�ĵ�������Ϊ��λ
	CTime t = CTime::GetCurrentTime();
	string path = to_string(t.GetYear()) + "/" + to_string(t.GetMonth()) + "/" + to_string(t.GetDay());
	ofstream ofs1(".\\Order\\order\\" + path + ".txt", ios::app);
	ofs1 << "---- ���ƺţ�" << it->second.getCarNo() << endl;
	ofs1 << "---- ͣ��ʱ�䣺" << it->second.getBTime() << endl;
	ofs1 << "---- ʻ��ʱ�䣺" << it->second.getETime() << endl;
	ofs1 << "---- ͣ��ʱ����" << it->second.getTSpan() << endl;
	ofs1 << "---- �ϼƷ��ã�" << it->second.getMoney() << endl;
	ofs1 << "---- ���ţ�" << it->second.getOrderNp() << endl;
	ofs1 << "---- ---- ---- ---- ---- ----" << endl;
	ofs1.close();
	// ��������ͣ����ɾ��
	this->park.erase(it);
	// ʣ�೵λ��1
	this->occupied_place += 1;
	Sleep(3000);
}
