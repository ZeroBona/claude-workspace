#include <iostream>
using namespace std;

void printSeparator() {
    cout << "====================" << endl;
}

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int main() {
    printSeparator();
    cout << "3 和 5 中较大的是：" << max(3, 5) << endl;
    printSeparator();
    cout << "10 和 7 中较大的是：" << max(10, 7) << endl;
    printSeparator();
    return 0;
}
