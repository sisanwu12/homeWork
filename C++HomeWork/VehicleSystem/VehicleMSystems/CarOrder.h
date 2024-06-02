#pragma once
#include "System.h"
#include "Print.h"

// ���ŵ�
class CarOrder :public System {
	string order_np;	// ����
	string car_no;		// ���ƺ�
	int park_num;		// ��λ��
	CTime begin_time;	// ��ʼʱ��
	CTime end_time;		// ����ʱ��
	string time_span;	// ʱ����
	int money;			// ͣ������
	
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
	CTime getNow(); // ��ȡ��ǰʱ��
	string TheTime(CTime time); // ��ӡʱ��
	static bool IsCarNo(string car_no); // �Ƿ�Ϊ�Ϸ����ƺ�
};