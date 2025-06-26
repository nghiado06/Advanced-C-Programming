#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool queue_isEmpty(Queue queue)
{
    return ((queue.front == -1) ? true : false);
}

bool queue_isFull(Queue queue)
{
    if (queue.front == -1)
        return false; // Nếu hàng đợi rỗng, chắc chắn không đầy
    return ((queue.rear + 1) % queue.size == queue.front);
}

int enqueue(Queue *queue, int data)
{
    if (queue_isFull(*queue))
    {
        printf("Queue đã đầy!\n");
    }
    else
    {
        if (queue->front == -1)
        {
            queue->front = queue->rear = 0;
        }
        else
        {
            queue->rear = (queue->rear + 1) % queue->size;
        }

        queue->item[queue->rear] = data;

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

        if (queue->front == queue->rear)
        {
            queue->front = -1;
            queue->rear = -1;
        }
        else
        {
            queue->front = (queue->front + 1) % queue->size;
        }

        return dequeue_value;
    }
}

int front(Queue queue)
{
    if (queue_isEmpty(queue))
    {
        printf("Hàng đợi rỗng!\n");
        return QUEUE_EMPTY;
    }
    return queue.front;
}

int rear(Queue queue)
{
    if (queue_isEmpty(queue))
    {
        printf("Hàng đợi rỗng!\n");
        return QUEUE_EMPTY;
    }
    return queue.rear;
}

void display(Queue queue)
{
    if (queue_isEmpty(queue))
    {
        printf("Hàng đợi rỗng!\n");
    }
    else
    {
        int i = queue.front;
        while (1)
        {
            printf("%d\n", queue.item[i]);
            if (i == queue.rear)
            {
                printf("Hoàn tất in!\n");
                break;
            }
            i = (i + 1) % queue.size;
        }
    }
}

void queue_free(Queue *queue)
{
    free(queue->item);
}

int main()
{
    Queue queue;

    queue_init(&queue, 5);

    enqueue(&queue, 10);
    enqueue(&queue, 15);
    enqueue(&queue, 20);
    enqueue(&queue, 25);
    enqueue(&queue, 30);

    display(queue);

    printf("Front element: %d\n", front(queue));
    printf("Rear element: %d\n", rear(queue));

    printf("Dequeued %d\n", dequeue(&queue));
    // printf("Dequeued %d\n", dequeue(&queue));
    // printf("Dequeued %d\n", dequeue(&queue));
    // printf("Dequeued %d\n", dequeue(&queue));

    display(queue);

    enqueue(&queue, 50);
    display(queue);

    printf("Front element: %d\n", front(queue));
    printf("Rear element: %d\n", rear(queue));

    queue_free(&queue);

    return 0;
}
