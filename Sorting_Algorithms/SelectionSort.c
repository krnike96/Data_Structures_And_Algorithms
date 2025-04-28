#include "stdio.h"
#include "stdlib.h"
void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (*(arr + j) < *(arr + min))
            {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
    printf("Sorted Array : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
}
int main()
{
    int n;
    printf("Enter the size of Array : ");
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    if (!arr)
        return 0;
    printf("Enter the Array elements : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (arr + i));
    }
    selectionSort(arr, n);
    free(arr);
    return 0;
}