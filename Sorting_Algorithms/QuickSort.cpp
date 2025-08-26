#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int hoarePartition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];       //first element is pivot
    int i = low - 1;
    int j = high + 1;

    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot); //finding element on left that should be on right
        do
        {
            j--;
        } while (arr[j] > pivot); //finding element on right that should be on left

        if (i >= j)
            return j;             //if both pointers met

        swap(arr[i], arr[j]);
    }
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = hoarePartition(arr, low, high);
        quickSort(arr, low, pivot);         //pivot included on left
        quickSort(arr, pivot + 1, high);
    }
}

void printArr(vector<int> &arr)
{
    if (!arr.empty())
    {
        for (auto e : arr)
        {
            cout << e << " ";
        }
    }
}

int main()
{
    size_t size;
    cout << "Enter the size of Array : ";
    cin >> size;

    vector<int> arr(size);
    cout << "Enter the Array Elements : ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, size - 1);
    printArr(arr);

    return 0;
}