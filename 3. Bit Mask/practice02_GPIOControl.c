#include <stdio.h>
#include <stdint.h>

#define ON 1
#define OFF 0

typedef struct
{
    uint8_t LED1 : 1;
    uint8_t LED2 : 1;
    uint8_t LED3 : 1;
    uint8_t LED4 : 1;
    uint8_t LED5 : 1;
    uint8_t LED6 : 1;
    uint8_t LED7 : 1;
    uint8_t LED8 : 1;

} GPIO_LED;

void ledController(GPIO_LED *Led, uint8_t ledNumber, uint8_t on_off)
{
    uint8_t *ledPtr = (uint8_t *)Led;
    if (on_off == 1)
    {
        *ledPtr |= (1 << (ledNumber - 1));
    }
    else
    {
        *ledPtr &= ~(1 << (ledNumber - 1));
    }
}

void AllLedDisplay(GPIO_LED *Led)
{
    uint8_t *LedPtr = (uint8_t *)Led;
    for (int i = 0; i < 8; i++)
    {
        if ((*LedPtr & (1 << i)) != 0)
        {
            printf("LED%d is ON\n", i + 1);
        }
        else if ((*LedPtr & (1 << i)) == 0)
        {
            printf("LED%d is OFF\n", i + 1);
        }
    }
}

int main()
{
    GPIO_LED Led = {0};
    ledController(&Led, 7, ON);
    ledController(&Led, 3, ON);

    AllLedDisplay(&Led);

    return 0;
}