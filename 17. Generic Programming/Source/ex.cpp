#include <iostream>
using namespace std;

template <typename T1, typename T2>
T1 sum(T1 a, T2 b)
{
    return a + b;
}

// tham số mặc định
template <typename T = int, typename T1>
T square(T1 x)
{
    return x * x;
}

int main()
{
    int a = 10;
    double b = 15.5;
    int result;
    result = sum(a, b);
    cout << square(4.5) << endl;
    cout << square(4) << endl;           // lấy mặc định -> int    -> 16
    cout << square<double>(4.5) << endl; // ép kiểu      -> double -> 20.25
    return 0;
}