## Tìm hiểu về Thư viện STDARG và ASSERT
- Thư viện stdarg là gì? Có ý nghĩa gì?
- Thư viện assert là gì? Có ý nghĩa gì?
# 1. Thư viện STDARG
****Thư viện stdarg:****
- Cung cấp các phương thức để làm việc với hàm số có số lượng input parameter không cố định.
- Các hàm như printf và scanf là ví dụ điển hình.
- Các hàm thông dụng của thư viện stdarg:
  - **va_list:**
    - Là một kiểu dữ liệu để đại diện cho danh sách các đối số biến đổi (Khai báo biến).
  ```cpp
  va_list args;
  ```
    - Bản chất của va_list chính là kiểu dữ liệu chuỗi.
  ```cpp
   void test(int count,...){ 
   // typedef char* va_list
   va_list args;
   Tương đương với:
   char *args = "int count,..."; 
   } 
  ```

  - **va_start(para1, para2)**:
    - Bắt đầu một danh sách đối số biến đổi.
    - **para1** là đối số mang kiểu dữ liệu va_list.

    ```cpp
    va_list args;
    va_start(args,...);
    ```
    
    - **para2** là đối số cuối cùng mang kiểu dữ liệu cố định.
    
    ```cpp
    void (int a, int b, int count,...){
    va_list args;
    va_start(args, count); //count là đối số cuối cùng có kiểu dữ liệu cố định int. Đồng thời
<br>
    đối số này cũng giúp xác số lượng phần tử tham số tự do.
    }
    ```
    
# 2. Thư viện ASSERT
