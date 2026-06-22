#include <iostream>
using namespace std;

class Dog {
public:
    Dog(string n, int a) {
        name = n;
        age = a;
    }

    void bark() {
        cout << name << "：汪汪！" << endl;
    }

    void showInfo() {
        cout << name << "，" << age << "岁" << endl;
    }

private:
    string name;
    int age;
};

int main() {
    Dog dog1("小白", 2);
    Dog dog2("旺财", 3);

    dog1.showInfo();
    dog1.bark();

    cout << endl;

    dog2.showInfo();
    dog2.bark();

    return 0;
}
