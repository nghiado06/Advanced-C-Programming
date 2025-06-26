#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "module_manager.h"

Module *module_list = NULL;
int module_count = 0;

void initModules() // Reset danh sách các modules
{
    module_list = NULL;
    module_count = 0;
};

void addModule(uint8_t id, const char *name)
{
    module_list = (Module *)realloc(module_list, (module_count + 1) * sizeof(Module)); // Dùng Realloc để khởi tạo các giá trị bằng 0
    module_list[module_count].id = id;
    strcpy(module_list[module_count].name, name);
    module_list[module_count].status = 0;
    module_count++; // Tăng số thứ tự module
};

void controlModule(uint8_t id, uint8_t Status, void (*status_control)(uint8_t *, uint8_t), void (*control_func)(void))
{
    status_control(&(module_list[(id - 1)].status), Status); // Điều khiển trạng thái với Thư viện Bitmask_Ulis
    module_list[(id - 1)].control_func = control_func;       // Sử dụng các hàm điều khiển bên function_handler
};

void printModules()
{
    printf("\\nDANH SÁCH MODULE:\\n");
    for (int i = 0; i < module_count; i++)
    {
        printf("ID: %d, Tên: %s\n", module_list[i].id, module_list[i].name);
    }
};
