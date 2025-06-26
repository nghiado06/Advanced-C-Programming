#include <iostream>
#include <string>

using namespace std;

// khác biệt so với struct nằm ở chỗ class có thể khai báo cấu trúc phức tạp hơn
// truy cập các thành viên từ bên ngoài/bên trong
// Có thể gọi trực tiếp hoặc thông qua tên Class

class SinhVien
{
public:
    string name; // thuộc tính (properties)
    int age;
    string school; // Thuộc tính này giả định là cố định
    string period; // Thuộc tính này giả định là cố định
    string campus;
    string sex;
    string falcuty;
    int gpa;

    void display(); // phương thức (method)

    void outSide();

    // Constructor
    SinhVien(int GPA, string whichCampus = " ", string whichSex = " ", string whichFalcuty = "Mechanical Engineering"); // Các giá trị mặc định này hoàn toàn có thể bị ghi đè

    ~SinhVien(); // Nếu constructot là khởi tạo dữ liệu thì, Destructor thường được ứng dụng để hủy dữ liệu
                 // Destructor chỉ có một kiểu là không có tham số.
};

SinhVien::SinhVien(int GPA, string whichCampus, string whichSex, string whichFalcuty) // Trình biên dịch vẫn hiểu là đã có giá trị mặc định
    : gpa(GPA)
{
    school = "Ho Chi Minh City University of Technology";
    period = "2024-2025";
    campus = whichCampus;
    sex = whichSex;
    falcuty = whichFalcuty;
}

void SinhVien::outSide()
{
    cout << "Ham nay duoc dinh nghia ben ngoai!" << endl;
}

void SinhVien::display()
{
    cout << "Ten: " << name << endl;
    cout << "Tuoi: " << SinhVien::age << endl;
    cout << "Truong: " << school << endl;
    cout << "Hoc Ky: " << period << endl;
    cout << "Co so: " << campus << endl;
    cout << "Gioi Tinh:" << sex << endl;
    cout << "Khoa: " << falcuty << endl;
    cout << "GPA: " << gpa << endl;
}

SinhVien::~SinhVien()
{
    cout << "Destructor!" << endl;
}

int main()
{
    SinhVien sv1(4, "Ly Thuong Kiet", "Nam", "Mechanical Engineering"); // đối tượng (object) //Khoa May Tinh đã ghi đè lên giá trị mặc định

    sv1.age = 19;
    sv1.name = "Do Duc Nghia";
    sv1.campus = "Di An";
    sv1.display();
    return 0;
}