#include <iostream>
using namespace std;

int main() {
    const int ROWS = 2;
    const int COLS = 3;

    int matrix[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    cout << "原矩阵：" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\n转置后：" << endl;
    for (int j = 0; j < COLS; j++) {
        for (int i = 0; i < ROWS; i++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
