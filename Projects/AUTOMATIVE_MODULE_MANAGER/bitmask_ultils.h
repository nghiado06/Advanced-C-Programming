#ifndef BITMASK_ULTILS_H
#define BITMASK_ULTILS_H

#include <stdint.h>

#define STATUS_ON (1 << 0)
#define STATUS_ERROR (1 << 1)
#define STATUS_WARNING (1 << 2)

// Hàm kích hoạt trạng thái
void StatusEnabled(uint8_t *status, uint8_t Status);
// Hàm tắt trạng thái
void StatusUnenabled(uint8_t *status, uint8_t Status);
// Hàm kiểm tra trạng thái
void StatusChecked(uint8_t status, uint8_t Status);

#endif