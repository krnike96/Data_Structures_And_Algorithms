#include <iostream>
using namespace std;
void insertionSort(int * arr,size_t size){
    
}
int main(){
    printf("Enter the Size of Array : ");
    size_t size;
    scanf("%zu",&size);
    int * arr = new int[size];
    for(int i = 0; i < size; i++){
        scanf("%d",&arr[i]);
    }
    insertionSort(arr,size);
    printArray(arr,size);
    delete[] arr;
    return 0;
}