#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    map<string, string> arr =
        {
            {"one", "Nghĩa"},
            {"two", "Nhân"}};

    arr["three"] = "Oanh";
    arr["four"] = "Dũng";

    for (const auto &item : arr)
    {
        cout << "Key: " << item.first << " - " << "Value: " << item.second << endl;
    }
}