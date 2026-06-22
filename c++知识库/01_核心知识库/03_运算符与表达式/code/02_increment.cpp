#include <iostream>
using namespace std;

int main() {
    int x = 1;

    cout << "初始：x = " << x << endl;
    x++;
    cout << "x++ 后：x = " << x << endl;
    x++;
    cout << "再 x++：x = " << x << endl;
    x--;
    cout << "x-- 后：x = " << x << endl;

    cout << endl;

    // 前置和后置的区别
    int a = 5, b = 5;

    int result1 = a++;   // 先赋值，后自增
    int result2 = ++b;   // 先自增，后赋值

    cout << "a = " << a << ", result1 = a++ = " << result1 << endl;
    cout << "b = " << b << ", result2 = ++b = " << result2 << endl;

    return 0;
}
