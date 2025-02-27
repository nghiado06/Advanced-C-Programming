# BÀI TẬP 02
## Ứng dụng các kiến thức:
- **goto**
- **Macro**
- Thư viện **setjmp**
- Thư viện **stdint**
để build một chương trình test các dữ liệu đầu vào và đầu ra cố định đơn giản.

```cpp
#include <stdio.h>
#include <setjmp.h>
#include <stdint.h>

// Định nghĩa các Macro TRY THROW CATCH
#define TRY exc = setjmp(buf);
#define THROW(x) \
    longjmp(buf, x);
#define CATCH(x, ...)                 \
    if (exc == x)                     \
    {                                 \
        printf("%s\n", #__VA_ARGS__); \
        goto askagain;                \
    }

// Định nghĩa các dữ liệu đầu vào cho các hàm
#define VALID_FILE 1
#define INVALID_FILE 0

#define DISCONNECTED 0
#define CONNECTED 1

#define VALID_DATA 1
#define INVALID_DATA 0

// Khai báo biến lưu trữ thông tin trạng thái thực thi
jmp_buf buf;

// Khai báo chuỗi tín hiệu
int exc = 0;

// Tạo danh sách enum để lưu các loại lỗi
enum ErrorCodes
{
    NO_ERROR = 1,     // Giá trị 1
    FILE_ERRORS,      // Giá trị 2
    NETWORK_ERROR,    // Giá trị 3
    CALCULATION_ERROR // Giá trị 4
};

// Khai báo các hàm chức năng

void readFile(int a)
{
    if (a == 1)
    {
        THROW(NO_ERROR);
    }
    else if (a == 0)
    {
        THROW(FILE_ERRORS);
    }
}

void networkOperation(int b)
{
    if (b == 1)
    {
        THROW(NO_ERROR);
    }
    else if (b == 0)
    {
        THROW(NETWORK_ERROR);
    }
}

void calculateData(int c)
{
    if (c == 1)
    {
        THROW(NO_ERROR);
    }
    else if (c == 0)
    {
        THROW(CALCULATION_ERROR);
    }
}

int main()
{

    // Xây dựng mô hình kiểm tra bằng TRY CATCH THROW
    TRY

    CATCH(NO_ERROR, No Errors Found)

        CATCH(FILE_ERRORS, File Errors Found)

            CATCH(NETWORK_ERROR, Network Errors Found)

                CATCH(CALCULATION_ERROR, Calculation Errors Found)

        // Xây dựng giao diện UI đơn giản bằng goto

        // Khai báo biến kiểm tra
        uint8_t opt;
    char check;

    // Trạng thái đầu tiên là ở main menu
    goto main_menu;

// Đặt nhãn
main_menu:
    printf("---ĐANG Ở MAIN MENU---\n");
    printf("1. Calculate\n");
    printf("2. Read File\n");
    printf("3. Network Checking\n");
    printf("Hãy chọn option bạn muốn: ");
    scanf("%d", &opt);
    getchar();

    // Kiểm tra option
    if (opt == 1)
        goto calculate;
    else if (opt == 2)
        goto readfile;
    else if (opt == 3)
        goto networkcheck;

calculate:
    printf("1. Valid Data\n");
    printf("2. Invalid Data\n");
    printf("Hãy chọn kiểu dữ liệu bạn muốn test: ");
    scanf("%d", &opt);
    getchar();

    // Kiểm tra option
    if (opt == 1)
        calculateData(VALID_DATA);
    else if (opt == 2)
        calculateData(INVALID_DATA);

readfile:
    printf("1. Valid File\n");
    printf("2. Invalide File\n");
    printf("Hãy chọn kiểu file bạn muốn test: ");
    scanf("%d", &opt);
    getchar();

    // Kiểm tra option
    if (opt == 1)
        readFile(VALID_FILE);
    else if (opt == 2)
        readFile(INVALID_FILE);

networkcheck:
    printf("1. Connected\n");
    printf("2. Disconnected\n");
    printf("Hãy chọn trạng thái mạng bạn muốn test: ");
    scanf("%d", &opt);
    getchar();

    // Kiểm tra option
    if (opt == 1)
        networkOperation(VALID_DATA);
    else if (opt == 2)
        networkOperation(INVALID_DATA);

askagain:
    printf("Bạn muốn tiếp tục thử chứ? [Y/n]:");
    // Kiểm tra
    scanf("%c", &check);
    if (check == 'Y' || check == 'y')
    {
        goto main_menu;
    }
    else
    {
        goto end;
    }

end:
    printf("Chương trình thử nghiệm kết thúc tại đây!");

    return 0;
}
```
