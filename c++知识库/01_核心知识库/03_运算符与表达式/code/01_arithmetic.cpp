#include <iostream>
using namespace std;

int main() {
    int a = 17, b = 5;

    cout << "a = " << a << ", b = " << b << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << "（注意！整数除法去掉了小数）" << endl;
    cout << "a % b = " << a % b << "（余数）" << endl;

    double c = 17.0;
    cout << "c / b = " << c / b << "（用小数除就有小数部分了）" << endl;

    return 0;
}
