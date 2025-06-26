#include <stdio.h>

void tong(int a, int b)
{
    printf("Tổng là: %d", a + b);
}

int main()
{
    void (*ptr)(int, int) = tong;
    int a = 10;
    int b = 10;
    ptr(a, b);

    int *ptr2;
    printf("Size of pointer: %d bytes\n", sizeof(ptr2));

    return 0;
}