#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // 写入一些数字
    ofstream fout("numbers.txt");
    int nums[] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++) {
        fout << nums[i] << " ";
    }
    fout.close();

    // 读取并计算
    ifstream fin("numbers.txt");
    int x, sum = 0, count = 0;
    while (fin >> x) {
        cout << x << " ";
        sum += x;
        count++;
    }
    fin.close();

    cout << "\n个数：" << count << " 总和：" << sum << endl;

    return 0;
}
