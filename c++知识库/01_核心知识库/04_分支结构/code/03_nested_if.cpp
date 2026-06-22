#include <iostream>
using namespace std;

int main() {
    int age, height;

    cout << "=== 游乐园门票系统 ===" << endl;
    cout << "请输入年龄：";
    cin >> age;
    cout << "请输入身高（cm）：";
    cin >> height;

    if (age >= 12) {
        if (height >= 140) {
            cout << "🎉 你可以玩过山车！" << endl;
        } else {
            cout << "😅 身高不够140cm，不能玩过山车" << endl;
            cout << "但你可以玩其他项目！" << endl;
        }
    } else if (age >= 6) {
        if (height >= 120) {
            cout << "🎉 你可以玩儿童过山车！" << endl;
        } else {
            cout << "😅 身高不够，先去玩旋转木马吧" << endl;
        }
    } else {
        cout << "👶 你太小了，去儿童乐园玩吧" << endl;
    }

    return 0;
}
