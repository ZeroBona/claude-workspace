#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> scores;

    scores.push_back(85);
    scores.push_back(92);
    scores.push_back(78);
    scores.push_back(96);

    cout << "元素个数：" << scores.size() << endl;
    cout << "第一个：" << scores.front() << " 最后一个：" << scores.back() << endl;

    cout << "所有成绩：";
    for (int i = 0; i < scores.size(); i++) {
        cout << scores[i] << " ";
    }
    cout << endl;

    scores.pop_back();
    cout << "删除后个数：" << scores.size() << endl;

    return 0;
}
