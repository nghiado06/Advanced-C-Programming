#include <iostream>
#include <string>

using namespace std;

class DoiTuong
{
    // private:
    //    string ten;
    //    int id;

protected:
    string ten;
    int id;

public:
    DoiTuong()
    {
        static int ID = 1;
        id = ID;
        ID++;
    }

    void setName(string _ten)
    {
        // check chuỗi nhập vào
        ten = _ten;
    }

    void display()
    {
        cout << "ten: " << ten << endl;
        cout << "id: " << id << endl;
    }
};

class SinhVien : public DoiTuong
{
protected:
    string chuyenNganh;

public:
    void setChuyenNganh(string _nganh)
    {
        chuyenNganh = _nganh;
    }

    void display()
    { // override
        cout << "ten: " << ten << endl;
        cout << "id: " << id << endl;
        cout << "chuyen nganh: " << chuyenNganh << endl;
    }
};

class HocSinh : public DoiTuong
{
protected:
    string lop;

public:
    void setLop(string _lop)
    {
        lop = _lop;
    }

    void display()
    { // override
        cout << "ten: " << ten << endl;
        cout << "id: " << id << endl;
        cout << "lop: " << lop << endl;
    }
};

class GiaoVien : public DoiTuong
{
protected:
    string chuyenMon;

public:
    void setChuyenMon(string _mon)
    {
        chuyenMon = _mon;
    }

    void display()
    { // override
        cout << "ten: " << ten << endl;
        cout << "id: " << id << endl;
        cout << "chuyen mon: " << chuyenMon << endl;
    }
};

int main(int argc, char const *argv[])
{
    // SinhVien sv1;

    // sv1.ten = "Hoang";
    // sv1.id = 1;
    // sv1.chuyenNganh = "DTVT";

    // cout << "ID: " << sv1.id << endl;
    // cout << "Ten: " << sv1.ten << endl;
    // cout << "Chuyen nganh: " << sv1.chuyenNganh << endl;

    SinhVien sv1;
    sv1.setName("Trung");
    sv1.setChuyenNganh("TDH");
    sv1.display();

    cout << endl;

    HocSinh hs1;
    hs1.setName("Tuan");
    hs1.setLop("12A1");
    hs1.display();

    cout << endl;

    GiaoVien gv1;
    gv1.setName("Hoang");
    gv1.setChuyenMon("Toan");
    gv1.display();
    return 0;
}
