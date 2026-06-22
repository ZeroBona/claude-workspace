#include <iostream>
using namespace std;

enum Weekday { MON = 1, TUE, WED, THU, FRI, SAT, SUN };

int main() {
    int d;
    cout << "请输入数字（1-7）：";
    cin >> d;

    Weekday day = (Weekday)d;

    switch (day) {
        case MON: cout << "周一：开始学习！" << endl; break;
        case TUE: cout << "周二：继续努力" << endl; break;
        case WED: cout << "周三：过半了" << endl; break;
        case THU: cout << "周四：快周末了" << endl; break;
        case FRI: cout << "周五：明天放假！" << endl; break;
        case SAT: cout << "周六：出去玩！" << endl; break;
        case SUN: cout << "周日：准备新一周" << endl; break;
        default: cout << "输入错误" << endl;
    }

    return 0;
}
