#include <iostream>
using namespace std;

int main()
{
    pair<int, int> p = {1, 2};
    cout << p.first << " " << p.second << endl;

    pair<pair<int, int>, string> p1 = {{1, 2}, "abc"};
    cout << p1.first.first << " " << p1.first.second << " " << p1.second << endl;

    return 0;
}