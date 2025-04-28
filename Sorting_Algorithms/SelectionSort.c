#include "stdio.h"
#include "stdlib.h"
void selectionSort(int *arr, size_t n)
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
        if(min == i) continue;
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}
void printArray(int * arr, size_t n){
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
    if(n <= 0) return 1;
    int *arr = (int *)malloc(sizeof(int) * n);
    if (!arr)
        return 1;
    printf("Enter the Array elements : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (arr + i));
    }
    selectionSort(arr, n);
    printf("Sorted Array : ");
    printArray(arr,n);
    free(arr);
    return 0;
}