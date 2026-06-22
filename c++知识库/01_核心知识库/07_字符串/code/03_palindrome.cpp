#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "请输入一个字符串：";
    cin >> s;

    bool isPalindrome = true;

    for (int i = 0; i < s.length() / 2; i++) {
        if (s[i] != s[s.length() - 1 - i]) {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome) {
        cout << s << " 是回文 ✅" << endl;
    } else {
        cout << s << " 不是回文 ❌" << endl;
    }

    return 0;
}
