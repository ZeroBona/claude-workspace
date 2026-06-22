#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int target = rand() % 100 + 1;
    int guess;

    cout << "=== 猜数字游戏 ===" << endl;
    cout << "我心里想了一个 1~100 的数字" << endl;

    do {
        cout << "猜一个数：";
        cin >> guess;

        if (guess > target) {
            cout << "太大了！" << endl;
        } else if (guess < target) {
            cout << "太小了！" << endl;
        }
    } while (guess != target);

    cout << "🎉 猜对了！太棒了！" << endl;

    return 0;
}
