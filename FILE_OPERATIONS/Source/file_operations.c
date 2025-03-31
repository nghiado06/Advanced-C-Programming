/*******************************************************************************
 * @file    file_operations.c
 * @brief   Đọc dữ liệu từ file CSV chứa thông tin người dùng và chuyển đổi dữ liệu.
 * @details File này mở file CSV, đọc từng dòng thông tin và phân tích dữ liệu,
 *          sau đó chuyển đổi dữ liệu và đưa dữ liệu vào hàm xử lý.
 * @version 1.0
 * @date    30-03-2025
 * @author  Duc Nghia
 ******************************************************************************/
#include "../Header/binary_tree.h"
#include "../Header/file_operations.h"

/**
 * @brief   Chuyển đổi dữ liệu đầu vào sang dữ liệu xử lý
 * @details Chuyển đổi các dữ liệu khác nhau sang cùng 1 kiểu dữ liệu để sắp xếp
 * @param   userName    Tên người dùng
 * @param   phoneNumber Số điện thoại người dùng
 * @return  DataBase
 */
DataBase dataBase(char *userName, int phoneNumber, char *address, int age)
{
    int name = 0;

    /*Xử lý tên người dùng*/
    for (int i = 0; userName[i] != '\0'; i++)
    {
        name += (int)userName[i];
    }

    /*Lưu dữ liệu người dùng*/
    DataBase user;
    user.userName = (char *)malloc(sizeof(userName));
    strcpy(user.userName, userName);
    user.name = name;
    user.number = phoneNumber;
    user.age = age;
    user.addr = (char *)malloc(sizeof(address));
    strcpy(user.addr, address);
    return user;
    /*Trả về dữ liệu người dùng*/
    return user;
}

/**
 * @brief   Giải phóng bộ nhớ cho các trường của cấu trúc User.
 * @details Hàm này giải phóng bộ nhớ đã cấp phát động cho các member của cấu trúc `User`.
 * @param   user: Con trỏ đến cấu trúc `User` cần giải phóng.
 */
void free_user(User *user)
{
    free(user->name);
    free(user->addr);
}

/**
 * @brief   Đọc dữ liệu từ file CSV và in thông tin người dùng.
 * @details Hàm này mở file CSV theo đường dẫn cung cấp, đọc từng dòng dữ liệu,
 *          phân tích và lưu vào cấu trúc `User`, sau đó in ra thông tin. Bộ nhớ
 *          cấp phát động sẽ được giải phóng ngay sau khi sử dụng.
 * @param   filename: Đường dẫn đến file CSV cần đọc.
 */
Node *readCSV(const char *filename, Node *head, int choice)
{

    FILE *file = fopen(filename, "r");

    /* Kiểm tra xem file có mở thành công không */
    if (file == NULL)
    {
        printf("Cannot open file!\n");
    }

    char line[100]; /**< Bộ đệm để lưu từng dòng từ file CSV */

    /* Bỏ qua dòng tiêu đề */
    fgets(line, sizeof(line), file); // "Name, Age, Address, Phone Number" // "Name" '\0'

    /* In tiêu đề bảng dữ liệu */
    printf("%-20s %-5s\t  %-20s\t  %-15s\n", "Name", "Age", "Address", "Phone Number");

    printf("\n");

    /* Đọc từng dòng dữ liệu từ file CSV */
    while (fgets(line, sizeof(line), file)) //  ,40, 789 Pine St, 555-8765
    {
        User user; /**< Biến lưu thông tin người dùng tạm thời */

        /* Tách tên từ dòng hiện tại */
        char *token = strtok(line, ",");
        user.name = (char *)malloc(strlen(token) + 1); /**< Cấp phát bộ nhớ cho tên */
        strcpy(user.name, token);

        /* Tách tuổi */
        token = strtok(NULL, ","); // "40" -> '4' - 0x30 = 4, '0' - 0x30 = 0 , '4' -> (int)'4' = 52
        user.age = atoi(token);

        /* Tách địa chỉ */
        token = strtok(NULL, ",");
        user.addr = (char *)malloc(strlen(token) + 1); /**< Cấp phát bộ nhớ cho địa chỉ */
        strcpy(user.addr, token);

        /* Tách số điện thoại */
        token = strtok(NULL, ",");
        user.phone = atoi(token);

        /* In thông tin người dùng */
        printf("%-20s %-5d\t %-20s\t %-15d\n", user.name, user.age, user.addr, user.phone);

        /*Lưu dữ liệu người dùng*/

        /*Sắp xếp theo số điện thoại*/
        if (choice == 1)
            add_node_numberSort(&head, dataBase(user.name, user.phone, user.addr, user.age));
        /*Sắp xếp theo tên*/
        else
            add_node_nameSort(&head, dataBase(user.name, user.phone, user.addr, user.age));

        /* Giải phóng bộ nhớ của các trường trong cấu trúc User */
        free_user(&user);
    }

    fclose(file); /**< Đóng file sau khi đọc xong */

    return head; /*trả về head*/
}
