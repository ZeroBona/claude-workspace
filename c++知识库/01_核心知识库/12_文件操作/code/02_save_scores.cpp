#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    string name;
    int score;
};

int main() {
    const int N = 3;
    Student students[N];

    for (int i = 0; i < N; i++) {
        cout << "请输入第" << i+1 << "个学生姓名和成绩：";
        cin >> students[i].name >> students[i].score;
    }

    ofstream fout("scores.txt");
    for (int i = 0; i < N; i++) {
        fout << students[i].name << " " << students[i].score << endl;
    }
    fout.close();
    cout << "成绩已保存到 scores.txt" << endl;

    return 0;
}
