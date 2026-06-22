#include <iostream>
using namespace std;

int main() {
    string name;
    int age;
    double score;
    char grade;

    cout << "请输入你的姓名：";
    cin >> name;

    cout << "请输入你的年龄：";
    cin >> age;

    cout << "请输入你的数学成绩：";
    cin >> score;

    cout << "请输入你的等级（A/B/C/D）：";
    cin >> grade;

    cout << endl;
    cout << "=== 学生信息 ===" << endl;
    cout << "姓名：" << name << endl;
    cout << "年龄：" << age << "岁" << endl;
    cout << "数学成绩：" << score << "分" << endl;
    cout << "等级：" << grade << endl;

    return 0;
}
