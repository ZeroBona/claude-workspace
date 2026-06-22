#include <iostream>
using namespace std;

struct Student {
    string name;
    double score;
};

int main() {
    Student students[5] = {
        {"小明", 85}, {"小红", 92}, {"小刚", 78},
        {"小丽", 96}, {"小华", 88}
    };

    double sum = 0, maxScore = 0;
    string maxName;

    for (int i = 0; i < 5; i++) {
        sum += students[i].score;
        if (students[i].score > maxScore) {
            maxScore = students[i].score;
            maxName = students[i].name;
        }
        cout << students[i].name << "：" << students[i].score << "分" << endl;
    }

    cout << "\n平均分：" << sum / 5 << endl;
    cout << "最高分：" << maxName << " " << maxScore << "分" << endl;

    return 0;
}
