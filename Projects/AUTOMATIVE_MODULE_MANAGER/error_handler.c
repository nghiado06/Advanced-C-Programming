#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>
#include "error_handler.h"
#include "module_manager.h"

jmp_buf safe_state;

void handleError()
{
    printf("Lỗi nghiêm trọng! Đưa hệ thống về trạng thái an toàn.\\n");
    longjmp(safe_state, 1);
}

// Hàm giải phóng bộ nhớ module_list
void freeModules()
{
    if (module_list != NULL)
    {
        free(module_list);
        module_list = NULL; // ✅ Tránh lỗi truy cập bộ nhớ sau khi free
        printf("Đã giải phóng bộ nhớ module_list.\n");
    }
}
