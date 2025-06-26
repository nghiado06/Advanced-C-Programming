#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> arr = {3, 5, 7, 4, 1};

    for (auto const var : arr)
    {
        cout << "Vector: " << var << endl;
    }

    sort(arr.begin(), arr.end());
    cout << "vector after sort ascending: " << endl;
    for (auto const var : arr)
    {
        cout << "Vector: " << var << endl;
    }

    sort(arr.begin(), arr.end(), greater<int>());
    cout << "vector after sort descending: " << endl;
    for (auto const var : arr)
    {
        cout << "Vector: " << var << endl;
    }

    vector<int> arr1 = {2, 5, 7, 4, 9};

    auto it = find(arr1.begin(), arr1.end(), 3);

    if (it != arr1.end())
    {
        cout << "Da tim thay" << endl;
    }
    else
    {
        cout << "Khong tim thay" << endl;
    }

    return 0;
}
