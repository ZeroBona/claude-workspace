#include <iostream>
using namespace std;

class BankAccount {
public:
    BankAccount(string n, double m) {
        name = n;
        money = m;
    }

    void save(double amount) {
        if (amount > 0) {
            money += amount;
            cout << "存入 " << amount << " 元，余额：" << money << " 元" << endl;
        }
    }

    void take(double amount) {
        if (amount > 0 && amount <= money) {
            money -= amount;
            cout << "取出 " << amount << " 元，余额：" << money << " 元" << endl;
        } else {
            cout << "余额不足！当前余额：" << money << " 元" << endl;
        }
    }

    double getMoney() {
        return money;
    }

private:
    string name;
    double money;
};

int main() {
    BankAccount acc("小明", 1000);

    acc.save(500);
    acc.take(200);
    acc.take(2000);
    cout << "最终余额：" << acc.getMoney() << " 元" << endl;

    return 0;
}
