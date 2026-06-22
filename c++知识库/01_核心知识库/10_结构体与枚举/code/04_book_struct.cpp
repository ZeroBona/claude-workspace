#include <iostream>
using namespace std;

struct Book {
    string title;
    string author;
    double price;
};

void printBook(Book b) {
    cout << "书名：" << b.title << endl;
    cout << "作者：" << b.author << endl;
    cout << "价格：" << b.price << "元" << endl;
    cout << "----------------" << endl;
}

int main() {
    Book books[3] = {
        {"C++入门", "张三", 39.9},
        {"算法启蒙", "李四", 49.5},
        {"编程思维", "王五", 29.0}
    };

    for (int i = 0; i < 3; i++) {
        printBook(books[i]);
    }

    return 0;
}
