#include <iostream>
using namespace std;

struct Student {
    string name;
    int age;
    double score;
};

int main() {
    Student s1 = {"小明", 13, 95.5};
    Student s2 = {"小红", 12, 88.0};

    cout << "第一名学生：" << s1.name << " " << s1.age << "岁 " << s1.score << "分" << endl;
    cout << "第二名学生：" << s2.name << " " << s2.age << "岁 " << s2.score << "分" << endl;

    s2.score = 92.5;
    cout << s2.name << "的新成绩：" << s2.score << "分" << endl;

    return 0;
}
