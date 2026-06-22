#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 3, c = 2;

    // 不加括号
    int r1 = a + b * c;
    cout << "a + b * c = " << r1 << "  （先乘后加）" << endl;

    // 加括号改变顺序
    int r2 = (a + b) * c;
    cout << "(a + b) * c = " << r2 << endl;

    // 混合逻辑运算
    int age = 15;
    bool r3 = age >= 10 && age < 20 || age == 5;
    cout << "age>=10 && age<20 || age==5 → " << r3 << endl;

    // 拿不准就加括号，更清楚！
    bool r4 = (age >= 10 && age < 20) || (age == 5);
    cout << "(age>=10 && age<20) || (age==5) → " << r4 << endl;

    return 0;
}
