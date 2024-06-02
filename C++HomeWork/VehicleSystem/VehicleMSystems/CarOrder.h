#pragma once
#include "System.h"
#include "Print.h"

// 车号单
class CarOrder :public System {
	string order_np;	// 单号
	string car_no;		// 车牌号
	int park_num;		// 车位号
	CTime begin_time;	// 开始时间
	CTime end_time;		// 结束时间
	string time_span;	// 时间跨度
	int money;			// 停车费用
	
public:
	CarOrder(string& car_no,int park_num);
	string getOrderNp();
	string getCarNo();
	string getBTime();
	string getETime();
	string getTSpan();
	int getMoney();
	int getParkNum();
	void setOrderNP();
	void setBeginTime(string time);
	void setEndTime();
	void setMoney();
	CTime getNow(); // 获取当前时间
	string TheTime(CTime time); // 打印时间
	static bool IsCarNo(string car_no); // 是否为合法车牌号
};