#include <iostream>
using namespace std;

void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "  函数内部：a=" << a << ", b=" << b << endl;
}

void swapByRef(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;

    cout << "值传递测试：" << endl;
    cout << "  交换前：x=" << x << ", y=" << y << endl;
    swapByValue(x, y);
    cout << "  交换后：x=" << x << ", y=" << y << "（没变！）" << endl;

    x = 10; y = 20;
    cout << "\n引用传递测试：" << endl;
    cout << "  交换前：x=" << x << ", y=" << y << endl;
    swapByRef(x, y);
    cout << "  交换后：x=" << x << ", y=" << y << "（变了！）" << endl;

    return 0;
}
