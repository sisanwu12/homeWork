#include "CarOrder.h"

void CarOrder::setEndTime() {
	this->end_time = this->getNow();
}

void CarOrder::setMoney() {
	// CTimeSpan��ʾʱ���ȣ���ATLģ����ṩ
	CTimeSpan Dif(this->end_time.GetTime() - this->end_time.GetTime());
	int Day = Dif.GetDays();
	// ����40������һ��Сʱ
	int Hour = Dif.GetMinutes() > 40 ? Dif.GetHours() + 1 : Dif.GetHours();
	// ��ͣ��ʱ�����ַ�������time_span��Ա�����У��Ա��ӡ
	this->time_span = to_string(Day) + " �� " + to_string(Hour) + " ʱ";
	if (Dif.GetDays() == 0) {
		if (Hour <= 3) this->money = 0;
		// ����3Сʱ�Ĳ���ÿСʱ3Ԫ
		else this->money = 3 * (Hour - 3);
	} else {
		// ����һ�죬��һ��20��Сʱ�շ�
		this->money = 3 * (Hour + Day * 20);
	}
}

CarOrder::CarOrder(string& car_no) : car_no(car_no),begin_time(getNow()),money(0) {
	order_np = "order_" + to_string(begin_time.GetYear()) + "/" + to_string(begin_time.GetMonth()) + "/" + to_string(begin_time.GetDay()) + "_" + to_string(begin_time.GetHour()) + ":" + to_string(begin_time.GetMinute()) + ":" + to_string(begin_time.GetSecond());
}

string CarOrder::getOrderNp() { return this->order_np; }
string CarOrder::getCarNo(){return this->car_no;}
string CarOrder::getBTime() { return this->TheTime(this->begin_time); }
string CarOrder::getETime() { return this->TheTime(this->end_time); }
string CarOrder::getTSpan() { return this->time_span; }
int CarOrder::getMoney() { return this->money; }


CTime CarOrder::getNow() {
	// ��ȡ��ǰʱ�䣬�� CTime�� �ṩ
	CTime time = CTime::GetCurrentTime();
	return time;
}

string CarOrder::TheTime(CTime time) {
	string t = to_string(time.GetYear() ) + " �� " + to_string(time.GetMonth()) + " �� " + to_string(time.GetDay()) + " �� " + to_string(time.GetHour()) + " ʱ " + to_string(time.GetMinute()) + " �� " + to_string(time.GetSecond()) + " ��";
	return t;
}

bool CarOrder::IsCarNo(string car_no) {
	// ������ʽƥ�䳵�ƺ�
	// ���� ^ ��ʾƥ���ַ����Ŀ�ʼλ��
	// ���� $ ��ʾƥ���ַ����Ľ���λ��
	// (a|b|c){n} ��ʾǰ n ���ַ�����Ϊ a,b,c �е�һ��
	// [A-Z]{n} ��ʾǰ n ���ַ�����Ϊ��д��ĸ A �� Z �е�һ��
	// [A - Z0 - 9]{n} ��ʾǰ n ���ַ�����Ϊ��д��ĸ A �� Z �Լ����� 1 �� 9 �е�һ��
	// ���µ�������ʽ��������ƥ�䳵�ƺţ���һ���ַ�Ϊʡ����д���ڶ����ַ�Ϊ��д��ĸ��������ַ�Ϊ��д��ĸ�����֣�

	regex pattern("^(��|��|��|��|��|ԥ|��|��|��|��|��|³|��|��|��|��|��|��|��|��|��|��|��|��|��|��|��|��|��|��|��|��|̨){1} [A - Z]{1} [A - Z0 - 9]{5}$");

	// regex_match(a,b) �� <regex> �ṩ�ĺ����������ж� a �ַ����Ƿ����� b ���������ʽ

	return regex_match(car_no, pattern);
}