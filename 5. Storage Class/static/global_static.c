#include <stdio.h>

// Biến static toàn cục sẽ chỉ được sử dụng trong file nguồn hiện tại, các file khác không thể can thiệp vào biến static này nữa, kể cả dùng extern
// Ứng dụng của nó là để skip giai đoạn mà chúng ta không muốn thể hiện
static int wide_using = 90; // Không dùng extern để gọi được nữa

static void display()
{
    printf("%d", wide_using);
}
// Hàm này sẽ không được gọi nữa
int main()
{

    return 0;
}