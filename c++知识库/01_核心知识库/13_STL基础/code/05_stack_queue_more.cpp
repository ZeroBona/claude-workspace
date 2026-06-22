#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    cout << "=== 栈的应用：进制转换 ===" << endl;
    int n = 42;
    stack<int> s;
    while (n > 0) {
        s.push(n % 2);
        n /= 2;
    }
    cout << "42 的二进制：";
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl << endl;

    cout << "=== 队列的应用：打印队列 ===" << endl;
    queue<string> q;
    q.push("第1个");
    q.push("第2个");
    q.push("第3个");

    while (!q.empty()) {
        cout << "处理：" << q.front() << endl;
        q.pop();
    }

    return 0;
}
