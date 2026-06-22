#include <iostream>
using namespace std;

int main() {
    int num, year;

    // 判断奇偶
    cout << "请输入一个整数：";
    cin >> num;
    bool isEven = num % 2 == 0;
    cout << num << "是" << (isEven ? "偶数" : "奇数") << endl;

    cout << endl;

    // 判断闰年
    cout << "请输入年份：";
    cin >> year;
    bool isLeap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    cout << year << "年" << (isLeap ? "是" : "不是") << "闰年" << endl;

    return 0;
}
