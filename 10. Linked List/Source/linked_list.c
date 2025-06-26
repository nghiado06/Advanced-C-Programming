#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
Linked List là một cấu trúc dữ liệu bào gồm chuỗ các nút (nodes) chứa giá trị và con trỏ trỏ đến địa chỉ của node tiếp theo.
    - Cho phép truy cập linh hoạt
    - Yêu cầu 1 vùng nhớ lớn hơn kích thước giá trị, khác với mảng
*/

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

#define EMPTY_NODE -1

Node *createNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

bool empty(Node *head)
{
    if (head == NULL)
    {
        printf("Không có Node!\n");
        return true;
    }
    else
    {
        printf("Có Node!\n");
        return false;
    }
}

int size(Node *head)
{
    if (head == NULL)
    {
        printf("Không có Node!");
        return EMPTY_NODE;
    }
    else
    {
        int i = 1;
        while (head->next != NULL)
        {
            head = head->next;
            ++i;
        }
        return i;
    }
}

void push_back(Node **head, int data)
{
    // Tạo node mới trước
    Node *new_node = createNode(data);

    // Kiểm tra điều kiện
    if (*head == NULL)
    {
        *head == new_node;
    }
    else
    {
        Node *p = *head;
        while (p->next != NULL)
            p = p->next;
        p->next = new_node;
    }
}

void push_front(Node **head, int data)
{
    Node *new_node = createNode(data);

    // Kiểm tra điều kiện
    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        new_node->next = *head;
        *head = new_node;
    }
}

void pop_front(Node **head)
{
    if (*head == NULL)
    {
        printf("Không có Node!\n");
    }
    else
    {
        Node *p;
        p = *head;
        *head = (*head)->next;
        free(p);
        p = NULL;
    }
}

void pop_back(Node **head)
{
    if (*head == NULL)
    {
        printf("Không có Node!\n");
    }
    else
    {
        Node *p = *head;
        while (p->next->next != NULL)
        {
            p = p->next;
        }
        free(p->next);
        p->next = NULL;
    }
}

int front(Node *head)
{
    if (head == NULL)
    {
        printf("Không có Node!\n");
        return EMPTY_NODE;
    }
    else
    {
        printf("Giá trị Node đầu tiên: %d\n", head->data);
        return head->data;
    }
}

int back(Node *head)
{
    if (head == NULL)
    {
        printf("Không có Node!\n");
        return EMPTY_NODE;
    }
    else
    {
        while (head->next != NULL)
        {
            head = head->next;
        }

        printf("Giá trị của Node cuối là: %d\n", head->data);
        return head->data;
    }
}

void clear(Node **head)
{
    printf("Clear Process...\n");

    if (*head == NULL)
    {
        printf("Không có Node!\n");
    }
    else
    {
        Node *p = *head;
        while ((*head)->next != NULL)
        {
            *head = (*head)->next;
            free(p);
            p = *head;
        }

        free(p);
        *head = NULL;

        printf("Clear Successfully!\n");
    }
}

int get(Node *head, int pos)
{
    if (head == NULL)
    {
        printf("Không có Node!\n");
        return EMPTY_NODE;
    }
    else
    {
        for (int i = 1; i < pos; i++)
        {
            head = head->next;
        }

        printf("Giá trị Node thứ %d là: %d\n", pos, head->data);
        return head->data;
    }
}

void insert(Node **head, int data, int pos)
{
    Node *new_node = createNode(data);

    if (*head == NULL)
    {
        printf("Không có Node!\n");
        *head = new_node;
    }
    else
    {

        Node *p;

        if (pos == size(*head) + 1)
        {
            push_back(head, data);
        }
        else if (pos > size(*head) + 1 || pos < 1)
        {
            printf("Vượt khỏi Kích thước Linked List!\n");
        }
        else
        {

            p = *head;

            for (int i = 1; i < pos - 1; i++)
            {
                p = p->next;
            }

            new_node->next = p->next;
            p->next = new_node;
        }
    }
}

// void insert(Node **head, int data, int pos)
// {
//     int n = size(*head);

//     // Nếu danh sách rỗng và chèn vào đầu
//     if (*head == NULL && pos == 1)
//     {
//         *head = createNode(data);
//         return;
//     }

//     // Kiểm tra vị trí hợp lệ
//     if (pos > n + 1 || pos < 1)
//     {
//         printf("Vượt khỏi Kích thước Linked List! (Kích thước hiện tại: %d)\n", n);
//         return;
//     }

//     // Chèn vào đầu danh sách
//     if (pos == 1)
//     {
//         Node *new_node = createNode(data);
//         new_node->next = *head;
//         *head = new_node;
//         return;
//     }

//     // Duyệt danh sách
//     Node *p = *head;
//     for (int i = 1; i < pos - 1 && p != NULL; i++) // Kiểm tra NULL
//     {
//         p = p->next;
//     }

//     // Nếu p == NULL, nghĩa là vòng lặp chạy quá danh sách
//     if (p == NULL)
//     {
//         printf("Lỗi: p bị NULL khi duyệt danh sách!\n");
//         return;
//     }

//     // Tạo node mới
//     Node *new_node = createNode(data);
//     if (new_node == NULL)
//         return;

//     // Chèn node mới vào danh sách
//     new_node->next = p->next;
//     p->next = new_node;
// }

void erase(Node **head, int pos)
{
    if (*head == NULL)
    {
        printf("Không có Node!\n");
        return;
    }

    if (pos > size(*head) || pos < 1)
    {
        printf("Không nằm trong kích thước của linked list!\n");
        return;
    }

    if (pos == 1)
    {
        pop_front(head);
        return;
    }

    if (pos == size(*head))
    {
        pop_back(head);
        return;
    }

    Node *p;
    p = *head;
    for (int i = 1; i < pos - 1; i++)
    {
        p = p->next;
    }

    Node *temp = p->next;
    p->next = temp->next;
    free(temp);
    temp = NULL;
}

void display(Node *head)
{
    if (head == NULL)
    {
        printf("Node rỗng!\n");
    }
    else
    {
        int i = 0;
        while (head != NULL)
        {
            printf("Node: %d - Value: %d - Node Address: %d\n", i + 1, head->data, &head);
            ++i;
            head = head->next;
        }
    }
}

int main()
{
    // Khởi tạo node
    Node *head = createNode(1);
    Node *second = createNode(10);
    Node *third = createNode(5);

    // Liên kết các node
    head->next = second;
    second->next = third;

    push_back(&head, 15);

    push_back(&head, 16);

    pop_back(&head);

    push_front(&head, 17);

    push_front(&head, 22);

    pop_front(&head);

    display(head);

    front(head);

    back(head);

    printf("Số lượng Node trong Linked List là: %d\n", size(head));

    get(head, 3);

    insert(&head, 11, 7);
    insert(&head, 11, 3);
    insert(&head, 21, 6);
    display(head);

    erase(&head, 4);
    display(head);

    clear(&head);

    display(head);
}