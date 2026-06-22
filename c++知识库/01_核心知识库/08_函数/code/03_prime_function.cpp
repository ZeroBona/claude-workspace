#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void printPrime(int n) {
    if (isPrime(n)) {
        cout << n << " 是素数 ✅" << endl;
    } else {
        cout << n << " 不是素数 ❌" << endl;
    }
}

int main() {
    printPrime(7);
    printPrime(10);

    cout << "\n2~50 之间的素数：";
    for (int i = 2; i <= 50; i++) {
        if (isPrime(i)) cout << i << " ";
    }
    cout << endl;

    return 0;
}
