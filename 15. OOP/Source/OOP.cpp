#include "OOP.hpp"

int main()
{
    // Khởi tạo Sinh Viên 1
    SinhVien sv1;
    sv1.setMajor("Co Dien Tu");
    sv1.setID(2412257);
    sv1.setName("Do Duc Nghia");
    sv1.display();

    // Khởi tạo Học sinh 1
    HocSinh hs1;
    hs1.setName("Ngo Hoang Hao");
    hs1.setClass("12A1");
    hs1.setID(526712);
    hs1.display();

    // Khởi tạo Giảng Viên 1
    GiangVien gv1;
    gv1.setID(7831231);
    gv1.setName("Ms Xuan Anh");
    gv1.setSubject("Calculus 1/2");
    gv1.display();

    // Khởi tạo trẻ vị thành niên
    TreViThanhNien tvtn;
    tvtn.SinhVien::setID(41224124);

    return 0;
}