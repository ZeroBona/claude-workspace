#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int b = 20;

    cout << "交换前：a = " << a << "，b = " << b << endl;

    // 用第三个变量来交换
    int temp = a;   // temp = 10
    a = b;          // a = 20
    b = temp;       // b = 10

    cout << "交换后：a = " << a << "，b = " << b << endl;

    return 0;
}
