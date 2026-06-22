#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    char oldChar, newChar;

    cout << "请输入字符串：";
    getline(cin, s);
    cout << "要替换的字符：";
    cin >> oldChar;
    cout << "替换为：";
    cin >> newChar;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == oldChar) {
            s[i] = newChar;
        }
    }

    cout << "替换后：" << s << endl;

    return 0;
}
