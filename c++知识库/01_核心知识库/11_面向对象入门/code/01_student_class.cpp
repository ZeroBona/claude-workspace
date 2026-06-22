#include <iostream>
using namespace std;

class Student {
public:
    Student(string n, int a, double s) {
        name = n;
        age = a;
        score = s;
        count++;
    }

    void sayHello() {
        cout << "大家好，我是" << name << endl;
    }

    void showInfo() {
        cout << name << " " << age << "岁 " << score << "分" << endl;
    }

    static int getCount() { return count; }

private:
    string name;
    int age;
    double score;
    static int count;
};

int Student::count = 0;

int main() {
    Student s1("小明", 13, 95.5);
    Student s2("小红", 12, 88.0);

    s1.sayHello();
    s1.showInfo();
    s2.showInfo();

    cout << "学生总数：" << Student::getCount() << endl;

    return 0;
}
