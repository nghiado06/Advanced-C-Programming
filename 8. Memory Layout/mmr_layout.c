#include <stdio.h>
#include <stdlib.h> //Thư viện dễ sử dụng các hàm cấp phát động
#include <stdint.h>

/*Memory Layout: Phân vùng nhớ
- Text Segment
- Data (Initialized Data)
- BSS (Uninitialized Data)
- Heap
- Stack

1. Text Segment (Code Segment):
    - Chứa mã máy, chứa tập hợp các lệnh thực thi
    - Biến hằng (const), chuỗi hằng (string literal) (Chạy trên MacOS - Clang thì nó sẽ nằm trên vùng Text nhưng nếu là Windows - MingW thì nó sẽ nằm trên vùng Data - read only)
    - Có quyền đọc và thực thu, nhưng không có quyền ghi
2. Data Segment (Initialized Data):
    - Chứa biến toàn cục được khởi tạo với giá trị khác không.
    - Chứa các biến static (global + local) được khởi tạo với giá trị khác 0.
    - Có quyền đọc và ghi, tức là có thể đọc và thay đổi giá trị.
    - Tất cả các biến sẽ được thu hồi sau khi chương trình kết thúc.
3. BSS Segment (Uninitialized Data):
    - Chứa các biến toàn cục khởi tạo bằng 0 hoặc chưa khởi tạo giá trị.
    - Chứa các biến static toàn cục và cục bộ được khởi tạo giá trị bằng 0 hoặc chưa khởi tạo giá trị.
    - Biến sẽ bị thu hồi sau khi chương trình kết thúc.
4. Stack
    - Chưa các biến cục bộ (trừ static cục bộ), tham số truyền vào.
    - Hằng số cục bộ, có thể thay đổi thông qua con trỏ
    - Quyền truy cập: Đọc và ghi, nghĩa là có thể đọc và thay đổi giá trị của biến.
    - Sau khi chương trình xong, kết thúc hàm, biến sẽ bị thu hồi.
    - Hoạt động theo quy tắc (Last In - First Out) - (LIFO)
5. Memory Leak: sử dụng (Ví dụ đệ quy nhiều quá) dẫn đến không còn đủ vùng nhớ để chưa nữa
6. Heap:
- Cấp phát động
    - Heap được sử dụng để cấp phát bộ nhớ động trong quá trình thực thi của chương trình.
    - Điều này cho phép chương trình tạo ra và giải phóng bộ nhớ theo như cầu, thích ứng với sự biến đổi của dữ liệu
trong quá trình chạy.
    - Các hàm malloc(), calloc(), realloc() và free() được sử dụng để cấp phát và giải phóng cho bộ nhớ trên heap.
    - Các hàm này phải được chạy trong hàm main

*/

const int a = 0;   // Data - Read Only
int a1 = 10;       // data segment
int a2 = 0;        // BSS Segment
static int b = 10; // Data Segment
static int d = 0;  // BSS
int *ptr1 = NULL;

void test()
{
    static int c = 10;  // Data Segment
    int e = 10;         // Stack
    const int b1 = 100; // Stack
    ptr1 = &b1;
    *ptr1 = 101;
}

typedef struct
{
    int x;
    int y;

} data;

data *sv;

int main()
{
    sv = (data *)malloc(sizeof(data));
    sv->x = 5;
    sv->y = 6;

    int size = 5;

    char arr[50]; // cấp phát tĩnh

    // Hàm malloc(5): Cấp phát 1 vùng nhớ gồm 5 bytes 0x01 0x02 0x03 0x04 0x05 (Các địa chỉ được lấy ở phân vùng heap)

    uint16_t *ptr = (uint16_t *)malloc(size * sizeof(uint16_t)); // Con trỏ trỏ đến địa chỉ đầu tiên của vùng nhớ được cấp phát.
    // Cần lưu ý số lượng phần tử và kích thước kiểu dữ liệu của phần tử
    // Malloc là một con trỏ void nên muốn đọc dữ liệu đúng thù nên ép kiểu nó về
    // Không gán giá trị thì nó sẽ đưa ra các giá trị rác

    // Gán giá trị:
    ptr[0] = 5;
    ptr[1] = 10;

    // Đọc dữ liệu của mảng:

    for (int i = 0; i < size; i++)
    {
        printf("Địa chỉ %d: %p - Value: %d\n", i, ptr + i, *(ptr + i));
    }

    ptr = realloc(ptr, 20); // Realloc dùng để thay đổi kích thước vùng nhớ đã được cấp phát

    for (int i = 0; i < 20; i++)
    {
        ptr[i] = i * 5;
    }

    for (int i = 0; i < 20; i++)
    {
        printf("Địa chỉ %d: %p - Value: %d\n", i, ptr + i, *(ptr + i));
    }

    int *arr1 = (int *)calloc(5, sizeof(int)); // Hàm calloc có điểm khác biệt là nó sẽ có khởi tạo giá trị bằng 0

    for (int i = 0; i < 5; i++)
    {
        printf("Địa chỉ: %p - Value: %d\n", arr1 + i, *(arr1 + i));
    }

    free(ptr);

    ptr = NULL;

    free(arr1);
    arr1 = NULL;

    free(sv);
    sv = NULL;
    return 0;
}