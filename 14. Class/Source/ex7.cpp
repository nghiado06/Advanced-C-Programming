#include <iostream>
#include <string>

using namespace std;

class SinhVien
{
public:
    static int dem;

    SinhVien()
    {
        dem++;
    }

    static void showCount()
    {
        cout << "Da tao " << dem << " sinh vien" << endl;

        // cout << name; ❌ Không được, vì name không phải static
    }

private:
    string name;
};

// Định nghĩa biến static bên ngoài
int SinhVien::dem = 0;

int main()
{
    SinhVien::showCount(); // ✅ Gọi hàm static mà không cần tạo object
    SinhVien sv1;
    SinhVien::showCount();
    SinhVien sv2;
    SinhVien::showCount(); // ✅ In ra: Da tao 2 sinh vien
}
