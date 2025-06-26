/***************************************************************************
 * @file    binary_tree.c
 * @brief   Chuyển đổi danh sách liên kết thành cây nhị phân và tìm kiếm nhị phân.
 * @details Chương trình xây dựng danh sách liên kết đơn, sau đó chuyển đổi danh sách
 *          thành cây nhị phân tìm kiếm (BST). Hỗ trợ thêm node, tìm điểm giữa danh sách,
 *          và thực hiện tìm kiếm nhị phân.
 *          File source cho các hàm.
 * @version 1.0
 * @date    30-03-2025
 * @author  Duc Nghia
 ***************************************************************************/

#include "../Header/binary_tree.h"
#include "../Header/file_operations.h"

/**
 * @brief   Thêm node vào danh sách liên kết và sắp xếp theo thứ tự tăng dần số điện thoại.
 * @param   head   Con trỏ đến con trỏ head của danh sách liên kết.
 * @param   value  Giá trị cần thêm vào danh sách.
 * @return  void
 */
void add_node_numberSort(Node **head, DataBase value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->sorted_data = value.number;
    new_node->name = value.userName;
    new_node->number = value.number;
    new_node->age = value.age;
    new_node->addr = value.addr;
    new_node->next = NULL;

    if (*head == NULL || (*head)->sorted_data >= value.number)
    {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    Node *current = *head;
    while (current->next != NULL && current->next->sorted_data < value.number)
    {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
}

/**
 * @brief   Thêm node vào danh sách liên kết và sắp xếp theo thứ tự tăng dần tổng mã ASCII của tên người dùng.
 * @param   head   Con trỏ đến con trỏ head của danh sách liên kết.
 * @param   value  Giá trị cần thêm vào danh sách.
 * @return  void
 */
void add_node_nameSort(Node **head, DataBase value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->sorted_data = value.name;
    new_node->name = value.userName;
    new_node->number = value.number;
    new_node->addr = value.addr;
    new_node->age = value.age;
    new_node->next = NULL;

    if (*head == NULL || (*head)->sorted_data >= value.name)
    {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    Node *current = *head;
    while (current->next != NULL && current->next->sorted_data < value.name)
    {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
}

/**
 * @brief   Xây dựng cây nhị phân từ danh sách liên kết.
 * @details Tìm điểm giữa danh sách và chia danh sách thành cây nhị phân tìm kiếm.
 * @param   head   Con trỏ đến danh sách liên kết.
 * @param   start  Vị trí bắt đầu của danh sách.
 * @param   end    Vị trí kết thúc của danh sách.
 * @return  CenterPoint*   Gốc của cây nhị phân tìm kiếm.
 */
CenterPoint *buildTree(Node *head, int start, int end)
{
    if (head == NULL || start > end)
    {
        return NULL;
    }

    int mid = (start + end) / 2;
    Node *node = head;

    for (int i = start; i < mid; i++)
    {
        if (node->next == NULL)
            break;
        node = node->next;
    }

    CenterPoint *root = (CenterPoint *)malloc(sizeof(CenterPoint));
    root->sorted_value = node->sorted_data;
    root->name = node->name;
    root->number = node->number;
    root->addr = node->addr;
    root->age = node->age;
    root->left = buildTree(head, start, mid - 1);
    root->right = buildTree(node->next, mid + 1, end);
    return root;
}

/**
 * @brief   Chuyển danh sách liên kết thành cây nhị phân tìm kiếm (BST).
 * @details Tính độ dài danh sách liên kết và gọi `buildTree()` để xây dựng BST.
 * @param   head  Con trỏ đến danh sách liên kết.
 * @return  CenterPoint*  Gốc của cây nhị phân tìm kiếm.
 */
CenterPoint *centerPoint(Node *head)
{
    int length = 0;
    Node *node = head;
    while (node != NULL)
    {
        node = node->next;
        length++;
    }
    return buildTree(head, 0, length - 1);
}

/**
 * @brief   Thực hiện tìm kiếm nhị phân trên cây BST.
 * @details Duyệt cây nhị phân để tìm kiếm giá trị cần tìm.
 * @param   root         Gốc của cây nhị phân.
 * @param   phoneNumber  Giá trị số điện thoại cần tìm.
 * @return  CenterPoint*   Trả về con trỏ đến node tìm thấy, NULL nếu không tìm thấy.
 */
CenterPoint *binary_NumberSearch(CenterPoint *root, int phoneNumber)
{
    static int loop = 0;
    loop++;
    printf("Loop Times: %d\n", loop);

    Sleep(500);

    if (root == NULL)
        return NULL;

    if (root->sorted_value == phoneNumber)
    {
        return root;
    }
    else if (phoneNumber < root->sorted_value)
    {
        return binary_NumberSearch(root->left, phoneNumber);
    }
    else
    {
        return binary_NumberSearch(root->right, phoneNumber);
    }
}

/**
 * @brief   Thực hiện tìm kiếm nhị phân trên cây BST.
 * @details Duyệt cây nhị phân để tìm kiếm giá trị cần tìm.
 * @param   root      Gốc của cây nhị phân.
 * @param   userName  Giá trị tên cần tìm.
 * @return  CenterPoint*   Trả về con trỏ đến node tìm thấy, NULL nếu không tìm thấy.
 */
CenterPoint *binary_NameSearch(CenterPoint *root, char *userName)
{

    int ascii = 0;
    /*Chuyển đổi mã ascii*/
    for (int i = 0; userName[i] != '\0'; i++)
    {
        ascii += (int)userName[i];
    }

    /*Kiểm tra lần lặp*/
    static int loop = 0;
    loop++;
    printf("Loop Times: %d\n", loop);

    Sleep(500);

    if (root == NULL)
        return NULL;

    if ((root->sorted_value == ascii) && (strcmp(root->name, userName) == 0))
    {
        return root;
    }
    else if ((ascii < root->sorted_value) && (strcmp(root->name, userName) != 0))
    {
        return binary_NameSearch(root->left, userName);
    }
    else
    {
        return binary_NameSearch(root->right, userName);
    }
}

/**
 * @brief   In danh sách liên kết.
 * @details Duyệt danh sách liên kết và in ra từng phần tử.
 * @param   head  Con trỏ đến danh sách liên kết.
 * @return  void
 */
void print_list(Node *head)
{
    while (head != NULL)
    {
        printf("User Name: %s\n", head->name);
        printf("Phone Number: %d\n", head->number);
        printf("Address: %s\n", head->addr);
        printf("Age: %d\n", head->age);
        head = head->next;
    }
    printf("=====================\n");
}

/**
 * @brief   Giải phóng bộ nhớ.
 * @details Giải phóng bộ nhớ cho node và chuỗi.
 * @param   root  Node tìm được
 * @return  void
 */
void free_tree(CenterPoint *root)
{
    if (root == NULL)
        return;
    free_tree(root->left);
    free_tree(root->right);
    free(root->name); // nếu name cũng malloc
    free(root->addr);
    free(root);
}