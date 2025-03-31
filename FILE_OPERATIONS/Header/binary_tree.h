/*************************************************************************
 * @file    binary_tree.h
 * @brief   Sử dụng các hàm trong Binary Search Tree
 * @details Tái sử dụng lại các hàm đã định nghĩa trong file source
 * @version 1.0
 * @date    30-03-2025
 * @author  Duc Nghia
 ************************************************************************/

/*==================DEFINITIONS=====================*/
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

/*==================INCLUDE LIBRARY=====================*/
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

/*===================FUNCTIONS CALLBACKS=======================*/

typedef struct DataBase DataBase;

/**
 * @struct  Node
 * @brief   Cấu trúc của một node trong danh sách liên kết đơn.
 */
typedef struct Node
{
    int sorted_data; /**< Giá trị dùng để sắp xếp của node */
    int number;      /*Giá trị dùng để so sánh số điện thoại*/
    char *name;      /*Giá trị dùng để so sánh tên người dùng*/
    int age;
    char *addr;
    struct Node *next; /**< Con trỏ đến node tiếp theo */
} Node;

/**
 * @struct  CenterPoint
 * @brief   Cấu trúc của một node trong cây nhị phân tìm kiếm.
 */
typedef struct CenterPoint
{
    int sorted_value; /**< Giá trị sắp xếp của node */
    int number;       /*Giá trị dùng để đối chiếu số điện thoại*/
    char *name;       /*Giá trị so sánh*/
    int age;
    char *addr;
    struct CenterPoint *left;  /**< Con trỏ đến node con trái */
    struct CenterPoint *right; /**< Con trỏ đến node con phải */
} CenterPoint;

/**
 * @brief   Thêm node vào danh sách liên kết và sắp xếp theo thứ tự tăng dần.
 * @param   head   Con trỏ đến con trỏ head của danh sách liên kết.
 * @param   value  Giá trị cần thêm vào danh sách.
 * @return  void
 */
void add_node_nameSort(Node **head, DataBase value);

/**
 * @brief   Thêm node vào danh sách liên kết và sắp xếp theo thứ tự tăng dần.
 * @param   head   Con trỏ đến con trỏ head của danh sách liên kết.
 * @param   value  Giá trị cần thêm vào danh sách.
 * @return  void
 */
void add_node_numberSort(Node **head, DataBase value);

/**
 * @brief   Xây dựng cây nhị phân từ danh sách liên kết.
 * @details Tìm điểm giữa danh sách và chia danh sách thành cây nhị phân tìm kiếm.
 * @param   head   Con trỏ đến danh sách liên kết.
 * @param   start  Vị trí bắt đầu của danh sách.
 * @param   end    Vị trí kết thúc của danh sách.
 * @return  CenterPoint*   Gốc của cây nhị phân tìm kiếm.
 */
CenterPoint *buildTree(Node *head, int start, int end);

/**
 * @brief   Chuyển danh sách liên kết thành cây nhị phân tìm kiếm (BST).
 * @details Tính độ dài danh sách liên kết và gọi `buildTree()` để xây dựng BST.
 * @param   head  Con trỏ đến danh sách liên kết.
 * @return  CenterPoint*  Gốc của cây nhị phân tìm kiếm.
 */
CenterPoint *centerPoint(Node *head);

/**
 * @brief   Thực hiện tìm kiếm nhị phân trên cây BST.
 * @details Duyệt cây nhị phân để tìm kiếm giá trị cần tìm.
 * @param   root         Gốc của cây nhị phân.
 * @param   phoneNumber  Giá trị số điện thoại cần tìm.
 * @return  CenterPoint*   Trả về con trỏ đến node tìm thấy, NULL nếu không tìm thấy.
 */
CenterPoint *binary_NumberSearch(CenterPoint *root, int phoneNumber);

/**
 * @brief   Thực hiện tìm kiếm nhị phân trên cây BST.
 * @details Duyệt cây nhị phân để tìm kiếm giá trị cần tìm.
 * @param   root      Gốc của cây nhị phân.
 * @param   userName  Giá trị tên cần tìm.
 * @return  CenterPoint*   Trả về con trỏ đến node tìm thấy, NULL nếu không tìm thấy.
 */
CenterPoint *binary_NameSearch(CenterPoint *root, char *userName);

/**
 * @brief   In danh sách liên kết.
 * @details Duyệt danh sách liên kết và in ra từng phần tử.
 * @param   head  Con trỏ đến danh sách liên kết.
 * @return  void
 */
void print_list(Node *head);

/**
 * @brief   Giải phóng bộ nhớ.
 * @details Giải phóng bộ nhớ cho node và chuỗi.
 * @param   root  Node tìm được
 * @return  void
 */
void free_tree(CenterPoint *root);

#endif