#include <iostream>
#include <string>

using namespace std;

class Parent
{
protected:
    int c;
    int d;

public:
    int a;
    string b;

    void display() { cout << c << endl; }
};

class Child : protected Parent
{
public:
    void display()
    {
        cout << c << endl;
        cout << d << endl;
        cout << a << endl;
    }
};

class Child2 : public Parent
{
public:
    void display()
    {
        cout << a << endl;
        cout << b << endl;
    }
};

int main()
{
    Parent p1;

    return 0;
}