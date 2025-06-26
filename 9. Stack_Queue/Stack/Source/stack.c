#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

typedef struct
{
    int *item; // Mảng (cấp phát động) chứa các giá trị chèn vào
    int top;   // Chỉ số lấy giá trị ở đỉnh
    int size;  // Số lượng phần tử tối đa
} Stack;

#define STACK_EMPTY -1

void init(Stack *stack, int newSize)
{
    stack->item = (int *)malloc(newSize * sizeof(int));
    stack->top = -1;
    stack->size = newSize;
}

bool isEmpty(Stack stack)
{
    return (stack.top == -1 ? true : false);
}

bool isFull(Stack stack)
{
    return (stack.top == (stack.size - 1) ? true : false);
}

void push(Stack *stack, int data)
{
    if (isFull(*stack))
    {
        printf("Khong the them. Stack da day\n");
    }
    else
    {
        stack->item[++(stack->top)] = data;
        printf("Data: %d - Element: %d Push Successfully!\n", data, stack->top);
        // stack->top++;
        // stack->item[stack->top] = data;
    }
}

int pop(Stack *stack)
{
    if (isEmpty(*stack))
    {
        printf("Stack Empty!\n");
        return STACK_EMPTY;
    }
    else
    {
        int val = stack->item[stack->top];
        stack->item[stack->top--] = 0;
        return val;
    }
}

int top(Stack stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is Empty!\n");
        return STACK_EMPTY;
    }
    else
    {
        return stack.item[stack.top];
    }
}

void stack_free(Stack *stack)
{
    if (stack->item != NULL)
    {
        free(stack->item);
        stack->item = NULL;
    }
}
