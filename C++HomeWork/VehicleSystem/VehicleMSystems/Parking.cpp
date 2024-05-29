#include "Parking.h"

Parking::Parking(int all_place):all_place(all_place), occupied_place(all_place) {
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "--- 停车场已初始化成功！" << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "---- 总停车位：" << this->all_place << endl;
	cout << "---- ---- ---- ---- ---- ----" << endl;
}

void Parking::CarIN(string car_no) {
	CarOrder* order = new CarOrder(car_no);
	// 将该车存入停车场
	this->park.insert(pair<string, CarOrder>(order->getCarNo(), *order));
	// 剩余停车位减一
	this->occupied_place -= 1;
	system("cls");
	Print::Welcome();
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "---- 车牌号："<< order->getCarNo() << endl;
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
}

void Parking::CarOUT(string car_no) {
	auto it = this->park.find(car_no);
	// 获取结束时间
	it->second.setEndTime();
	// 计算费用
	it->second.setMoney();
	Print::Bye();
	cout << "---- ---- ---- ---- ---- ----" << endl;
	cout << "---- 车牌号：" << it->second.getCarNo() << endl;
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

	// 写入给用户的小票文档
	ofstream ofs(".\\Order\\user\\" + it->second.getOrderNp() + ".txt", ios::out);
	ofs << "---- 车牌号：" << it->second.getCarNo() << endl;
	ofs << "---- 停入时间：" << it->second.getBTime() << endl;
	ofs << "---- 驶出时间：" << it->second.getETime() << endl;
	ofs << "---- 停车时长：" << it->second.getTSpan() << endl;
	ofs << "---- 合计费用：" << it->second.getMoney() << endl;
	ofs << "---- 单号：" << it->second.getOrderNp() << endl;
	ofs.close();

	// 写入系统内部存储文档，以天为单位
	CTime t = CTime::GetCurrentTime();
	string path = to_string(t.GetYear()) + "/" + to_string(t.GetMonth()) + "/" + to_string(t.GetDay());
	ofstream ofs1(".\\Order\\order\\" + path + ".txt", ios::app);
	ofs1 << "---- 车牌号：" << it->second.getCarNo() << endl;
	ofs1 << "---- 停入时间：" << it->second.getBTime() << endl;
	ofs1 << "---- 驶出时间：" << it->second.getETime() << endl;
	ofs1 << "---- 停车时长：" << it->second.getTSpan() << endl;
	ofs1 << "---- 合计费用：" << it->second.getMoney() << endl;
	ofs1 << "---- 单号：" << it->second.getOrderNp() << endl;
	ofs1 << "---- ---- ---- ---- ---- ----" << endl;
	ofs1.close();
	// 将车辆从停车场删除
	this->park.erase(it);
	// 剩余车位加1
	this->occupied_place += 1;
	Sleep(3000);
}
