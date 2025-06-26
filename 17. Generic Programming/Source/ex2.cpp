#include <iostream>
using namespace std;

// Function Template khi chỉ có một tham số
template <typename T>
T sum(T value)
{
    return value;
}

// Function Template sử dụng Variadic Template, ít nhất 2 tham số
template <typename T, typename... Args>
auto sum(T first, Args... args)
{
    return first + sum(args...);
}

int main()
{
    cout << sum(1, 2, 3.6, 5.7, 40) << endl;
    return 0;
}
