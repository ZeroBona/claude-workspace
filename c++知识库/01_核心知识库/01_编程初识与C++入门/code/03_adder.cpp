#include <iostream>
using namespace std;

int main() {
    int a, b;

    cout << "=== 加法计算器 ===" << endl;
    cout << "请输入第一个数字：";
    cin >> a;

    cout << "请输入第二个数字：";
    cin >> b;

    int sum = a + b;

    cout << a << " + " << b << " = " << sum << endl;

    return 0;
}
