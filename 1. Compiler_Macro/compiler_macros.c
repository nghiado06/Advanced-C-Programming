#include <stdio.h>

/*Compiler: Trình biên dịch
Quá trình biên dịch bao gồm các bước sau:
1. Preprocessing (Tiền xử lý): Bao gồm include header(tìm kiếm và chèn mã nguồn), expand macro(thay thế các macro), delete comment
(xóa đi các dòng comment). Chuyển/gồm các file (.c;.cpp;.h) vào file.i.
Cú pháp để tạo file.i là:  gcc -E file.c -o file.i trong terminal
2. Compiler (Biên dịch): Chuyển file.i này sang file.s, ngôn ngữ assembly rất dễ để máy tính hiểu
Cú pháp để tạo file.s là: gcc -S file.i -o file.s
3. Assemble: Chuyển file.s sang file.o,.obj sử dụng ngôn ngữ máy (Mã nhị phân)
Cú pháp để tạo file.o là: gcc -c file.s - file.o
4. Linking: Gom tất cả các file.o lại với nhau để thành file thực thi .exe
Cú pháp để gom file là: gcc file1.o file2.o -o ten_file_thuc_thi
*/

// Macro: #define, #include, #undef, #if, #elif, #else, #endif
// #if dùng để kiểm tra các Macro
// Các toán tử trong macro
// 1. Toán tử #: dùng để biến giá trị thành 1 chuỗi ký tự. Cần có 1 macro trung gian
// 2. Toán tử ##: dùng để nối chuỗi
// 3. Toán tử Variadic:
#define STRINGIZE(x) #x
#define DATA 40
#define STRINGIZE_HELPER(x) STRINGIZE(x)

#define NOI_CHUOI(a, b) a##b

int main()
{

    // Sử dụng toán tử #
    int TOIYEU_EM = 1;
    printf("The value is: %s\n", STRINGIZE_HELPER(DATA));
    printf("%d\n", NOI_CHUOI(TOI, YEU_EM));

    return 0;
}
