#include <iostream>
using namespace std;

namespace A
{
    void unique()
    {
        cout << "Member này là duy nhất" << endl;
    }
};

using namespace A;

int main()
{
    unique();
    return 0;
}