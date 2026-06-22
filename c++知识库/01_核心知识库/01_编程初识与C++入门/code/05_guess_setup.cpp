#include <iostream>
using namespace std;

int main() {
    int guess;

    cout << "=== 猜数字游戏 ===" << endl;
    cout << "我想了一个 1~10 之间的数字。" << endl;
    cout << "你能猜到是多少吗？" << endl;
    cout << "（提示：这次答案是 7）" << endl;
    cout << "请输入你的猜测：";

    cin >> guess;

    cout << "你猜的是：" << guess << endl;
    cout << "正确答案是：7" << endl;

    if (guess == 7) {
        cout << "🎉 猜对了！你好厉害！" << endl;
    } else {
        cout << "😅 猜错了，下次加油！" << endl;
    }

    return 0;
}
