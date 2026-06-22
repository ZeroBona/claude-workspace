#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "Hello";
    string s2 = "World";

    string s3 = s1 + " " + s2;
    cout << "s3 = " << s3 << endl;

    cout << "s3 长度：" << s3.length() << endl;

    cout << "第一个字符：" << s3[0] << endl;
    cout << "最后一个字符：" << s3[s3.length()-1] << endl;

    s3[6] = 'w';
    cout << "修改后：" << s3 << endl;

    cout << "s1 == s2 ? " << (s1 == s2 ? "相等" : "不相等") << endl;

    return 0;
}
