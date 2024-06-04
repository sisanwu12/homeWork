#include "CarOrder.h"

// string 转换为 wstring
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
	// CTimeSpan表示时间跨度，由ATL模板库提供
	CTimeSpan Dif(this->end_time.GetTime() - this->end_time.GetTime());
	int Day = Dif.GetDays();
	// 超过40分钟算一个小时
	int Hour = Dif.GetMinutes() > 40 ? Dif.GetHours() + 1 : Dif.GetHours();
	// 将停车时间以字符串存入time_span成员变量中，以便打印
	this->time_span = to_string(Day) + " 天 " + to_string(Hour) + " 时";
	if (Dif.GetDays() == 0) {
		if (Hour <= 3) this->money = 0;
		// 超过3小时的部分每小时3元
		else this->money = 3 * (Hour - 3);
	} else {
		// 超过一天，算一天20个小时收费
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
	// 获取当前时间，由 CTime类 提供
	CTime time = CTime::GetTickCount();
	return time;
}

string CarOrder::TheTime(CTime time) {
	string t = to_string(time.GetYear() ) + " 年 " + to_string(time.GetMonth()) + " 月 " + to_string(time.GetDay()) + " 日 " + to_string(time.GetHour()) + " 时 " + to_string(time.GetMinute()) + " 分 " + to_string(time.GetSecond()) + " 秒";
	return t;
}

bool CarOrder::IsCarNo(string car_no) {
	// 正则表达式匹配车牌号
	// 符号 ^ 表示匹配字符串的开始位置
	// 符号 $ 表示匹配字符串的结束位置
	// [A-Z] 表示字符必须为大写字母 A 到 Z 中的一个
	// 以下的正则表达式可以用来匹配车牌号（第一个字符为省份缩写，第二个字符为大写字母，后五个字符为大写字母或数字）
	// 以及新能源汽车的车牌号
	// wstring是兼容中文的string容器，不过目前c++并没有完善 wstring 的功能
	// 需要先用 string 来接收字符串，再调用to_wstring函数(自己实现，c++没有提供)
	wstring str = string2wstring(car_no);
	// 普通汽车+新能源
	wregex regRule(L"^(([京津沪渝冀豫云辽黑湘皖鲁新苏浙赣鄂桂甘晋蒙陕吉闽贵粤青藏川宁琼使领][A-Z](([0-9]{5}[DF])|([DF]([A-HJ-NP-Z0-9])[0-9]{4})))|([京津沪渝冀豫云辽黑湘皖鲁新苏浙赣鄂桂甘晋蒙陕吉闽贵粤青藏川宁琼使领][A-Z][A-HJ-NP-Z0-9]{4}[A-HJ-NP-Z0-9挂学警港澳使领]))$");
	wsmatch matchResult;
	wstring::const_iterator iterStart = str.begin();
	wstring::const_iterator iterEnd = str.end();
	//DebugView(str, matchResult, regRule);
	return (regex_search(iterStart, iterEnd, matchResult, regRule));
}