# TÌM HIỂU VỀ LINKED LIST
- Tìm hiểu về Khái niệm Linked List
- Tìm hiểu về các hàm thao tác với Linked List:
	- Cấu trúc của Node
	- Hàm createNode
	- Hàm push_back
	- Hàm push_front
	- Hàm pop_back
	- Hàm pop_front
	- Hàm front/back
	- Hàm insert
	- Hàm erase
	- Hàm size
	- Hàm get
	- Hàm empty
	- Hàm clear

# 1. KHÁI NIỆM
- Linked list là một cấu trúc dữ liệu trong lập trình máy tính, được sử dụng để tổ chức
và lưu trữ dữ liệu. Một linked list bao gồm một chuỗi các "nút" (nodes), mỗi nút chứa một
giá trị dữ liệu và một con trỏ (pointer) đến nút tiếp theo trong chuỗi.

# 2. HÀM THAO TÁC
- Cùng tìm hiểu về các hàm thao tác chính với cấu trúc dữ liệu Linked List

## 2.1 Cấu trúc Node
- Một node sẽ được cấu trúc bao gồm giá trị của node, và **địa chỉ của node kế tiếp**.
- Địa chỉ của các node này có thể hoàn toàn nằm độc lập, không kề bên nhau.
- Bản chất của mỗi một node chính là 1 con trỏ được cấu trúc bới 2 phần tử trên.
- **Địa chỉ của node kế tiếp** chính là **bản thân node kế tiếp**. Tức có nghĩa là node sẽ lưu 1 con trỏ và con trỏ này chính là node tiếp theo mà nó liên kết.

```cpp
typedef struct node
{
	int value;
	struct node* next;
} node;
```

## 2.2 Hàm createNode
- Hàm createNode sẽ khởi tạo 1 con trỏ Node. Lưu giá trị của node và một con trỏ next dùng để lưu node tiếp theo.

```cpp
node* createNode(int value)
{
    node* ptr = (node*)malloc(sizeof(node)); //Cấp phát động cho con trỏ Node
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}

```

## 2.3 Hàm push_back
- Hàm push_back giúp ta thêm một node mới vào phía sau danh sách liên kết.
- Vì ta đang có Node dưới dạng 1 con trỏ, nên muốn thay đổi trực tiếp vào node này. Ta sử dụng con trỏ cấp hai.

```cpp
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
	//Di chuyển đến node cuối cùng bằng 1 con trỏ p tạm thời
        Node *p = *head;
        while (p->next != NULL)
            p = p->next;
        p->next = new_node;
    }
}
```

## 2.4 Hàm push_front
- Hàm push_frotn dùng để thêm một node vào đầu danh sách liên kết.

```cpp
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
```

## 2.5 Hàm pop_back
- Hàm pop_back dùng để xóa node cuối cùng của danh sách liên kết.

```cpp

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

```

## 2.6 Hàm pop_front
- Hàm pop_front dùng để xóa node đầu tiên của danh sách liên kết.

```cpp
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
```

## 2.7 Hàm front/back
- Hàm front/back dùng để đọc giá trị của node đầu tiên và node cuối cùng.

- **Hàm front**

```cpp
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
```

- **Hàm back**

```cpp
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
```

## 2.8 Hàm insert
- Hàm insert dùng để thêm một node vào vị trí bất kỳ.

```cpp
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

```

## 2.9 Hàm erase
- Hàm erase dùng để xóa một node nằm ở vị trí bất kỳ.

```cpp
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
```

## 2.10 Hàm size
- Hàm size dùng để đọc số lượng node trong danh sách liên kết.

```cpp
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
```

## 2.11 Hàm get
- Hàm get dùng để đọc giá trị phần tử của một node bất kỳ.

```cpp
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
```

## 2.12 Hàm empty
- Hàm empty dùng để kiểm tra nếu danh sách liến kết đó rỗng.

```cpp
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
```

## 2.13 Hàm clear
- Hàm clear dùng để xóa tất cả các node của danh sách liên kết.

```cpp
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
```

## 2.14 Chương trình mẫu sử dụng Linked List

```cpp
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
```

output

```
Node: 1 - Value: 17 - Node Address: 6291088
Node: 2 - Value: 1 - Node Address: 6291088
Node: 3 - Value: 10 - Node Address: 6291088
Node: 4 - Value: 5 - Node Address: 6291088
Node: 5 - Value: 15 - Node Address: 6291088
Giá trị Node đầu tiên: 17
Giá trị của Node cuối là: 15
Số lượng Node trong Linked List là: 5
Giá trị Node thứ 3 là: 10
Vượt khỏi Kích thước Linked List!
Node: 1 - Value: 17 - Node Address: 6291088
Node: 2 - Value: 1 - Node Address: 6291088
Node: 3 - Value: 11 - Node Address: 6291088
Node: 4 - Value: 10 - Node Address: 6291088
Node: 5 - Value: 5 - Node Address: 6291088
Node: 6 - Value: 21 - Node Address: 6291088
Node: 7 - Value: 15 - Node Address: 6291088
Node: 1 - Value: 17 - Node Address: 6291088
Node: 2 - Value: 1 - Node Address: 6291088
Node: 3 - Value: 11 - Node Address: 6291088
Node: 4 - Value: 5 - Node Address: 6291088
Node: 5 - Value: 21 - Node Address: 6291088
Node: 6 - Value: 15 - Node Address: 6291088
Clear Process...
Clear Successfully!
Node rỗng!
```
