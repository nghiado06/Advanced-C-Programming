#include <iostream>
using namespace std;

// Đặc điểm: lồng nhau, namespace cùng tên,

namespace A
{
    int x = 10;
    void display()
    {
        cout << x << endl;
    }

    namespace C
    {
        void display()
        {
            cout << "Hello World!" << endl;
        }
    };
};

namespace A
{

};

namespace B
{
    int x = 11;
    void display()
    {
        cout << x << endl;
    }
};

template <typename T>
void display(T a, T b)
{
    cout << "Đây là hàm display với template" << endl;
}

void display(int c)
{
    cout << "Hàm display toàn cục" << endl;
}

int main()
{
    cout << A::x << endl;
    cout << B::x << endl;

    A::display();
    B::display();
    A::C::display();

    display(1, 2);
    return 0;
}