#include <iostream>
using namespace std;

int main() {
    double a, b;
    char op;

    cout << "=== 简易计算器 ===" << endl;
    cout << "输入格式：数字 运算符 数字" << endl;
    cout << "例如：5 + 3" << endl;
    cin >> a >> op >> b;

    switch (op) {
        case '+':
            cout << a << " + " << b << " = " << a + b << endl;
            break;
        case '-':
            cout << a << " - " << b << " = " << a - b << endl;
            break;
        case '*':
            cout << a << " * " << b << " = " << a * b << endl;
            break;
        case '/':
            if (b != 0) {
                cout << a << " / " << b << " = " << a / b << endl;
            } else {
                cout << "❌ 除数不能为0！" << endl;
            }
            break;
        default:
            cout << "❌ 不支持的运算符！请用 + - * /" << endl;
            break;
    }

    return 0;
}
