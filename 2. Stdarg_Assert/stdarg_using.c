#include <stdio.h>
#include <stdarg.h>

//Hàm sum với đối số cố định
int sum(int count, ...){
    va_list args;

    va_start(args, count);

    int results;

    for (int i = 0; i < count; i++){
        results += va_arg(args, int);
    }
    return results;

}

//Hàm sum với đối số không cố định
#define tong(...) sum2(__VA_ARGS__, 'a')


int sum2(int count, ...){
    va_list args;
    va_list args2;

    va_start(args,  count);
    va_copy(args2, args);

    int result = count;

    while ((va_arg(args2, char*)) != (char*)'a'){
        result += va_arg(args, int); 
    }

    va_end(args);
    return result;
}


int main(){


    return 0;
}