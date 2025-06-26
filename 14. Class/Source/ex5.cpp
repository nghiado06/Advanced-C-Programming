#include <iostream>
#include <string>
using namespace std;

class SinhVien
{
public:
    SinhVien(string name, string lop); // constructor  // tự động khởi tạo
    int ID;                            // property
    string name;                       // property
    string lop;                        // property
    void display();                    // method
};

SinhVien::SinhVien(string name, string lop)
{
    static int id = 100;
    SinhVien::ID = id;
    cout << "Create class ID: " << ID << endl;
    id++;

    SinhVien::name = name;
    SinhVien::lop = lop;
}

void SinhVien::display()
{
    cout << "MSSV: " << ID << endl;
    cout << "TEN: " << name << endl;
    cout << "LOP: " << lop << endl;
}

int main(int argc, char const *argv[])
{
    SinhVien sv("Anh", "DDT1"), sv1("Tuan", "CDT2"); // stack
    sv.display();
    cout << "---------" << endl;
    sv1.display();
    return 0;
}
