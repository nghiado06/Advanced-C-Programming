#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "..\Header\random.h"

void generateRandom(int *arr, int size)
{
    // Khởi tạo bộ sinh số ngẫu nhiên
    srand(time(NULL)); // Nếu không có dòng này thì mỗi lần gọi nó sẽ gọi là đúng bộ số cũ

    // Sinh ngẫu nhiên các phần tử cho mảng
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 10000 + 1;
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[7];
    generateRandom(arr, 7);
}