#include <stdio.h>

#define NO_FOUND -1

int binarySearch(int *arr, int l, int r, int x)
{
    if (r >= l)
    {
        int mid = (r + l) / 2;

        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] > x)
        {
            return binarySearch(arr, l, mid - 1, x);
        }
        else
        {
            return binarySearch(arr, mid + 1, r, x);
        }
    }
    return NO_FOUND;
}

int main()
{
    int arr[] = {1, 3, 4, 5, 7, 8, 9};
    int x = 8;
    int res = binarySearch(arr, 0, 7, x);
    printf("%d", res);
}