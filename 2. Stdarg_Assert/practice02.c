#include <stdio.h>
#include <stdarg.h>

// Thay digitalWrite bằng HAL_GPIO_WRITEPIN

#define HIGH 1
#define LOW 0
#define HAL_GPIO_WRITEPIN(Pin, state) digitalWrite(Pin, state)

void digitalWrite(int Pin, int state)
{
    printf("GPIO %d --> %s", Pin, ((state == HIGH) ? "ON" : "OFF"));
}

int main()
{

    HAL_GPIO_WRITEPIN(17, HIGH);

    return 0;
}