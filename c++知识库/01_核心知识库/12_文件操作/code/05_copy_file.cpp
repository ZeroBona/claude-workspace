#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename;
    cout << "请输入要复制的文件名：";
    cin >> filename;

    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "文件打开失败！" << endl;
        return 1;
    }

    ofstream fout("copy_" + filename);
    string line;
    while (getline(fin, line)) {
        fout << line << endl;
    }

    fin.close();
    fout.close();

    cout << "文件已复制为 copy_" << filename << endl;

    return 0;
}
