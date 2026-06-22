#include <iostream>
using namespace std;

class Counter {
public:
    Counter() { value = 0; }

    void increment() { value++; }
    void decrement() { value--; }
    void reset() { value = 0; }
    int getValue() { return value; }

private:
    int value;
};

int main() {
    Counter c;
    c.increment();
    c.increment();
    c.increment();
    cout << "计数：" << c.getValue() << endl;
    c.decrement();
    cout << "减1后：" << c.getValue() << endl;
    c.reset();
    cout << "重置后：" << c.getValue() << endl;
    return 0;
}
