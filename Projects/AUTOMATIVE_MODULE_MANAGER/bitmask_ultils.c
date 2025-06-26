#include <stdio.h>
#include <stdint.h>

void StatusEnabled(uint8_t *status, uint8_t Status)
{
    *status |= Status;
};

void StatusUnenabled(uint8_t *status, uint8_t Status)
{
    *status &= (~Status);
};

void StatusChecked(uint8_t *status, uint8_t Status)
{
    printf((*status & Status != 0) ? "Status Found" : "Status Not Found");
};
