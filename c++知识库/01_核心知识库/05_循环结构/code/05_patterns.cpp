#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "请输入图形大小：";
    cin >> n;

    // 矩形
    cout << "\n矩形：" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    // 直角三角形
    cout << "\n直角三角形：" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    // 九九乘法表
    cout << "\n九九乘法表：" << endl;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << "×" << i << "=" << i * j << "\t";
        }
        cout << endl;
    }

    return 0;
}
