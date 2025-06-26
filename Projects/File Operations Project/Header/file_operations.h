/*************************************************************************
 * @file    file_operations.h
 * @brief   Khai báo các hàm xử lý file/
 * @details Tái sử dụng lại các hàm đã định nghĩa trong file source
 * @version 1.0
 * @date    30-03-2025
 * @author  Duc Nghia
 ************************************************************************/

/*==================DEFINITIONS=====================*/
#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

/*==================INCLUDE LIBRARY=====================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_tree.h"
#include <Windows.h>

/*===================FUNCTIONS CALLBACKS=======================*/

/**
 * @struct  User
 * @brief   Cấu trúc lưu thông tin người dùng.
 * @details Cấu trúc này chứa tên, tuổi, địa chỉ và số điện thoại của người dùng.
 */
typedef struct
{
    char *name; /**< Tên của người dùng */
    int age;    /**< Tuổi của người dùng */
    char *addr; /**< Địa chỉ của người dùng */
    int phone;  /**< Số điện thoại của người dùng */
} User;

/**
 * @struct  DataBase
 * @brief   Cấu trúc lưu thông tin dữ liệu để search.
 * @details Cấu trúc này chứa tổng mã ascii của tên và số điện thoại của người dùng.
 */
typedef struct DataBase
{
    int name;       /*Tổng mã ASCII của tên user*/
    int number;     /*Số điện thoại của user*/
    char *userName; /*Tên người dùng*/
    int age;
    char *addr;
} DataBase;

/**
 * @brief   Chuyển đổi dữ liệu đầu vào sang dữ liệu xử lý
 * @details Chuyển đổi các dữ liệu khác nhau sang cùng 1 kiểu dữ liệu để sắp xếp
 * @param   userName    Tên người dùng
 * @param   phoneNumber Số điện thoại người dùng
 * @return  DataBase
 */
DataBase dataBase(char *userName, int phoneNumber, char *address, int age);

/**
 * @brief   Giải phóng bộ nhớ cho các trường của cấu trúc User.
 * @details Hàm này giải phóng bộ nhớ đã cấp phát động cho các member của cấu trúc `User`.
 * @param   user: Con trỏ đến cấu trúc `User` cần giải phóng.
 */
void free_user(User *user);

/**
 * @brief   Đọc dữ liệu từ file CSV và in thông tin người dùng.
 * @details Hàm này mở file CSV theo đường dẫn cung cấp, đọc từng dòng dữ liệu,
 *          phân tích và lưu vào cấu trúc `User`, sau đó in ra thông tin. Bộ nhớ
 *          cấp phát động sẽ được giải phóng ngay sau khi sử dụng.
 * @param   filename: Đường dẫn đến file CSV cần đọc.
 */
Node *readCSV(const char *filename, Node *head, int choice);

#endif