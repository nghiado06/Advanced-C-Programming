#include <stdio.h>
#include <stdarg.h>

#define ON 1
#define OFF 0

void log_sensor_data(const char* sensor_name, int count,...)
{
    va_list args;
    va_start(args,count);

    printf("Logging %s data: ", sensor_name);

   for (int i = 0; i< count; i++){
    double value = va_arg(args, double);
    printf("%.2f ", value);

   }


    va_end(args); 

}

void digitalWrite(int GPIO, int state){
    printf("GPIO %d --> %s\n", GPIO, (state == ON ? "ON" : "OFF"));
}

void led_controllers(int state, int count, ...){
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++){
        int GPIO = va_arg(args, int);
        digitalWrite(GPIO, state);
    }

    va_end(args);

}

int main(){
    log_sensor_data("Temparature", 3, 2.04, 2.07, 3.60);
    printf("\n");

    int LED1 = 17, LED2 = 16, LED3 = 14, LED4 = 10;

    led_controllers(ON, 3, LED1, LED2, LED3);
    led_controllers(OFF, 1, LED4);


    return 0;
}