#pragma once
#include "System.h"
#include "CarOrder.h"

class Parking :public System 
{
	int all_place;				// ��ͣ��λ
	int occupied_place;			// ʣ��ͣ��λ
	map<string, CarOrder> park;	// ͣ��λ����Ϊ���ƺţ�ֵΪ������
public:
	Parking(int all_place);
	void CarIN(string car_no);
	void CarOUT(string car_no);
};