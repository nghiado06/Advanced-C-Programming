#include <stdio.h>
#include "print.h"
#include "is_even.h"

#define COUT(name) \
    printf(name)

#define PI 3.14

int main()
{
    COUT("Nghĩa\n");
    print();
    is_even(7);

    return 0;
}