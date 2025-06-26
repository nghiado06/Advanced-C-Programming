#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*Cấu trúc Dữ liệu - Thuật Toán
- Cấu trúc dữ liệu: Cách tổ chức, lưu trữ, xử lý dữ liệu. Được chia làm 2 loại chính:
    - Cấu trúc dữ liệu tuyến tính (Linear Structure): mảng (Array), ngăn xếp (Stack), hàng đợi (Queue), danh sách liên kết (Linked List)
    - Cấu trúc dữ liệu phi tuyến tính (Non-linear Data Structure): đồ thị (Graph), cây (Trees)

1. Stack:
- Hoạt động theo nguyên tắc LIFO
- Các thao tác với stack:
    - push: thêm phần tử (element) vào đỉnh (top) của stack
    - pop: xóa phần tử (element) ở đỉnh (top) của stack
    - peak/top: đọc giá trị phần tử ở đỉnh ngăn xếp
    - Kiểm tra stack đầy: top = size - 1
    - Kiểm tra stack rỗng: top = -1
- 1 Stack sẽ bao gồm 3 thông số sau:
    - size: sô lượng phần tử do mình quy định
    - top: chỉ số ở đỉnh để mình truy cập vào
    - *item: mảng chứa các giá trị add vào


2. Queue:
- Là một cấu trúc dữ liệu tuân theo nguyên tắc FIFO (First In First Out)
- Các thao tác với queue:
    - Enqueue: Thêm phần tử vào cuối hàng đợi
    - Dequeue: Xóa phần tử ra khổi đầu hàng đợi
    - front: Để lấy giá trị phần tử đầu hàng đợi
    - rear: Lấy giá trị phần tử cuối hàng đợi
    - Kiểm tra hàng đầy hay rỗng
- Các loại hàng đợi:
    - Linear Queue (Hàng đợi tuyến tính):
        - Khởi tạo : front  = -1, rear = -1
        - Phần tử đầu: front = 0, rear ++
        - Thêm phần tử: front = 0, rear ++
        - Xóa phần tử: front ++, rear = size - 1
        - Rỗng khi front > rear
    Nhược điểm:
        - Khi đã thêm đầy các phần tử thì không thể thêm nữa mặc dù đã xóa đi 1 hoặc 1 vài phần tử.
    bắt buộc phải xóa hết các phần tử đang có rồi mới thêm mới vào được
    - Circular Queue:
        - Khác biệt: full = front == (rear + 1) % size
*/

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
    }
}

int top(Stack stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is Empty!\n");
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

// QUEUE

typedef struct
{
    int *item;
    int size;
    int front;
    int rear;
} Queue;

#define QUEUE_EMPTY -1

void queue_init(Queue *queue, int newSize)
{
    queue->item = (int *)calloc(newSize, sizeof(int));
    queue->size = newSize;
    queue->front = -1;
    queue->rear = -1;
}

bool queue_isFull(Queue queue)
{
    return (((queue.front <= queue.rear) && (queue.rear == queue.size - 1)) ? true : false);
}

bool queue_isEmpty(Queue queue)
{
    return ((queue.rear = -1) || (queue.front > queue.rear) ? true : false);
}

int enqueue(Queue *queue, int data)
{
    if (queue_isFull(*queue))
    {
        printf("Queue đã đầy!");
        return;
    }
    ++queue->rear;
    if (queue->front == -1)
        queue->front++;
    queue->item[queue->rear] = data;

    return (queue->item[queue->rear]);
}

int dequeue(Queue *queue)
{
    if (queue_isEmpty(*queue))
    {
        printf("Queue Rỗng!");
        return;
    }
    int dequeue_value = queue->item[queue->front];
    queue->item[queue->front] = 0;

    queue->front++;

    if ((queue->front == queue->rear + 1) && (queue->rear = queue->size - 1))
    {
        queue->front = -1;
        queue->rear = -1;
    }

    return dequeue_value;
}

void queue_free(Queue *queue)
{
    free(queue->item);
}

int main()
{
    Stack stack1;

    init(&stack1, 5);

    printf("Push Process...\n");
    for (int i = 1; i <= stack1.size; ++i)
    {
        push(&stack1, i * 5);
    }

    printf("\n");

    printf("Print Elements...\n");

    for (int i = 0; i < stack1.size; ++i)
    {
        printf("Element: %d - Address: %d - Value: %d\n", i + 1, &(stack1.item[i]), stack1.item[i]);
    }

    printf("\n");

    printf("Pop Process...");

    for (int i = 0; i < stack1.size; i++)
    {
        printf("Element: %d - Address: %d - Value: %d\n", i + 1, &(stack1.item[stack1.top]), stack1.item[stack1.top]);
        pop(&stack1);
    }

    return 0;
}