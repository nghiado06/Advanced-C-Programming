#ifndef OOP_HPP
#define OOP_HPP

// Tìm hiểu về tính kế thừa - đa kế thừa

#include <iostream>
#include <string.h>

using namespace std;

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

    void display()
    {
        cout << "STT: " << STT << endl;
        cout << "Ten: " << ten << endl;
        cout << "ID: " << id << endl;
    }
};

// class con / class dẫn xuất / derived class
class SinhVien : public DoiTuong
{
private:
    string chuyenNganh;

public:
    void setMajor(string Major)
    {
        chuyenNganh = Major;
    }

    void display();
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
    void display();
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
    void display();
};

// Diamond Problem

class TreViThanhNien : public HocSinh, public SinhVien, public DoiTuong // Đa Kế Thừa
{
};

void SinhVien::display()
{
    // cout << "STT: " << STT << endl;
    // cout << "Ten: " << ten << endl;
    // cout << "ID: " << id << endl;
    DoiTuong::display();
    cout << "Chuyen Nganh: " << chuyenNganh << endl;
}

void GiangVien::display()
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

#endif