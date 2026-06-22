#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // 追加写入
    ofstream fout("log.txt", ios::app);
    fout << "程序运行了一次" << endl;
    fout.close();

    // 读取并显示全部日志
    ifstream fin("log.txt");
    string line;
    cout << "=== 运行记录 ===" << endl;
    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();

    return 0;
}
