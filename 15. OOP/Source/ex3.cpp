#include <iostream>
using namespace std;

class DoiTuong
{
private:
    void Private()
    {
        cout << "Day la khu vuc private" << endl;
    }

protected:
    int id;
    string name;

public:
    void setName(string newName);
    void setID(int newID);
};

class SinhVien : protected DoiTuong
{
private:
    string chuyenNganh;

public:
    void setMajor(string Major);
};

void DoiTuong::setID(int newID)
{
    id = newID;
}

void DoiTuong::setName(string newName)
{
    name = newName;
}

void SinhVien::setMajor(string Major)
{
    chuyenNganh = Major;
}

int main()
{
    SinhVien sv1;
    // sv1.id = 2412257;   // Báo lỗi vì protected trong class cha vẫn là protected trong class con
    // sv1.Private();      // Báo lỗi truy cập
    // sv1.setID(2412257); // Không báo lỗi
    // sv1.setName("Do Duc Nghia");
    sv1.setMajor("Co Dien Tu");
    return 0;
}