#include <iostream>
#include <vector>
#include <ctime>//���ڻ�ȡ��ǰʱ��
#include <string>
#include<fstream>
using namespace std;

class CarOrder //���ڴ洢�����Ķ�����Ϣ�������š����ƺš���ʼ������ʱ�䡢���ã�
{
public:
    string order_np;//����
    string car_no;//���ƺ�
    time_t begin_time;//��ʼʱ��
    time_t end_time;//�뿪ʱ��
    int money;//����

    CarOrder(const string& car_no) : car_no(car_no), begin_time(time(nullptr)), money(0)
    {
        order_np = "order_" + std::to_string(begin_time);
    }//���캯������һ�����ƺ���Ϊ����������ʼ�������š���ʼʱ��ͷ��á�
};

class Parking //���ڹ���ͣ��������Ϣ����ͣ��λ����ռ�õ�ͣ��λ�Ͷ����б�
{
public:
    int all_place;//��ͣ��λ
    int occupied_place;//��ͣͣ��λ
    vector<CarOrder> orders;

    Parking(int all_place) : all_place(all_place), occupied_place(0) {}

    /*
     carIn�������ڴ���������ͣ�����Ĳ�����
     ���ͣ����δ�����򴴽�һ���µ�CarOrder���󲢽�����ӵ������б��У�
     ���������ʾ��Ϣ��ʾͣ����������
     */
    void carIn(const string& car_no)
    {
        if (occupied_place < all_place)
        {
            CarOrder new_order(car_no);
            orders.push_back(new_order);
            occupied_place++;
            cout << "��������ɹ������ƺţ�" << car_no << "��Ӧͣλ�ã�" << new_order.order_np << endl;
        }
        else
        {
            cout << "�����������޷����롣" << endl;
        }
    }
    /*
    carOut�������ڴ������뿪ͣ�����Ĳ�����
    ��������Ķ������ڶ����б��в��Ҷ�Ӧ��CarOrder����
    ����ͣ�����ò��Ӷ����б����Ƴ��ö���
    */
    void carOut(const string& order_np)
    {
        for (auto it = orders.begin(); it != orders.end(); ++it)
        {
            if (it->order_np == order_np)
            {
                it->end_time = time(nullptr);
                int duration = it->end_time - it->begin_time;
                it->money = duration * 10; // ����ÿСʱ�շ�10Ԫ
                occupied_place--;
                cout << "�����뿪�ɹ������ƺţ�" << it->car_no << "��ͣ�����ã�" << it->money << "Ԫ" << endl;
                orders.erase(it);
                return;
            }
        }
        cout << "δ�ҵ���Ӧ��ͣ������" << endl;
    }
};
/*
 ���ڷ���ͣ������ͣ�������
 parkAnaly��������һ��Parking������Ϊ������
 ��2Сʱһ��ʱ��ν��з���ͣ����������ͣ�������
*/
class Analy
{
public:
    static void parkAnaly(const Parking& parking)
    {
        // ��2Сʱһ��ʱ��ν��з���ͣ����������ͣ��״��
        // �������ʾ����ʵ��Ӧ������Ҫ���ݾ����������ʵ��
        cout << "��ʱ��η���ͣ�������" << endl;
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
            cout << i << "����" << (i + 2) << "�㣺����" << count << "����ͣ��" << endl;
        }
    }
};
/*
 ����ģ��ͣ������ϵͳ�����С�
*/
class Task {
public:
    static void start()
    {
        Parking parking(100); // ���賵����ͣ��λΪ100��
        int choice;
        while (true)
        {
            cout << "===========��ӭ�����ͣ��������ϵͳ��===========" << endl << endl;
            cout << "1.������վ�Ǽ� 2.������վ�Ǽ� 3.��λ״̬��ʾ 4.�˳�ϵͳ" << endl;
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                string car_no;
                cout << "�����복�ƺţ�";
                cin >> car_no;
                parking.carIn(car_no);
                break;
            }
            case 2:
            {
                string order_np;
                cout << "������ó��ڳ�����λ�ã�";
                cin >> order_np;
                parking.carOut(order_np);
                break;
            }
            case 3:
            {
                cout << "������ͣ��λ��" << parking.all_place << endl;
                cout << "��ǰ��ͣ����������" << parking.occupied_place << endl;
                break;
            }
            case 4:
            {
                cout << "�˳�ϵͳ��" << endl;
                return;
            }
            default:
            {
                cout << "��Ч��ѡ�����������롣" << endl;
                break;
            }
            }
        }
    }
};

int main()
{
    Task::start();//����ͣ��������ϵͳ
    return 0;
}