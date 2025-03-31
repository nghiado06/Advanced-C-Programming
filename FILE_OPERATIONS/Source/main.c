#include "../Header/binary_tree.h"
#include "../Header/file_operations.h"

#define DATA_PATH "Data/DataBase.csv"

int main()
{
    Node *head = NULL;
    int phoneNumber;
    char userName[100];

    int choice;
    printf("Please choose sort way!\n");
    printf("1. Sort by phone number\n2. Sort by name\n");
    scanf("%d", &choice);

    printf("======PROCESSING======\n");
    Sleep(2000);

    head = readCSV(DATA_PATH, head, choice);

    print_list(head);
    CenterPoint *root = centerPoint(head);

    if (choice == 1)
    {
        printf("Enter the phone number: ");
        scanf("%d", &phoneNumber);
        root = binary_NumberSearch(root, phoneNumber);
    }
    else
    {
        printf("Enter the user name: ");
        scanf("%s", userName);
        root = binary_NameSearch(root, userName);
    }

    printf("PROCESSING...\n");
    Sleep(3000);

    if (root)
    {
        printf("=====================\n");
        printf("Found user:\n");
        printf("Name: %s\n", root->name);
        printf("Age: %d\n", root->age);
        printf("Address: %s\n", root->addr);
        printf("Phone Number: %d\n", root->number);
    }
    else
    {
        printf("Do Not Found!\n");
    }

    free_tree(root);

    return 0;
}
