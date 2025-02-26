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
    - Bản chất của va_list là một kiểu dữ liệu chuỗi.
  ```cpp
  va_list args;
  ```  
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
      va_start(args, count); //count là đối số cuối cùng có kiểu dữ liệu cố định int. Đồng thời đối số này cũng giúp xác số lượng phần tử tham số tự do.
    }
    ```
  - **va_arg(para1, para2)**: Truy cập đối số trong danh sách.
    - **para1:** đối số có kiểu dữ liệu va_list.
    - **para2:** kiểu dữ liệu
    - Khi sử dụng macro này nên lưu ý những điều sau:
      - Mỗi lần gọi hàm là 1 lần hàm này truy cập đối số, dù cho lần gọi hàm đó có ý nghĩa gì.
      ```cpp
      void test(int count, ...){
        va_list args;
        va_start(args, count);
        va_arg(args, int); //Đã truy cập đối số đầu tiên
  
        printf("Đây là đối số thứ hai: %d\n", va_arg(args, int));
        printf("Đây là đối số thứ ba: %s\n", va_arg(args, char*));
      
        va_end(args);
      }

      int main(){
      test(3, 1,2,"Hello World");
      }
      ```
      output
      ```
      Đây là đối số thứ hai: 2
      Đây là đối số thứ ba: Hello World
      ```
      - **Quy tắc mở rộng kiểu dữ liệu mặc định (Default Arguments Promotion):**
        - char --> int
        - short --> int
        - float --> double
      ```cpp
      void test(int count,...){
        va_list args;
        va_start(args, count);
        for (int i = 0; i<count; i++){
          int value = va_arg(args, int);
          printf("%d\n", value);

      
        va_end(args);
        }
      }
      int main(){
        test(3, 1, 'A', (short)5);
      }
      ```
      output
      ```
      1 65 5(kiểu int)
      ```
      - Quy tắc ép kiểu:
        - Không thể ép kiểu char* cho các kiểu int, short, ... Chỉ có thể ép kiểu cho chuỗi hoặc dạng địa chỉ và ngược lại.
        - Không thể dùng va_arg(args, short/char) cho các đối số có kiểu dữ liệu tương tự nữa vì chúng đã bị mở rộng thành int.
  - **va_copy(args2, args):**
    - hàm dùng để copy danh sách đối số biến đổi từ args sang args2.
    - Lưu ý khi dùng hàm này là phải kích hoạt danh sách của args trước.
    ```cpp
    void test(int count,...){
      va_list args;
      va_list args2;
      va_start(args, count);
      va_copy(args2, args);
      for (int i = 0; i< count; i++){
        printf("%d ", va_arg(args, int));
        printf("%d\n", va_arg(args2, int));
      }
    }
    int main(){
      test(2, 3, 4);
    }
    ```
    ouput
    ```
    3 3
    4 4
    ```
  - **va_end(args):** kết thúc việc sử dụng danh sách đối số biến đổi. Nó cần được gọi khi kết thúc hàm.
  - Trong các ví dụ ở trên đều có một hàm va_end(args) ở cuối.
- Như vậy cấu trúc để sử dụng **danh sách đối số biến đổi** là:
```cpp
void function(dataType const_para,...){
  va_list args;
  va_start(args, const_para);
  codeBlocks (sử dụng va_arg(args, dataType) để truy cập đối số);
  va_end(args);
}
```
    
# 2. Thư viện ASSERT
