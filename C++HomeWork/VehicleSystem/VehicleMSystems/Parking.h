#pragma once
#include "System.h"
#include "CarOrder.h"

class Parking :public System 
{
	int all_place;				// 总停车位
	int occupied_place;			// 剩余停车位
	bool emptyPark[1000000];	// 车位号记录
	queue<string> access;		// 停车场便道
	map<string, CarOrder> park;	// 停车位。键为车牌号，值为车单号
public:
	Parking(int all_place);
	void setInit(CarOrder* car,int parknum);	// 初始化停车场
	void CarIN(string car_no);					// 汽车停入函数
	void INaccess(string car_no);				// 入便道函数
	void CarOUT(string car_no);					// 汽车驶出函数
	string OUTaccess();							// 出便道函数
	queue<string> getAccess();					// 获取便道函数
	map<string, CarOrder> getPark();			// 获取停车数据函数
	int getParkNum();							// 获取车位号函数
	int getAllPlace();							// 获取总停车位
};