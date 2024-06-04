#include "Parking.h"

Parking::Parking(int all_place):all_place(all_place), occupied_place(all_place) {
	memset(this->emptyPark, 0, sizeof this->emptyPark);
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "--- 停车场已初始化成功！" << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "---- 总停车位：" << this->all_place << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
}

void Parking::setInit(CarOrder* car,int parknum) {
	this->park.insert(pair<string, CarOrder>(car->getCarNo(), *car));
	this->emptyPark[parknum] = true;
}

void Parking::CarIN(string car_no) {
	// 满车位
	if (this->occupied_place == 0) {
		Print::Error();
		cout << "---- ---- ---- ---- ---- ----" << endl;
		cout << "----       车位已满！     ----" << endl;
		cout << "---- ---- ---- ---- ---- ----" << endl;
		cout << endl << endl << endl;
		cout << "是否进入便道等待？(输入数字 1 确认，输入其他内容取消)" << endl;
		cout << "当前便道中有 " << this->getAccess().size() << " 辆车" << endl;
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
	// 将该车存入停车场
	this->park.insert(pair<string, CarOrder>(order->getCarNo(), *order));
	// 剩余停车位减一
	this->occupied_place -= 1;
	system("cls");
	Print::Welcome();
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "---- 车牌号："<< order->getCarNo() << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "---- 车位号：" << order->getParkNum() << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "---- 停入时间：" << order->getBTime() << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "---- 单号：" << order->getOrderNp() << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	// 释放堆区内存
	delete order;
	// 将指针指向空指针，防止出现野指针
	order = nullptr;
	Sleep(3000);
	return;
}

void Parking::INaccess(string car_no) {
	this->access.push(car_no);
}

void Parking::CarOUT(string car_no) {
	auto it = this->park.find(car_no);
	// 获取结束时间
	it->second.setEndTime();
	// 计算费用
	it->second.setMoney();
	Print::Bye();

	// 写入给用户的小票文档
	ofstream ofs(it->second.getOrderNp() + ".txt", ios::out);
	ofs << "---- 车牌号：" << it->second.getCarNo() << endl;
	ofs << "---- 车位号：" << it->second.getParkNum() << endl;
	ofs << "---- 停入时间：" << it->second.getBTime() << endl;
	ofs << "---- 驶出时间：" << it->second.getETime() << endl;
	ofs << "---- 停车时长：" << it->second.getTSpan() << endl;
	ofs << "---- 合计费用：" << it->second.getMoney() << endl;
	ofs << "---- 单号：" << it->second.getOrderNp() << endl;
	ofs.close();
	
	// 写入系统内部文档
	ofstream ofs1("order.txt", ios::app);
	ofs1 << "---- 车牌号：" << it->second.getCarNo() << endl;
	ofs1 << "---- 车位号：" << it->second.getParkNum() << endl;
	ofs1 << "---- 停入时间：" << it->second.getBTime() << endl;
	ofs1 << "---- 驶出时间：" << it->second.getETime() << endl;
	ofs1 << "---- 停车时长：" << it->second.getTSpan() << endl;
	ofs1 << "---- 合计费用：" << it->second.getMoney() << endl;
	ofs1 << "---- 单号：" << it->second.getOrderNp() << endl;
	ofs1 << "---- ---- ---- ---- ---- ----" << endl;
	ofs1.close();
	// 打印到屏幕
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "---- 车牌号：" << it->second.getCarNo() << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "---- 车位号：" << it->second.getParkNum() << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "---- 停入时间：" << it->second.getBTime() << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "---- 驶出时间：" << it->second.getETime() << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "---- 停车时长：" << it->second.getTSpan() << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "---- 合计费用：" << it->second.getMoney() << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "---- 单号：" << it->second.getOrderNp() << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;

	this->emptyPark[it->second.getParkNum()] = false;
	// 如果便道没车，剩余车位加1
	if (!this->access.empty()) {
		this->occupied_place += 1;

	} else {
		// 便道第一辆车入库
		this->CarIN(this->OUTaccess());
	}
	// 将车辆从停车场删除
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
