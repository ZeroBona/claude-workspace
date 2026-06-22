#include <iostream>
using namespace std;

int main() {
    int score;
    cout << "请输入成绩（0-100）：";
    cin >> score;

    if (score < 0 || score > 100) {
        cout << "❌ 成绩必须在 0-100 之间！" << endl;
    } else if (score >= 90) {
        cout << "等级：A —— 优秀！🌟" << endl;
    } else if (score >= 80) {
        cout << "等级：B —— 良好！👍" << endl;
    } else if (score >= 70) {
        cout << "等级：C —— 中等" << endl;
    } else if (score >= 60) {
        cout << "等级：D —— 及格" << endl;
    } else {
        cout << "等级：E —— 不及格，加油哦 💪" << endl;
    }

    return 0;
}
