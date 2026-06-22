#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "请输入一句话：";
    getline(cin, s);

    int count = 0;
    bool inWord = false;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ' && !inWord) {
            count++;
            inWord = true;
        } else if (s[i] == ' ') {
            inWord = false;
        }
    }

    cout << "单词数量：" << count << endl;

    return 0;
}
