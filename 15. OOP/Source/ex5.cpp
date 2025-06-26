#include <iostream>

using namespace std;

class Parent
{
public:
    virtual void func() = 0;
};

class Child : public Parent
{
    void func() override
    {
        cout << "Day la ham ao da duoc dinh nghia lai!";
    }
};

class Kid : public Parent
{
};

int main()
{
    Child cld;
    Parent prt;
    Kid kid;
    Parent *prt2;

    return 0;
}