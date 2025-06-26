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

    SinhVien(); // Constructor
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

SinhVien::SinhVien()
{
    uni = "Ho Chi Minh City University of Technology"; // Khởi tạo các giá trị cố định
    age = 19;
}

int main()
{
    SinhVien sv1;
    sv1.name = "Do Duc Nghia";
    sv1.id = 2412257;
    sv1.campus = "Ly Thuong Kiet Camp";
    sv1.falcuty = "Falcuty of Mechanical Engineer";
    sv1.major = "Mechatronics Engineering";
    sv1.display();

    return 0;
}