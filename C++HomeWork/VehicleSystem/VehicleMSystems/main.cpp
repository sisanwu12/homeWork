#include <iostream>
#include <vector>
#include <ctime>//用于获取当前时间
#include <string>
#include<fstream>
using namespace std;

class CarOrder //用于存储车辆的订单信息（订单号、车牌号、开始、结束时间、费用）
{
public:
    string order_np;//单号
    string car_no;//车牌号
    time_t begin_time;//开始时间
    time_t end_time;//离开时间
    int money;//费用

    CarOrder(const string& car_no) : car_no(car_no), begin_time(time(nullptr)), money(0)
    {
        order_np = "order_" + std::to_string(begin_time);
    }//构造函数接收一个车牌号作为参数，并初始化订单号、开始时间和费用。
};

class Parking //用于管理停车场的信息（总停车位、已占用的停车位和订单列表）
{
public:
    int all_place;//总停车位
    int occupied_place;//已停停车位
    vector<CarOrder> orders;

    Parking(int all_place) : all_place(all_place), occupied_place(0) {}

    /*
     carIn函数用于处理车辆进入停车场的操作，
     如果停车场未满，则创建一个新的CarOrder对象并将其添加到订单列表中；
     否则，输出提示信息表示停车场已满。
     */
    void carIn(const string& car_no)
    {
        if (occupied_place < all_place)
        {
            CarOrder new_order(car_no);
            orders.push_back(new_order);
            occupied_place++;
            cout << "车辆进入成功，车牌号：" << car_no << "，应停位置：" << new_order.order_np << endl;
        }
        else
        {
            cout << "车场已满，无法进入。" << endl;
        }
    }
    /*
    carOut函数用于处理车辆离开停车场的操作，
    根据输入的订单号在订单列表中查找对应的CarOrder对象，
    计算停车费用并从订单列表中移除该对象。
    */
    void carOut(const string& order_np)
    {
        for (auto it = orders.begin(); it != orders.end(); ++it)
        {
            if (it->order_np == order_np)
            {
                it->end_time = time(nullptr);
                int duration = it->end_time - it->begin_time;
                it->money = duration * 10; // 假设每小时收费10元
                occupied_place--;
                cout << "车辆离开成功，车牌号：" << it->car_no << "，停车费用：" << it->money << "元" << endl;
                orders.erase(it);
                return;
            }
        }
        cout << "未找到对应的停车单。" << endl;
    }
};
/*
 用于分析停车场的停车情况。
 parkAnaly函数接收一个Parking对象作为参数，
 按2小时一个时间段进行分析停车场车辆的停车情况。
*/
class Analy
{
public:
    static void parkAnaly(const Parking& parking)
    {
        // 按2小时一个时间段进行分析停车场车辆的停车状况
        // 这里仅作示例，实际应用中需要根据具体需求进行实现
        cout << "按时间段分析停车情况：" << endl;
        for (int i = 0; i < 24; i += 2)
        {
            int count = 0;
            for (const auto& order : parking.orders)
            {
                if (i <= (order.end_time - order.begin_time) / 3600 && (order.end_time - order.begin_time) / 3600 < (i + 2))
                {
                    count++;
                }
            }
            cout << i << "点至" << (i + 2) << "点：共有" << count << "辆车停放" << endl;
        }
    }
};
/*
 用于模拟停车管理系统的运行。
*/
class Task {
public:
    static void start()
    {
        Parking parking(100); // 假设车场总停车位为100个
        int choice;
        while (true)
        {
            cout << "===========欢迎你进入停车场管理系统！===========" << endl << endl;
            cout << "1.汽车进站登记 2.汽车出站登记 3.车位状态显示 4.退出系统" << endl;
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                string car_no;
                cout << "请输入车牌号：";
                cin >> car_no;
                parking.carIn(car_no);
                break;
            }
            case 2:
            {
                string order_np;
                cout << "请输入该车在车场的位置：";
                cin >> order_np;
                parking.carOut(order_np);
                break;
            }
            case 3:
            {
                cout << "车场总停车位：" << parking.all_place << endl;
                cout << "当前已停车的数量：" << parking.occupied_place << endl;
                break;
            }
            case 4:
            {
                cout << "退出系统。" << endl;
                return;
            }
            default:
            {
                cout << "无效的选择，请重新输入。" << endl;
                break;
            }
            }
        }
    }
};

int main()
{
    Task::start();//启动停车场管理系统
    return 0;
}