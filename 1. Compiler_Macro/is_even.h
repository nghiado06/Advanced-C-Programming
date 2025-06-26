#ifndef IS_EVEN_H
#define IS_EVEN_H

#include <stdio.h>

void is_even(int x)
{
    ((x % 2 == 0) ? printf("Đây là số chẵn") : printf("Đây là số lẻ"));
    printf("\n");
}

#endif