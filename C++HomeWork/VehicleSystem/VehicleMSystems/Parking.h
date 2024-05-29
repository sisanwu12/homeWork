#pragma once
#include "System.h"
#include "CarOrder.h"

class Parking :public System 
{
	int all_place;				// 总停车位
	int occupied_place;			// 剩余停车位
	map<string, CarOrder> park;	// 停车位。键为车牌号，值为车单号
public:
	Parking(int all_place);
	void CarIN(string car_no);
	void CarOUT(string car_no);
};