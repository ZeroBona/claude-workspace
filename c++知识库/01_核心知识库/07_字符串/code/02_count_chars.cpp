#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s;
    cout << "请输入一行文字：";
    getline(cin, s);

    int letters = 0, digits = 0, spaces = 0, others = 0;

    for (int i = 0; i < s.length(); i++) {
        if (isalpha(s[i])) letters++;
        else if (isdigit(s[i])) digits++;
        else if (isspace(s[i])) spaces++;
        else others++;
    }

    cout << "字母：" << letters << "个" << endl;
    cout << "数字：" << digits << "个" << endl;
    cout << "空格：" << spaces << "个" << endl;
    cout << "其他：" << others << "个" << endl;

    return 0;
}
