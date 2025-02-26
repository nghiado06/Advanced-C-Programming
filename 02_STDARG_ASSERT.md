# STDARG
****Thư viện stdarg:****
- Cung cấp các phương thức để làm việc với hàm số có số lượng input parameter không cố định
- Các hàm như printf và scanf là ví dụ điển hiển
- Các hàm thông dụng của thư viện stdarg:
  - **va_list:** một kiểu dữ liệu để đại diện cho danh sách các đối số biến đổi (Khai báo biến).
  ```cpp
  va_list args;
  ```
  Bản chất của va_list chính là kiểu dữ liệu chuỗi.
  ```cpp
   void test(int count,...){ 
   // typedef char* va_list
   va_list args;
   Tương đương với:
   char *args = "int count,..."; 
 } 
  ```
  - va_start(args, )
# ASSERT
