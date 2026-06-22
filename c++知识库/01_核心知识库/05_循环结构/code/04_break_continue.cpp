#include <iostream>
using namespace std;

int main() {
    // break 演示
    cout << "1到20中，第一个能被7整除的数是：";
    for (int i = 1; i <= 20; i++) {
        if (i % 7 == 0) {
            cout << i << endl;
            break;
        }
    }

    // continue 演示
    cout << "1~10，跳过5：";
    for (int i = 1; i <= 10; i++) {
        if (i == 5) {
            continue;
        }
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
