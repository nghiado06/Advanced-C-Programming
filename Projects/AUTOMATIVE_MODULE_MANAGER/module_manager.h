#ifndef MODULE_MANAGER_H
#define MODULE_MANAGER_H

#include "function_handler.h"
#include <stdint.h>

typedef struct
{
    uint8_t id;
    char name[50];
    uint8_t status;             // Trạng thái Module
    void (*control_func)(void); // Hành động điều khiển
} Module;

extern Module *module_list;
extern int module_count;

void initModules();

void addModule(uint8_t id, const char *name);

void printModules();

void controlModule(uint8_t id, uint8_t Status, void (*status_control)(uint8_t *, uint8_t), void (*control_func)(void));

#endif