#include <iostream>
using namespace std;

class Rectangle {
public:
    Rectangle(double w, double h) {
        width = w;
        height = h;
    }

    double area() {
        return width * height;
    }

    double perimeter() {
        return 2 * (width + height);
    }

    void show() {
        cout << "长方形：" << width << "×" << height << endl;
        cout << "面积：" << area() << " 周长：" << perimeter() << endl;
    }

private:
    double width, height;
};

int main() {
    Rectangle r1(3, 4);
    Rectangle r2(5.5, 2.5);

    r1.show();
    cout << endl;
    r2.show();

    return 0;
}
