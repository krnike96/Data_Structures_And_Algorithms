#include "stdio.h"
#include "stdlib.h"

void swap(int *arr, int i, int j)
{
    int temp = *(arr + i);
    *(arr + i) = *(arr + j);
    *(arr + j) = temp;
}
void bubbleSort(int *arr, size_t n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr, j, j + 1);
            }
        }
    }
}
void printArray(int *arr, size_t n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
}
int main()
{
    size_t n;
    printf("Enter the size of Array : ");
    scanf("%zu", &n);
    if (n <= 0)
        return 1;
    int *arr = (int *)malloc(sizeof(int) * n);
    if (!arr)
        return 1;
    printf("Enter the Array elements : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (arr + i));
    }
    bubbleSort(arr, n);
    printf("Sorted Array : ");
    printArray(arr, n);
    free(arr);
    return 0;
}