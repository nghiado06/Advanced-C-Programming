#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        for (int j = 0; j <= n - i - 2; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {3, 5, 6, 1, 4, 9, 2};
    bubbleSort(arr, 7);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", arr[i]);
    }
}