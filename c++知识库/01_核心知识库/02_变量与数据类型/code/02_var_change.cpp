#include <iostream>
using namespace std;

int main() {
    int x = 5;

    cout << "一开始，x = " << x << endl;

    x = 10;
    cout << "改成 10，x = " << x << endl;

    x = x + 3;
    cout << "加 3，x = " << x << endl;

    x = x * 2;
    cout << "乘以 2，x = " << x << endl;

    x = x - 8;
    cout << "减 8，x = " << x << endl;

    return 0;
}
