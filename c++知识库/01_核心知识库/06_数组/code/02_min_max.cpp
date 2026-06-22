#include <iostream>
using namespace std;

int main() {
    const int N = 5;
    int scores[N];

    cout << "请输入" << N << "个成绩：";
    for (int i = 0; i < N; i++) {
        cin >> scores[i];
    }

    int maxScore = scores[0];
    int minScore = scores[0];

    for (int i = 1; i < N; i++) {
        if (scores[i] > maxScore) maxScore = scores[i];
        if (scores[i] < minScore) minScore = scores[i];
    }

    cout << "最高分：" << maxScore << endl;
    cout << "最低分：" << minScore << endl;

    return 0;
}
