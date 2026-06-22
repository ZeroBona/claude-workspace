#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};

    cout << "第一个元素：" << arr[0] << endl;
    cout << "第三个元素：" << arr[2] << endl;

    arr[1] = 99;
    cout << "修改后第二个元素：" << arr[1] << endl;

    cout << "数组全部元素：";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int scores[3];
    cout << "请输入3个成绩：";
    for (int i = 0; i < 3; i++) {
        cin >> scores[i];
    }
    cout << "你输入的成绩：";
    for (int i = 0; i < 3; i++) {
        cout << scores[i] << " ";
    }
    cout << endl;

    return 0;
}
