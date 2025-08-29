#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftPart(n1), rightPart(n2);

    for (int i = 0; i < n1; i++)
    {
        leftPart[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        rightPart[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (leftPart[i] <= rightPart[j])
        {
            arr[k++] = leftPart[i++];
        }
        else
        {
            arr[k++] = rightPart[j++];
        }
    }

    while (i < n1)
    {
        arr[k++] = leftPart[i++];
    }

    while (j < n2)
    {
        arr[k++] = rightPart[j++];
    }
}

void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}
void printArray(vector<int> &arr)
{
    if (arr.size() <= 0)
        return;
    for (auto n : arr)
    {
        cout << n << " ";
    }
    cout << endl;
}
int main()
{
    cout << "Enter the Size of Array : ";
    size_t size;
    cin >> size;
    vector<int> arr(size);
    cout << "Enter the Array Elements : " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    mergeSort(arr, 0, size - 1);
    printArray(arr);
    return 0;
}