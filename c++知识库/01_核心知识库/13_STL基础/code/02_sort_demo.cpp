#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {5, 2, 8, 1, 9, 3, 7};

    cout << "排序前：";
    for (int x : v) cout << x << " ";
    cout << endl;

    sort(v.begin(), v.end());
    cout << "从小到大：";
    for (int x : v) cout << x << " ";
    cout << endl;

    sort(v.begin(), v.end(), greater<int>());
    cout << "从大到小：";
    for (int x : v) cout << x << " ";
    cout << endl;

    return 0;
}
