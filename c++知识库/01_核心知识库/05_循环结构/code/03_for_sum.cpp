#include <iostream>
using namespace std;

int main() {
    int oddSum = 0;
    int evenSum = 0;

    for (int i = 1; i <= 100; i++) {
        if (i % 2 == 0) {
            evenSum += i;
        } else {
            oddSum += i;
        }
    }

    cout << "1~100 奇数和 = " << oddSum << endl;
    cout << "1~100 偶数和 = " << evenSum << endl;
    cout << "总和 = " << oddSum + evenSum << endl;

    return 0;
}
