#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "bitmask_ultils.h"
#include "function_handler.h"
#include "module_manager.h"
#include "error_handler.h"

int main()
{
    if (setjmp(safe_state) == 0)
    {                  // Thiết lập trạng thái an toàn
        initModules(); // Khởi tạo danh sách module

        addModule(1, "Động cơ ECU");
        addModule(2, "Phanh ABS");

        printModules(); // Hiển thị danh sách module

        controlModule(1, STATUS_ON, StatusEnabled, Motor_Control); // Bật động cơ ECU
        controlModule(2, STATUS_ON, StatusEnabled, ABS_Control);   // Điều khiển phanh ABS
    }
    else
    {
        printf("Chương trình đã quay về trạng thái an toàn sau lỗi.\\n");
    }

    freeModules(module_list);
    return 0;
}
