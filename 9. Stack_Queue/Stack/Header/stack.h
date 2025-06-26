/*=========================================[ INTRODUCTION ]=======================================*/
/**
 * @file stack.h
 * @brief Thư viện stack hỗ trợ khai báo các hàm thao tác với stack
 * @details Cung cấp các hàm khởi tạo, thêm, xóa, đọc phần tử
 *
 * @author Do Duc Nghia
 * @date 09/03/2025
 * @version 1.0
 */

#ifndef STACK_H
#define STACK_H

/*=======================================[ INCLUDE LIBRARIES ]====================================*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*=========================================[ DEFINE MACRO ]=========================================*/

#define STACK_EMPTY -1

/*===========================================[ MAIN CODE ]==========================================*/

/**
 * @brief Tạo cấu trúc dữ liệu Stack với các thành phần
 * @param item Mảng dùng để lưu các phần tử
 */

typedef struct
{
    int *item; // Mảng (cấp phát động) chứa các giá trị chèn vào
    int top;   // Chỉ số lấy giá trị ở đỉnh
    int size;  // Số lượng phần tử tối đa
} Stack;

/**
 * @brief Hàm dùng để khởi tạo các giá trị đầu vào
 * @param newSize kích thước khởi tạo (Số lượng phần tử)
 * @return void
 */

void init(Stack *stack, int newSize);

/**
 * @brief Hàm dùng để kiểm tra nếu stack rỗng
 * @return bool
 */

bool isEmpty(Stack stack);

/**
 * @brief Hàm dùng để kiểm tra nếu stack đầy
 * @return bool
 */

bool isFull(Stack stack);

/**
 * @brief Hàm dùng để thêm phần tử vào stack
 * @param data Giá trị của phần tử được thêm vào
 * @return void
 */

void push(Stack *stack, int data);

/**
 * @brief Hàm dùng để xóa phần tử ra khỏi stack
 * @return int
 */

int pop(Stack *stack);

/**
 * @brief Hàm dùng để lấy giá trị phần tử ở đỉnh
 * @return int
 */

int top(Stack stack);

/**
 * @brief Hàm dùng để giải phóng stack
 * @return void
 */

void stack_free(Stack *stack);

#endif
