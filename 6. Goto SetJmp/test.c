#include <stdio.h>

#define THROW(x, ...)  \
    printf("%d\n", x); \
    senc = #__VA_ARGS__;

char *senc;

int main()
{
    THROW(1, In dòng này)
    printf("%s", senc);

    return 0;
}