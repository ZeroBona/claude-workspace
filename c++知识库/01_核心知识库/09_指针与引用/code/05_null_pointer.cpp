#include <iostream>
using namespace std;

int main() {
    // 空指针：不指向任何地址的指针
    int *p = nullptr;

    // 使用前先分配地址
    int x = 42;
    p = &x;          // p 现在指向 x

    if (p != nullptr) {
        cout << "p 指向的值：" << *p << endl;
    }

    // 指针的指针（了解）
    int **pp = &p;   // pp 存的是 p 的地址
    cout << "指针的指针：" << **pp << endl;

    return 0;
}
