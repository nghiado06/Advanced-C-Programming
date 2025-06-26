#include <iostream>

using namespace std;

class A
{
public:
    A()
    {
        cout << "Constructor A" << endl;
    }

    void hienthiA()
    {
        cout << "Day la lop A" << endl;
    }
};

class B : virtual public A
{
public:
    B()
    {
        cout << "Constructor B" << endl;
    }

    void hienthiB()
    {
        cout << "Day la lop B" << endl;
    }
};

class C : virtual public A
{
public:
    C()
    {
        cout << "Constructor C" << endl;
    }

    void hienthiC()
    {
        cout << "Day la lop C" << endl;
    }
};

// Diamond Problem với hàm daKeThua, khắc phục bằng virtual ngay đầu hàm (kế thừa ảo)
class D : public B, public C
{
public:
    D()
    {
        cout << "Constructor D" << endl;
    }

    void hienthiD()
    {
        cout << "Day la lop D" << endl;
    }
};

int main()
{
    D d;
    d.hienthiB();
    d.B::hienthiA();
    d.hienthiA();

    return 0;
}