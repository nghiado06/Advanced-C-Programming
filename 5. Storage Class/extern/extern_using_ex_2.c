#include <stdio.h>

// Biến extern dùng để sử dụng qua lại giữa các file
// Điều kiện là nó phải là biến toàn cục
extern int wide_using;
extern void print();

int main()
{
    print();
    return 0;
}