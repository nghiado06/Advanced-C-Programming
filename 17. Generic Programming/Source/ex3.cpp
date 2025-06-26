#include <iostream>
using namespace std;

template <typename T>
void print()
{
    T a;
    cout << "Kiểu dữ liệu của T là: " << typeid(a).name() << endl;
}

template <typename T, typename T1 = int>
void print_a(T1 a)
{
    T b;
    cout << "Kiểu dữ liệu của T1 sau khi đã được deduced là: " << typeid(a).name() << endl;
    cout << "Kiểu dữ liệu của T là: " << typeid(b).name() << endl;
}

template <typename T>
void display()
{
    cout << "Đây là hàm 1 biến!" << endl;
}

template <typename T, typename T1>
void display()
{
    cout << "Đây là hàm 2 biến!" << endl;
}

int main()
{
    // Kiểm tra tính độc lập của cơ chế
    cout << "=== Kiểm tra tính độc lập ===" << endl;
    print<int>();
    print<double>();

    cout << endl;

    print_a<double>(12);
    print_a<int>(3.5);

    cout << endl;

    cout << "=== Kiểm tra nếu đếm số lượng biến ===" << endl;

    // Kiểm tra nếu đếm số lượng biến
    display<int>();
    display<double>();

    cout << endl;

    display<int, double>();
    display<int, int>();
    return 0;
}
