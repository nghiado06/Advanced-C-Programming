#include <iostream>
using namespace std;

template <typename T>
void display()
{
    cout << "Đây là kiểu chưa được chuyên biệt" << endl;
};

template <>
void display<int>()
{
    cout << "Đây là kiểu int" << endl;
}

template <>
void display<bool>()
{
    cout << "Đây là kiểu bool" << endl;
}

template <>
void display<double>()
{
    cout << "Đây là kiểu double" << endl;
}

template <>
void display<float>()
{
    cout << "Đây là kiểu float" << endl;
}

// Trường hợp 1 kiểu
template <typename T>
void display_all()
{
    display<T>();
}

// Trường hợp từ 2 kiểu trở lên
template <typename First, typename Second, typename... Rest>
void display_all()
{
    display<First>();
    display_all<Second, Rest...>();
}

int main()
{
    display_all<bool, double, int, float>();

    return 0;
}