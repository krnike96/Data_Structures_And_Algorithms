#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lomutoPartition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];      //Right most element is the Pivot
    int i = low - 1;            //Index of the smaller element

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)    //check if the current element is smaller than or equal to the pivot
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], pivot);    //Place pivot in correct position
    return i + 1;               //Return partition index
}

int hoarePartition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low]; // first element is pivot
    int i = low - 1;
    int j = high + 1;

    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot); // finding element on left that should be on right
        do
        {
            j--;
        } while (arr[j] > pivot); // finding element on right that should be on left

        if (i >= j)
            return j; // if both pointers met

        swap(arr[i], arr[j]);
    }
}

void quickSortHoare(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = hoarePartition(arr, low, high);
        quickSortHoare(arr, low, pivot); // pivot included on left
        quickSortHoare(arr, pivot + 1, high);
    }
}

void quickSortLomuto(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = lomutoPartition(arr, low, high);
        quickSortLomuto(arr, low, pivot - 1); // Not including Pivot in either parts
        quickSortLomuto(arr, pivot + 1, high);
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

    cout << "1.Use Lomuto Partition\n2.Use Hoare Partition\nEnter your Choice : ";
    int ch;
    cin >> ch;
    if (2 == ch)
        quickSortLomuto(arr, 0, size - 1);
    else
        quickSortHoare(arr, 0, size - 1);

    printArr(arr);

    return 0;
}