#include <iostream>
using namespace std;

int main() {
    // 一条语句输出多段内容
    cout << "姓名：" << "小明" << "，年龄：" << 12 << "岁" << endl;

    // 先算再输出
    cout << "5 + 3 = " << 5 + 3 << endl;
    cout << "12 - 7 = " << 12 - 7 << endl;
    cout << "4 * 6 = " << 4 * 6 << endl;
    cout << "20 / 4 = " << 20 / 4 << endl;

    // 输出特殊字符
    cout << "换行前\n换行后" << endl;
    cout << "用\t可以\t制表（对齐）" << endl;

    return 0;
}
