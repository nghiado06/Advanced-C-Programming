#include <stdio.h>

int main()
{
    int *ptr;             // Con trỏ khi khai báo chưa cấp phát sẽ có thể trỏ đến 1 địa chỉ rác, gây tốn bộ nhớ
    int *null_ptr = NULL; // Con trỏ khi này không trỏ đến một địa chỉ cụ thể nào cả.

    printf("Địa chỉ của ptr: %p\n", ptr);
    printf("Địa chỉ của con trỏ NULL: %p\n", (void *)null_ptr); // Vì nó không trỏ đến 1 địa chỉ hợp lệ nào cả nên cần ép kiểu để nó xuất được địa chỉ. Thông thường địa chỉ này sẽ là 0x00

    return 0;
}