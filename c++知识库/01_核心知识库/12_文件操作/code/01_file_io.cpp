#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream fout("note.txt");
    fout << "C++ 文件操作学习笔记" << endl;
    fout << "=========================" << endl;
    fout << "1. ofstream 写入" << endl;
    fout << "2. ifstream 读取" << endl;
    fout.close();

    ifstream fin("note.txt");
    string line;
    cout << "文件内容：" << endl;
    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();

    return 0;
}
