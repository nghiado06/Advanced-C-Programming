#include <iostream>
#include <string>

using namespace std;

class HinhChuNhat
{
public:
    double chieuDai;
    double chieuRong;
    static int var;
};

int HinhChuNhat::var;

int main()
{
    HinhChuNhat hinh1;
    HinhChuNhat hinh2;
    HinhChuNhat hinh3;

    cout << "address of chieu dai: " << &hinh1.chieuDai << endl;
    cout << "address of chieu dai: " << &hinh2.chieuDai << endl;
    cout << "address of chieu dai: " << &hinh3.chieuDai << endl;

    cout << "address of var: " << &hinh1.var << endl;
    cout << "address of var: " << &hinh2.var << endl;
    cout << "address of var: " << &hinh3.var << endl;
    return 0;
}
