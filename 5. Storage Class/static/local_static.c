#include <stdio.h>

int *ptr = NULL;

void count()
{
    static int a = 0;
    ptr = &a;
    ++a;
    printf("Địa chỉ của a: %d\n", ptr);
    printf("Giá trị của a: %d\n", a);
}

int main()
{
    count();
    count();
    count();
    return 0;
}