#include <iostream>
#include <vector>

using namespace std;

int linearSearch(vector<int> &arr, int key)
{
    if (arr.size() == 0)
        return -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (key == arr[i])
        {
            return i;
        }
    }
    return -1;
}

void printArr(vector<int> &arr)
{
    if (arr.size() == 0)
        return;

    for (auto n : arr)
    {
        cout << n << " ";
    }
}

int main()
{
    int n;
    cout << "Enter the size of Array : ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the Array Elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the key to Search : ";
    cin >> key;
    int a = linearSearch(arr, key);
    if (a != -1)
        cout << "Key Found at position : " << a + 1;
    else
        cout << "Key not Found!";
    return 0;
}