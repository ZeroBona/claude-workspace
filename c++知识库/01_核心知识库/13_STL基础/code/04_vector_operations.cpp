#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums;

    // 添加数据
    nums.push_back(5);
    nums.push_back(2);
    nums.push_back(8);
    nums.push_back(1);
    nums.push_back(9);

    cout << "原始数据：";
    for (int x : nums) cout << x << " ";
    cout << endl;

    // 排序
    sort(nums.begin(), nums.end());
    cout << "从小到大：";
    for (int x : nums) cout << x << " ";
    cout << endl;

    // 反转
    reverse(nums.begin(), nums.end());
    cout << "从大到小：";
    for (int x : nums) cout << x << " ";
    cout << endl;

    // 查找最大值和最小值
    int maxVal = *max_element(nums.begin(), nums.end());
    int minVal = *min_element(nums.begin(), nums.end());
    cout << "最大值：" << maxVal << " 最小值：" << minVal << endl;

    return 0;
}
