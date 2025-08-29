#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &arr, int key)
{
    int left = 0;
    int right = arr.size() - 1;
    int index = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2; // Prevents Some Bugs that i never Encountered

        if (arr[mid] == key)
        {
            index = mid;
            right = mid - 1; // Ensuriung it returns first occurance
        }
        else if (arr[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return index;
}

void printArr(vector<int> &arr)
{
    int size = arr.size();
    if (!size)
    {
        cout << "Array is Empty." << endl;
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return;
}

void sortSmallArr(vector<int> &arr, int left, int right)
{ // using Insertion Sort for Smaller Arrays
    int size = arr.size();
    if (!size)
        return;
    for (int i = left + 1; i <= right; i++)
    {
        int key = arr[i];
        int j = i;
        while (j > 0 && arr[j - 1] > key)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}

int partition(vector<int> &arr, int left, int right)
{ // using Hoare Partitioning for Partition and Pivot Finding
    int pivot = arr[left];
    int i = left - 1;
    int j = right + 1;

    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }
}

void sortLargeArr(vector<int> &arr, int left, int right)
{ // Using Quick Sort for Larger Arrays
    if (left < right)
    {
        if (right - left + 1 <= 10)
        {
            sortSmallArr(arr, left, right); // Using Insertion Sort to avoid quick sort's recursion overhead for smaller subArrays
            return;
        }
        int pivot = partition(arr, left, right);
        sortLargeArr(arr, left, pivot);
        sortLargeArr(arr, pivot + 1, right);
    }
}

int main()
{
    int size;
    cout << "Enter the size of Array : ";
    cin >> size;

    vector<int> arr(size);
    cout << "Enter the Array Elements : ";

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the Key/Value to Search : ";
    cin >> key;

    if (size <= 10)
    {
        cout << "Using Insertion Sort for Sorting in Acsending Order(size <= 10)." << endl;
        sortSmallArr(arr, 0, size - 1);
    }
    else
    {
        cout << "Using Quick Sort for Sorting in Acsending Order(size > 10)." << endl;
        sortLargeArr(arr, 0, size - 1);
    }

    printArr(arr);
    int index = binarySearch(arr, key);
    if (-1 != index)
    {
        cout << "Key Found at Position : " << index + 1 << " in Sorted Array";
    }
    else
    {
        cout << "Key not Found!";
    }

    return 0;
}