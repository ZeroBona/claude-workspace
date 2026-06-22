#include <iostream>
using namespace std;

int main() {
    int month;
    cout << "请输入月份（1-12）：";
    cin >> month;

    switch (month) {
        case 3:
        case 4:
        case 5:
            cout << "🌸 春天" << endl;
            break;
        case 6:
        case 7:
        case 8:
            cout << "☀️ 夏天" << endl;
            break;
        case 9:
        case 10:
        case 11:
            cout << "🍂 秋天" << endl;
            break;
        case 12:
        case 1:
        case 2:
            cout << "❄️ 冬天" << endl;
            break;
        default:
            cout << "❌ 月份输入错误！" << endl;
            break;
    }

    return 0;
}
