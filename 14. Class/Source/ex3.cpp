#include <iostream>
#include <string>

using namespace std;

class SinhVien
{
public:
    string name;
    int age;
    int id;
    string uni;
    string campus;
    string falcuty;
    string major;

    void display();

    SinhVien(string newName = " ", string whichUni = " ", string whichCampus = "", string whichMajor = "");

    ~SinhVien();
};

void SinhVien::display()
{
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "ID: " << id << endl;
    cout << "Uni: " << uni << endl;
    cout << "Campus: " << campus << endl;
    cout << "Falcuty: " << falcuty << endl;
    cout << "Major: " << major << endl;
}

SinhVien::SinhVien(string newName, string whichUni, string whichCampus, string whichMajor)
{
    name = newName;
    uni = whichUni;
    age = 19;
    campus = whichCampus;
    major = whichMajor;
}

SinhVien::~SinhVien()
{
    // Reset lại dữ liệu
    name = "";
    uni = "";
    age = 0;
    id = 0;
    campus = "";
    falcuty = "";
    major = "";

    cout << "Da reset du lieu!" << endl;
}

int main()
{
    // Cách khai báo 1: Khai báo cho tham số
    SinhVien sv1("Do Duc Nghia", "HCMUT", "Ly Thuong Kiet", "Mechatronics Engineering"); // Hoàn toàn có thể ghi đè giá trị
    sv1.id = 2412257;
    sv1.falcuty = "Falcuty of Mechanical Engineer";

    // Cách khai báo 2: Khai báo đè lên tham số
    SinhVien sv2;
    sv2.name = "Ngo Hoang Hao";
    sv2.uni = "HCMUT";
    sv2.campus = "Di An";
    sv2.major = "Industry Management";
    sv2.id = 2310890;
    sv2.falcuty = "Falcuty of Industry Management";

    // Chưa khai báo tham số
    SinhVien sv3;
    sv3.id = 2412862;
    sv3.falcuty = "Falcuty of Mechanical Engineering";

    // Xuất ra màn hình
    sv1.display();

    // Xuống dòng
    cout << endl;

    sv2.display();

    // Xuống dòng
    cout << endl;

    sv3.display();

    return 0;
}