#ifndef OOP_2_HPP
#define OOP_2_HPP

// Tìm hiểu về tính kế thừa - đa kế thừa

/*=================================[ INCLUDE LIBRARY ]======================================*/

#include <iostream>
#include <string.h>

using namespace std;

/*====================================[ CLASS DECLARATION ]=================================*/

// class cha / class gốc / bare class
class DoiTuong
{
protected:
    string ten;
    int id;
    int STT;

public:
    void setName(string Ten)
    {
        ten = Ten;
    }

    void setID(int ID)
    {
        id = ID;
    }

    DoiTuong()
    {
        static int stt = 1;
        STT = stt;
        stt++;
    }

    virtual void display();

    void overload()
    {
        cout << "Overload Hàm" << endl;
    }

    void daKeThua();
};

class PureVirtualFunc
{
public:
    virtual void pureFunction() = 0;
};

// class con / class dẫn xuất / derived class
class SinhVien : public DoiTuong, public PureVirtualFunc
{
private:
    string chuyenNganh;

public:
    void setMajor(string Major)
    {
        chuyenNganh = Major;
    }

    void display() override;

    void overload(int x);

    void pureFunction() override;
};

class GiangVien : public DoiTuong
{
private:
    string boMon;

public:
    void setSubject(string BOMON)
    {
        boMon = BOMON;
    }
    void display() override;
};

class HocSinh : public DoiTuong
{
private:
    string lop;

public:
    void setClass(string Class)
    {
        lop = Class;
    }
    void display() override;
};

/*===============================[ FUNCTION DEFINITIONS ]==============================*/

void DoiTuong::display()
{
    cout << "STT: " << STT << endl;
    cout << "Ten: " << ten << endl;
    cout << "ID: " << id << endl;
}

void DoiTuong::daKeThua()
{
    cout << "Da Ke Thua" << endl;
}

void GiangVien::display() // overload
{
    // cout << "STT: " << STT << endl;
    // cout << "Ten: " << ten << endl;
    // cout << "ID: " << id << endl;
    DoiTuong::display();
    cout << "Bo Mon: " << boMon << endl;
}

void HocSinh::display()
{
    // cout << "STT: " << STT << endl;
    // cout << "Ten: " << ten << endl;
    // cout << "ID: " << id << endl;
    DoiTuong::display();
    cout << "Lop: " << lop << endl;
}

void SinhVien::display()
{
    // cout << "STT: " << STT << endl;
    // cout << "Ten: " << ten << endl;
    // cout << "ID: " << id << endl;
    DoiTuong::display();
    cout << "Chuyen Nganh: " << chuyenNganh << endl;
}

void SinhVien::overload(int x) // Overload
{
    DoiTuong::overload();
    cout << "Mở rộng hàm với biến x: " << x << endl;
}

void SinhVien::pureFunction()
{
    cout << "Day la ham ao" << endl;
}

#endif