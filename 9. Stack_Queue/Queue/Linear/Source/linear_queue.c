#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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
    return ((queue.rear == queue.size - 1) ? true : false);
}

bool queue_isEmpty(Queue queue)
{
    return ((queue.rear == -1) || (queue.front > queue.rear) ? true : false);
}

int enqueue(Queue *queue, int data)
{
    if (queue_isFull(*queue))
    {
        printf("Queue đã đầy!\n");
    }
    else
    {
        // ++queue->rear;
        // if (queue->front == -1)
        //     queue->front = 0;

        queue->item[++queue->rear] = data;

        printf("Đã thêm phần tử: %d - Địa chỉ: %d\n", queue->item[queue->rear], &(queue->item[queue->rear]));

        return (queue->item[queue->rear]);
    }
}

int dequeue(Queue *queue)
{
    if (queue_isEmpty(*queue))
    {
        printf("Queue Rỗng!\n");
        return QUEUE_EMPTY;
    }
    else
    {
        int dequeue_value = queue->item[queue->front];

        printf("Đã xóa phần tử : %d - Địa chỉ: %d\n", queue->item[queue->front], &(queue->item[queue->front]));

        queue->item[queue->front++] = 0;

        // queue->front++;

        if (queue->front > queue->rear)
        {
            queue->front = -1;
            queue->rear = -1;
        }

        return dequeue_value;
    }
}

void queue_free(Queue *queue)
{
    free(queue->item);
    printf("Đã giải phóng hàng đợi thành công!\n");
}

int main()
{
    Queue queue;

    queue_init(&queue, 5);

    printf("ENQUEUE PROCESS...\n");

    enqueue(&queue, 10);
    enqueue(&queue, 15);
    enqueue(&queue, 20);
    enqueue(&queue, 5);
    enqueue(&queue, 11);
    enqueue(&queue, 16);

    // Print Elements

    printf("\n");
    printf("PRINT PROCESS...\n");

    for (int i = 0; i < queue.size; i++)
    {
        printf("Phần tử thứ: %d - Giá trị: %d - Địa chỉ: %d\n", i + 1, queue.item[i], &(queue.item[i]));
    }

    // Xóa phần tử

    printf("\n");

    printf("DEQUEUE PROCESS...\n");

    for (int i = 0; i <= queue.size; i++)
    {
        dequeue(&queue);
    }

    queue_free(&queue);

    return 0;
}