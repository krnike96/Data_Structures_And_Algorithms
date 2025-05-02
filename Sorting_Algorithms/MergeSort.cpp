#include <iostream>
using namespace std;
void mergeSort(int * arr,size_t size){

}
void printArray(int * arr, size_t size){
    if(!size){
        cout << "Array is Empty."<<endl;
    }
    for(int i = 0; i < size; i++){
        cout << arr[i] <<" ";
    }
    return;
}
int main(){
    cout << "Enter the Size of Array : ";
    size_t size;
    cin >> size;
    int * arr = new int[size];
    cout<<"Enter the Array Elements : "<<endl;
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    mergeSort(arr,size);
    printArray(arr,size);
    delete[] arr;
    return 0;
}