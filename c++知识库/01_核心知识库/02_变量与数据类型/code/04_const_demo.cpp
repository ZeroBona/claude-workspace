#include <iostream>
using namespace std;

int main() {
    const double PI = 3.14159;
    const int DAYS_IN_YEAR = 365;

    int r;
    cout << "请输入圆的半径：";
    cin >> r;

    double area = PI * r * r;
    double circumference = 2 * PI * r;

    cout << "半径为" << r << "的圆：" << endl;
    cout << "面积 = " << area << endl;
    cout << "周长 = " << circumference << endl;
    cout << "一年有" << DAYS_IN_YEAR << "天" << endl;

    // PI = 3.14;  // 这行如果取消注释会报错！常量不能修改

    return 0;
}
