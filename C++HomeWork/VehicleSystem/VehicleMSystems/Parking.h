#pragma once
#include "System.h"
#include "CarOrder.h"

class Parking :public System 
{
	int all_place;				// ��ͣ��λ
	int occupied_place;			// ʣ��ͣ��λ
	bool emptyPark[1000000];	// ��λ�ż�¼
	queue<string>* access;		// ͣ�������
	map<string, CarOrder>* park;	// ͣ��λ����Ϊ���ƺţ�ֵΪ������
public:
	Parking(int all_place);
	~Parking();
	void setInit(CarOrder* car,int parknum);	// ��ʼ��ͣ����
	void CarIN(string car_no);					// ����ͣ�뺯��
	void INaccess(string car_no);				// ��������
	void CarOUT(string car_no);					// ����ʻ������
	string OUTaccess();							// ���������
	int getAccessLen();							// ��ȡ������Ⱥ���
	bool ISAccess();							// �жϱ���Ƿ�Ϊ�պ���
	map<string, CarOrder>* getPark();			// ��ȡͣ�����ݺ���
	int getParkNum();							// ��ȡ��λ�ź���
	int getAllPlace();							// ��ȡ��ͣ��λ
};