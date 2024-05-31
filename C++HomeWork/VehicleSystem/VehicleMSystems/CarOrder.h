#pragma once
#include "System.h"
#include "Print.h"

// ���ŵ�
class CarOrder :public System {
	string order_np;	// ����
	string car_no;		// ���ƺ�
	CTime begin_time;	// ��ʼʱ��
	CTime end_time;		// ����ʱ��
	string time_span;	// ʱ����
	int money;			// ͣ������
	
public:
	CarOrder(string& car_no);
	string getOrderNp();
	string getCarNo();
	string getBTime();
	string getETime();
	string getTSpan();
	int getMoney();
	void setEndTime();
	void setMoney();
	CTime getNow(); // ��ȡ��ǰʱ��
	string TheTime(CTime time); // ��ӡʱ��
	static bool IsCarNo(string car_no); // �Ƿ�Ϊ�Ϸ����ƺ�
};