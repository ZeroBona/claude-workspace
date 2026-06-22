#include <iostream>
using namespace std;

int main() {
    int score;
    cout << "请输入考试成绩：";
    cin >> score;

    if (score >= 60) {
        cout << "🎉 及格了！" << endl;
    } else {
        cout << "💪 不及格，继续加油！" << endl;
    }

    cout << "程序结束" << endl;

    return 0;
}
