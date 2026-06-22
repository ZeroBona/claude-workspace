#include <iostream>
using namespace std;

enum Weekday { MON = 1, TUE, WED, THU, FRI, SAT, SUN };

int main() {
    int day;
    cout << "请输入星期几（1-7）：";
    cin >> day;

    Weekday today = (Weekday)day;

    switch (today) {
        case MON: cout << "星期一，开始学习！" << endl; break;
        case TUE: cout << "星期二" << endl; break;
        case WED: cout << "星期三" << endl; break;
        case THU: cout << "星期四" << endl; break;
        case FRI: cout << "星期五，明天放假！" << endl; break;
        case SAT: cout << "星期六，出去玩！" << endl; break;
        case SUN: cout << "星期日，准备上学" << endl; break;
        default: cout << "输入错误" << endl;
    }

    return 0;
}
