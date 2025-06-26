#include <iostream>
#include <stdint.h>

using namespace std;

class A
{
private:
    int x;
    int y;
    int id;

public:
    void display();

    A(int X, int Y);
};

void A::display()
{
    cout << "ID: " << id << endl;
    cout << "Day la lop A!" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}

A::A(int X, int Y)
{
    static int ID = 1;
    x = X;
    y = Y;
    id = ID;
    ID++;
}

int main()
{
    int *ptr = new int(10);
    cout << "Dia chi doi tuong: " << ptr << endl;
    cout << "Gia tri doi tuong: " << *ptr << endl;
    delete ptr;

    int arr[] = {1, 2, 3, 4};
    int *arrptr = arr;

    cout << "Dia chi phan tu dau tien: " << arrptr << endl;
    cout << "Gia tri phan tu dau tien: " << *arrptr << endl;
    cout << "Cung la gia tri phan tu dau tien: " << arrptr[0] << endl;

    int *ptrarr = new int[5];
    delete[] ptrarr;

    A *classptr = new A(10, 18);
    classptr->display();
    A *classptr2 = new A(11, 5);
    classptr2->display();

    delete classptr;
    delete classptr2;

    return 0;
}