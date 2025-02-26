# Tìm hiểu về Compiler Process và Macro trong C
Compiler là gì? Quá trình compile gồm những bước nào? <br>
Macro là gì? Ý nghĩa của Macro ứng với quá trình compile và code.
## 1. Compiler
### A. Định nghĩa
Compiler có thể hiểu đơn giản là trình biên dịch, là một chương trình dịch (compile) một mã nguồn từ ngôn ngữ lập trình cấp cao (C++, C, Java,..) sang ngôn ngữ máy (Machine Language) để CPU, máy tính có thể hiểu được. 
### B. Quá trình compile (Compiler Process)
- Quá trình compile sẽ bao gồm các bước sau:
    - ****Preprocessing**** (Tiền xử lý): Quá trình sẽ chuyển các file (.c;.cpp;.h) sang file .i <br>
    ```
    Cú pháp để thực hiện quá trình trong terminal (IDE VScode) như sau:
    gcc -E file.c -o file.i
    ````
    Quá trình này bao gồm các công việc:<br>
    >* **Include Header**: Tìm kiếm và chèn mã nguồn<
        ```c
        Ex.h (Ví dụ cho file.h)
        #ifndef EX_H
        #define EX_H
        printf("Đây là file.h");
        #endif
        
        file.c (Ví dụ cho file.c)
        #include "Ex.h"
        printf("Đây là dòng code dưới dòng code trong file.h");
        
        file.i (Quá trình preprocessing sẽ biên dịch từ file.c sang file.i như sau)
        #ifdef EX_H
        #define EX_H
        printf("Đây là file.h");
        #endif
        printf("Đây là dòng code dưới dòng code trong file.h");
        ````

    >* **Delete Comment**: Xóa đi các dòng comment<
        ```c
        file.c
        // Dòng này sẽ bị xóa
        printf("Dòng code này thì không bị xóa");
  
        file.i (Khi này file.i sẽ không còn dòng commnent nữa)
        printf("Dòng code này thì không bị xóa");
        ````
    >* **Expand Macro**: Thay thế các macro, chỉ có tác dụng thay thế như thay thế văn bản<
        ```c
        file.c
        #define LED 17
        #define BUZZER 16

        digitalWrite(LED, HIGH);
        digitalWrite(BUZZER, LOW);

        file.i
        digitalWrite(17, HIGH);
        digitalWrite(16, LOW);
        ````

    - ****Compiler**** (Biên dịch): Chuyển từ file.i sang file.s, chuyển sang ngôn ngữ assembly
    ```
    Cú pháp để thực hiện quá trình trong terminal (IDE VScode) như sau:
    gcc -S file.i -o file.s
    ````
    - ****Assemble****: Chuyển file.s sang file.o;.obj, chuyển sang ngôn ngữ máy (Mã nhị phân)
    ```
    Cú pháp để thực hiện quá trình trong terminal (IDE VSCode) như sau:
    gcc -c file.s -0 file.o
    ````
    - ****Linking****: Gom tất cả các file.o lại với nhau để chuyển thành file thực thi .exe
    ```
    Cú pháp để thực hiện quá trình trong terminal (IDE VSCode) như sau:
    gcc file1.o file2.o 0o name.exe (name tùy ý)
    ````

# 2. Macros
## A. Định nghĩa
Macro là từ dùng để chỉ những thôn tin được xử lý ở quá trình tiền xử lý (Preprocessor).<br>
Chia làm 3 nhóm chính:<br>
- #include
- #define, #undef
- #if, #elif, #else, #ifdef, #ifndef
### #include
Chỉ thị #include dùng để chèn nội dụng của 1 file nào đó vào mã nguồn của chương trình
- Tái sử dụng mã nguồn
- Phân chia chương trình thành các phần nhỏ, giúp quản lý mã nguồn hiệu quả
```c
#include <stdio.h> (Chèn nội dung của file stdio này vào mã nguồn chương trình chính)

int main()
{
    code block;
}
````
### #define
- Dùng để thay thế một chuỗi bằng 1 chuỗi khác trước khi chương trình biên dịch
```c
#define PI 3.14

printf("%d", PI);

Khi biên dịch sang file.i sẽ chuyển thành
printf("%d", 3.14);

Tương tự:
#include <stdio.h>

#define Max(x,y) ((x) > (y) ? (x) : (y))

int main(){
    int a = 10, b = 20;
    int max_number = Max(a,b);
    printf("%d", max_number);

    return 0;
}
````
ouput
```
20
````

### #undef
Chỉ thị #undef dùng để hủy định nghĩa của một macro đã được định nghĩa bằng #define trước đó.
```c
#include <stdio.h>
#define SENSOR 21
int main(){
    #undef SENSOR
    printf("%d\n", SENSOR);
    #define SENSOR 50
    printf("%d\n", SENSOR);

    return 0;
}
````
ouput
```
21
50
````
### #if #elif #else
Các chỉ thị này cũng tương tự với if, else, elif trong C nhưng khác ở chỗ nó dành để kiểm tra macro.
```c
#include <stdio.h>
#define MCU STM32

//Kiểm tra bằng các macro điều kiện
int main(){
    #if MCU = STM32
        codeblock;
    #elif MCU = ESP32
        codeblock;
    #else
        codeblock;

    return 0;
}
````
### #ifdef #ifndef
- Chỉ thị #ifdef dùng để kiểm tra một macro đã được định nghĩa hay chưa, nếu macro đã được định nghĩa thì mã nguồn sau #ifdef sẽ được biên dịch.
- Chỉ thị #ifndef dùng để kiểm tra một macro đã được định nghĩa hay chưa, nếu macro chưa được định nghĩa thì mã nguồn sau #ifndef sẽ được biên dịch
```c
#include <stdio.h>
#define TEST1 1
#ifdef TEST1
printf("Đã được định nghĩa\n");
#endif
#ifndef TEST2
printf("Chưa được định nghĩa");
#endif
````
output
```
Đã được định nghĩa
Chưa được định nghĩa
````
## B. Một số toán tử trong Macro
### 1. Toán tử "#"
Toán tử # dùng để biến 1 giá trị thành 1 chuỗi ký tự. Nhưng hết sức lưu ý khi dùng toán tử #, vì khi dùng # cho 1 macro thì macro đó sẽ không được mở rộng trước khi đưa vào toán tử #. <br>
Lấy ví dụ:
```c
#include <stdio.h>

#define A 10
#define STRINGIZE(x) #x

int main(){
    print("%s\n", STRINGIZE(A));
    return 0;
}
````
output
```
A
````
Khi này output nó sẽ là A vì A chưa được mở rộng khi gặp toán #, do đó cần một Macro trung gian để trình biên dịch hiểu rằng đó không phải là toán tử # và Macro A có thể được mở rộng.
```c
#include <stdio.h>

#define A 10
#define BeforeStringize(x) STRINGIZE(x)
#define STRINGIZE(x) #x

int main(){
    print("%s\n", BeforeStringize(A));
    return 0;
}
````
output
```
"10"
````
### 2. Toán tử "##"
Toán tử ## dùng để nối chuỗi
```c
#include <stdio.h>

#define NOICHUOI(a,b) a##b

int main(){
    int AB = 1;
    printf("%d", NOICHUOI(A,B));
    return 0;
}
````
output
```
1
````
### 3. Toán tử varadic macro
- Là một dạng macro cho phép nhận một số lượng biến tham số có thể thay đổi.
- Giúp định nghĩa các macro có thể xử lý một lượng biến đầu vào khác nhau
- Có cú pháp là #define macro_name(...) expansion
#### Ví dụ cơ bản
```c
#include <stdio.h>

#define PRINT(...) printf(__VA_ARGS__)

int main() {
    PRINT("Hello, World!\n");
    PRINT("Number: %d\n", 42);

    return 0;
}

````
output
```
Hello, World!
Number: 42
````
#### Thêm tiền tố hoặc hậu tố
```c
#include <stdio.h>

#define PRINT(tag,...) printf("[%s] ", tag), printf(__VA_ARGS__)

int main(){
    PRINT("INFO", "Hello World" );

    return 0;
}
````
output
```
[INFO] Hello World
````
