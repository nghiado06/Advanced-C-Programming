#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include <setjmp.h>

extern jmp_buf safe_state;

void handleError();

void freeModules();

#endif
