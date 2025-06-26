// Đa hình được chia làm 2 loại:
// - Đa hình run-time
// - Đa hình Compile-Time

// ép kiểu từ class cha --> class con: down-casting
// ép kiểu từ class con --> class cha: up-casting

// kế thừa --> mở rộng: overload: mở rộng thêm được tham số
/* virtual --> mở rộng: override: bắt buộc phải gọi đúng hàm gốc để có thể ghi đè, nếu có chỉnh sửa (gọi thêm tham số,..)
nó sẽ hiểu là không phải là hàm gốc để có thể ghi đè được nữa, nói cách khác là chỉ có thể thay đổi nội dung bên trong.*/

// class trừu tượng # tính trừu tượng
/* pure virtual class:
- có 1 hàm không được xác định nội dùng, tức là chưa được định nghĩa bằng cách gán hàm đó bằng = 0
- Vẫn có thể sử dụng để khai báo con trỏ, khi đó nó bắt buộc các class con phải định nghĩa lại hàm trừu tượng đó (override)
*/

/*
Sử dụng hàm thuần ảo khi chưa xác định được hàm đó sẽ làm gì
Sử dụng hàm ảo khi có một nội dung chung và nội dung riêng sẽ được ghi đè

*/

#include "OOP_2.hpp"

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

    // Hàm ảo - Đa hình
    // Khởi tạo con trỏ
    DoiTuong *dt;

    dt = &sv1;
    ((SinhVien *)dt)->display(); // down-casting

    DoiTuong dt1;
    dt = &dt1;
    ((SinhVien *)dt)->display(); // Lỗi không có thông tin

    dt = &gv1;
    dt->display();

    // Hàm thuần ảo - Pure Virtual Function
    sv1.pureFunction();   // Đã định nghĩa ghi đè trong class Sinh Viên nhưng không thể khai báo đối tượng với các class khác
    PureVirtualFunc *pf3; // Vẫm khai báo được với con trỏ
    return 0;
}