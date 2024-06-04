#include "CarOrder.h"

// string ת��Ϊ wstring
static wstring string2wstring(string str) {
	wstring result;
	int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), NULL, 0);
	if (len < 0)return result;
	wchar_t* buffer = new wchar_t[len + 1];
	if (buffer == NULL)return result;
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), buffer, len);
	buffer[len] = '\0';
	result.append(buffer);
	delete[] buffer;
	return result;
}

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

CarOrder::CarOrder(string& car_no,int park_num) : car_no(car_no),begin_time(getNow()),money(0),park_num(park_num) {
	order_np = "order_" + to_string(this->begin_time.GetTime());
}

string CarOrder::getOrderNp() { return this->order_np; }
string CarOrder::getCarNo(){return this->car_no;}
string CarOrder::getBTime() { return this->TheTime(this->begin_time); }
string CarOrder::getETime() { return this->TheTime(this->end_time); }
string CarOrder::getTSpan() { return this->time_span; }
int CarOrder::getMoney() { return this->money; }
int CarOrder::getParkNum() { return this->park_num; }

void CarOrder::setOrderNP() {
	this->order_np = "order_" + to_string(this->begin_time.GetTime());
}

void CarOrder::setBeginTime(string time) {
	__time64_t t = stoi(time);
	this->begin_time = CTime(t);
}

CTime CarOrder::getNow() {
	// ��ȡ��ǰʱ�䣬�� CTime�� �ṩ
	CTime time = CTime::GetTickCount();
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
	// [A-Z] ��ʾ�ַ�����Ϊ��д��ĸ A �� Z �е�һ��
	// ���µ�������ʽ��������ƥ�䳵�ƺţ���һ���ַ�Ϊʡ����д���ڶ����ַ�Ϊ��д��ĸ��������ַ�Ϊ��д��ĸ�����֣�
	// �Լ�����Դ�����ĳ��ƺ�
	// wstring�Ǽ������ĵ�string����������Ŀǰc++��û������ wstring �Ĺ���
	// ��Ҫ���� string �������ַ������ٵ���to_wstring����(�Լ�ʵ�֣�c++û���ṩ)
	wstring str = string2wstring(car_no);
	// ��ͨ����+����Դ
	wregex regRule(L"^(([�����弽ԥ���ɺ�����³������Ӷ���ʽ����¼���������ش�����ʹ��][A-Z](([0-9]{5}[DF])|([DF]([A-HJ-NP-Z0-9])[0-9]{4})))|([�����弽ԥ���ɺ�����³������Ӷ���ʽ����¼���������ش�����ʹ��][A-Z][A-HJ-NP-Z0-9]{4}[A-HJ-NP-Z0-9��ѧ���۰�ʹ��]))$");
	wsmatch matchResult;
	wstring::const_iterator iterStart = str.begin();
	wstring::const_iterator iterEnd = str.end();
	//DebugView(str, matchResult, regRule);
	return (regex_search(iterStart, iterEnd, matchResult, regRule));
}