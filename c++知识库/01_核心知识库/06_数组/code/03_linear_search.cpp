#include <iostream>
using namespace std;

int main() {
    int arr[] = {4, 7, 2, 9, 5, 1, 8, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target;
    cout << "请输入要查找的数字：";
    cin >> target;

    int found = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        cout << target << " 找到了！位置在：" << found << endl;
    } else {
        cout << target << " 不在数组中" << endl;
    }

    return 0;
}
