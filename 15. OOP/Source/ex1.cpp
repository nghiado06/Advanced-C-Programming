#include <iostream>

using namespace std;

class SinhVien
{
private:
    int id;
    string name;

public:
    void getName(string newName);
    void getID(int newID);
    void display();
};

void SinhVien::getName(string newName)
{
    name = newName;
}

void SinhVien::getID(int newID)
{
    id = newID;
}

void SinhVien::display()
{
    cout << "Ho va Ten: " << name << endl;
    cout << "MSSV: " << id << endl;
}

int main()
{
    SinhVien sv1;
    // sv1.name = "Do Duc Nghia"; // báo lỗi truy cập
    sv1.getName("Do Duc Nghia");
    sv1.getID(2412257);
    sv1.display();

    return 0;
}
