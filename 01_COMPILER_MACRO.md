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
        - **Include Header**: Tìm kiếm và chèn mã nguồn
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
        - **Delete Comment**: Xóa đi các dòng comment
        ```c
        file.c
        // Dòng này sẽ bị xóa
        printf("Dòng code này thì không bị xóa");
  
        file.i (Khi này file.i sẽ không còn dòng commnent nữa)
        printf("Dòng code này thì không bị xóa");
        ````
        **Expand Macro**: Thay thế các macro, chỉ có tác dụng thay thế như thay thế văn bản
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
}
````
```output:title=output
20
````

### #undef

## B. Một số toán tử trong Macro


