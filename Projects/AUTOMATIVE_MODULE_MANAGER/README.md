# AUTOMATIVE_MODULE_MANAGER MINI PROJECT
Chương trình sử các kiến thức về:
- Bitmask: Quản lý trạng thái của Module với các phép Dịch Bit và toán tử với Bit
- Pointer: Sử dụng con trỏ, đặc biệt là con trỏ hàm để đọc các hàm được khai báo theo chức năng
- File Structure: Quản lý các file theo cấu trúc, giúp dễ sửa lỗi và quản lý chức năng của từng bộ phận
- Sử dụng thư viện setjmp.h để set vị trí các lỗi
- Struct: Tạo một struct bao gồm các đặc tính chung của các MCU
- Cấp phát động: Sử dụng Realloc để cấp phát động, giúp lưu trữ thông tin các module và điều chỉnh kích thước mảng
- Sử dụng các Macro trong việc tạo thư viện,..

Chương trình hoạt động như sau:
- Người dùng add vào các ECU cần tạo, sau đó tiến hành điều khiển hay nói cách khác là tạo thêm các dữ liệu liên quan đến ECU.
- Điều chỉnh các trạng thái của các ECU đó với các hàm.