#include <iostream>

using namespace std;

class DoiTuong
{
protected:
    int id;
    string name;

public:
    void setName(string newName);
    void setID(int newID);
    virtual void display();
};

class SinhVien : public DoiTuong
{
private:
    string chuyenNganh;

public:
    void setMajor(string Major);
    void display();
};

void SinhVien::setMajor(string Major)
{
    chuyenNganh = Major;
}

void DoiTuong::setID(int newID)
{
    id = newID;
}

void DoiTuong::setName(string newName)
{
    name = newName;
}

void DoiTuong::display()
{
    cout << "Ho va Ten: " << name << endl;
    cout << "MSSV: " << id << endl;
}

void SinhVien::display()
{
    cout << "Ho va Ten: " << name << endl;
    cout << "MSSV: " << id << endl;
    cout << "Chuyen Nganh: " << chuyenNganh << endl;
}

int main()
{
    // Khởi tạo sinh viên
    SinhVien sv1;
    sv1.setName("Do Duc Nghia");
    sv1.setID(2412257);
    sv1.setMajor("Co Dien Tu");

    // Khởi tạo đối tượng
    DoiTuong *dt1;
    dt1 = &sv1;
    dt1->display();
}