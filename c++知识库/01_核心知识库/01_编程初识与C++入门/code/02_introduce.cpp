#include <iostream>
using namespace std;

int main() {
    string name;
    int age;

    cout << "你好！我是电脑小助手。" << endl;
    cout << "你叫什么名字？" << endl;

    cin >> name;

    cout << "你好，" << name << "！你今年几岁了？" << endl;

    cin >> age;

    cout << "哇，" << age << "岁！很高兴认识你，" << name << "！" << endl;

    return 0;
}
