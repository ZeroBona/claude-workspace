#include <iostream>
using namespace std;

int area(int side) {
    return side * side;
}

int area(int length, int width) {
    return length * width;
}

double area(double radius) {
    return 3.14159 * radius * radius;
}

int main() {
    cout << "正方形（边长5）：" << area(5) << endl;
    cout << "长方形（3×4）：" << area(3, 4) << endl;
    cout << "圆形（半径2.5）：" << area(2.5) << endl;
    return 0;
}
