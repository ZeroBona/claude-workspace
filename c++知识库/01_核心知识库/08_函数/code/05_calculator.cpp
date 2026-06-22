#include <iostream>
using namespace std;

double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) {
    if (b == 0) {
        cout << "❌ 不能除以0！";
        return 0;
    }
    return a / b;
}

int main() {
    double x, y;
    char op;

    cout << "输入格式：数字 运算符 数字" << endl;
    cin >> x >> op >> y;

    double result;
    switch (op) {
        case '+': result = add(x, y); break;
        case '-': result = subtract(x, y); break;
        case '*': result = multiply(x, y); break;
        case '/': result = divide(x, y); break;
        default: cout << "不支持的运算符" << endl; return 0;
    }

    cout << x << " " << op << " " << y << " = " << result << endl;
    return 0;
}
