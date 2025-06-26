#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Có 2 cách sử dụng:
/*
Cách 1: gán nó thông qua một biến
Cách 2: sử dụng trực tiếp không cần thông qua biến, nhược điểm là chỉ sử dụng được 1 lần duy nhất
như gọi biến cục bộ trong stack.

Lambda Expression:
    truyền giá trị --> đọc
    truyền tham chiếu --> ghi


*/

auto funct = []()
{
    cout << "Hello World" << endl;
    ;
};

int main()
{
    auto func = []()
    {
        cout << "Hello World!" << endl;
    };

    func();
    func();
    funct();

    []()
    {
        cout << "Hello World" << endl;
    }();

    auto x = [](int a, int b, int c)
    {
        return a + b + c;
    };

    cout << [](int a, int b, int c)
    {
        return a + b + c;
    }(1, 2, 3)
         << endl;

    cout << x(1, 23, 4) << endl;

    cout << [](auto... args)
    {
        double sum = 0;
        double arr[] = {args...};

        for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        {
            sum = sum + arr[i];
        }
        return sum;
    }(1, 2, 3, 4, 3.5)
         << endl;

    int x1 = 1,
        y = 2,
        z = 3;

    [=]()
    {
        // x = 10;
        cout << x << endl;
    }();

    [&x1]()
    {
        x1 = 10;
        cout << x1 << endl;
    }();

    cout << x1 << endl;

    vector<int> nums = {5, 2, 8, 1};

    // Sắp xếp giảm dần bằng lambda
    sort(nums.begin(), nums.end(), [](int a, int b)
         { return a > b; });

    for (int x : nums)
        cout << x << " ";

    return 0;
}