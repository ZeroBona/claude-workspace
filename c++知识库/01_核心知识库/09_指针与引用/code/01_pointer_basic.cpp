#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int *p = &x;

    cout << "x 的值：" << x << endl;
    cout << "x 的地址：" << &x << endl;
    cout << "p 的值（存的地址）：" << p << endl;
    cout << "p 指向的值：" << *p << endl;

    *p = 20;
    cout << "修改后 x 的值：" << x << endl;

    return 0;
}
