#include <iostream>
using namespace std;

int main() {
    // 定义变量
    int age = 12;
    double height = 155.5;
    char grade = 'A';
    bool isStudent = true;
    string name = "小明";

    // 输出变量的值
    cout << "姓名：" << name << endl;
    cout << "年龄：" << age << "岁" << endl;
    cout << "身高：" << height << "cm" << endl;
    cout << "成绩等级：" << grade << endl;
    cout << "是学生吗？" << isStudent << "（1表示真，0表示假）" << endl;

    return 0;
}
