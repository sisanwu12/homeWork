#include "CarOrder.h"

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
	// 获取当前时间，由 CTime类 提供
	CTime time = CTime::GetCurrentTime();
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
	// (a|b|c){n} 表示前 n 个字符必须为 a,b,c 中的一个
	// [A-Z]{n} 表示前 n 个字符必须为大写字母 A 到 Z 中的一个
	// [A - Z0 - 9]{n} 表示前 n 个字符必须为大写字母 A 到 Z 以及数字 1 到 9 中的一个
	// 以下的正则表达式可以用来匹配车牌号（第一个字符为省份缩写，第二个字符为大写字母，后五个字符为大写字母或数字）

	regex pattern("^(京|津|沪|渝|冀|豫|云|辽|黑|湘|皖|鲁|新|苏|浙|赣|鄂|桂|晋|蒙|陕|吉|闽|贵|粤|青|藏|川|宁|琼|港|澳|台){1} [A - Z]{1} [A - Z0 - 9]{5}$");

	// regex_match(a,b) 是 <regex> 提供的函数，用于判断 a 字符串是否满足 b 这个正则表达式

	return regex_match(car_no, pattern);
}