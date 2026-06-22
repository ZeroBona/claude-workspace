#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    // 栈
    stack<int> s;
    s.push(1); s.push(2); s.push(3);
    cout << "栈（后进先出）：";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    // 队列
    queue<int> q;
    q.push(1); q.push(2); q.push(3);
    cout << "队列（先进先出）：";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
