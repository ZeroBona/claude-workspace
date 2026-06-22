#include <iostream>
using namespace std;

int main() {
    int a = 10;

    cout << "初始：" << a << endl;

    a += 5;
    cout << "a += 5  → " << a << endl;

    a -= 3;
    cout << "a -= 3  → " << a << endl;

    a *= 4;
    cout << "a *= 4  → " << a << endl;

    a /= 6;
    cout << "a /= 6  → " << a << endl;

    a %= 3;
    cout << "a %= 3  → " << a << endl;

    return 0;
}
