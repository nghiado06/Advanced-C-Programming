#include <stdio.h>

int linearSearch(int arr[], int n, int cmp)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == cmp)
        {
            return (i + 1);
        }
    }
    return -1;
}

int main()
{

    int arr[] = {1, 3, 5, 6, 2, 8, 4};
    int x = 3;
    printf("%d", linearSearch(arr, 7, x));
}