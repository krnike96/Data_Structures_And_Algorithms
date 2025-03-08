#include "stdio.h"
#include "stdlib.h"
int * temp = NULL;
void insertFirst(int **arr,int *size,int emt){
    int newSize = *size + 1;
    temp = realloc(*arr,sizeof(int)*newSize);
    if(temp == NULL && newSize != 0){
        printf("Memory Allocation failed!\n");
        return ; 
    }
    *arr = temp;
    for(int i = newSize - 1; i>0;i--){
        (*arr)[i] = (*arr)[i-1];
    }
    (*arr)[0] = emt;
    
    *size = newSize;
}
void insertLast(int **arr,int *size, int emt){
    int newSize = *size + 1;
    temp = realloc(*arr,sizeof(int)*newSize);
    *arr = temp;
    (*arr)[newSize-1] = emt;
    *size = newSize;
}
void insertPos(int **arr,int *size,int pos ,int emt){
    if(*size == 0) printf("\nArray is Empty!");
    else{
    int newSize = *size + 1;
    if(temp == NULL && newSize != 0){
        printf("Memory Allocation failed!\n");
        return ; 
    }
    *arr = temp;
    for(int i = newSize - 1; i > pos; i--){
        (*arr)[i] = (*arr)[i-1];
    }
    (*arr)[pos - 1] = emt;
    *size = newSize;
    }
}
void deleteFirst(int **arr,int *size){
    if(*size == 0) printf("\nArray is Empty!");
    else{
    
    for(int i = 0; i< (*size);i++){
        (*arr)[i] = (*arr)[i + 1];
    }
    (*size) --;
    int newSize = *size;
    temp = realloc(*arr,sizeof(int)*newSize);
    if(temp == NULL && newSize !=0){
        printf("\nMemory Allocation Failed!");
        return;
    }
    *arr = temp;
    }
}
void deleteLast(int **arr,int *size){
    if(*size == 0) printf("\nArray is Empty!");
    else{
        (*size) --;
        int newSize = *size;
        temp = realloc(*arr,sizeof(int)*newSize);
        if(temp == NULL && newSize !=0){
            printf("\nMemory Allocation Failed!");
            return;
        }
        *arr = temp;
    }
}
void deletePos(int **arr,int *size,int pos){
    if(*size == 0) printf("\nArray is Empty!");
    else{
    
    for(int i = pos - 1; i < *size; i++){
        (*arr)[i] = (*arr)[i + 1];
    }
    (*size) --;
    int newSize = *size;
    temp = realloc(*arr,sizeof(int)*newSize);
    if(temp == NULL && newSize !=0){
        printf("\nMemory Allocation Failed!");
        return;
    }
    *arr = temp;
    }
}
void update(int **arr,int pos,int emt,int *size){
    if(*size == 0) printf("\nArray is Empty!");
    else if(pos >=1 && pos <= (*size))
    (*arr)[pos-1] = emt;
}
void bubbleSort(int **arr,int *size){
    if(*size == 0) printf("\nArray is Empty!");
    else{
        for(int i = 0; i < *size ; i++){
            for(int j = 0; j < *size - i - 1; j++){
                if((*arr)[j] > (*arr)[j + 1]){
                    (*arr)[j] ^= (*arr)[j + 1] ^= (*arr)[j] ^= (*arr)[j + 1]; //swap
                }
            }
        }
    }
}
void binarySearch(int *arr,int *size,int emt){
    if(*size == 0) printf("\nArray is Empty!");
    else{
    int l = 0;
    int r = *size - 1;
    while(l <= r){
        int m = l +(r - l)/2;
        if(arr[m] == emt){
            printf("In Sorted Array, Element is found at %d Position.",m + 1);
            return;
        }
        if(arr[m] < emt) l = m + 1;
        else r = m - 1;
    }
        printf("\nElement Not found!");
    }
}

void linearSearch(int * arr,int *size, int emt){
    if(*size == 0) printf("\nArray is Empty!");
    else {
        for(int i = 0; i < *size; i++){
            if(arr[i] == emt) {
            printf("In Unsorted Array, Element is found at %d Position.", i + 1);
            return;
             } 
        }
        printf("\nElement Not Found!");
    }
}
void display(int **arr,int *size){
    if(*size == 0) printf("\nArray is Empty!");
    else {
        printf("\nCurrent Array : ");
        for(int i = 0; i < (*size); i++){
            printf("%d ",(*arr)[i]);
        }
    }
    
}
int main(){
    int * arr = NULL;
    int size = 0;
    int choice;
    
    printf("\nArray\n");
    while(1)
    {
        printf("\n1.Insert at First\n");
        printf("2.Insert at Last\n");
        printf("3.Insert at Specific Position\n");
        printf("4.Delete at First\n");
        printf("5.Delete at Last\n");
        printf("6.Delete at Specific Position\n");
        printf("7.Update at specific Position\n");
        printf("8.Sort\n");
        printf("9.Search(Sorting Req.)\n");
        printf("10.Search\n");
        printf("11.Display Array\n");
        printf("0.Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: 
                printf("\nEnter the Element : ");
                int element;
                scanf("%d",&element);
                insertFirst(&arr,&size,element);
                display(&arr,&size);
                break;
            case 2:
                printf("\nEnter the Element : ");
                scanf("%d",&element);
                insertLast(&arr,&size,element);
                display(&arr,&size);
                break;
            case 3:
                printf("\nEnter the Position : ");
                int pos;
                scanf("%d",&pos);
                printf("\nEnter the Element : ");
                scanf("%d",&element);
                insertPos(&arr,&size,pos,element);
                display(&arr,&size);
                break;
            case 4:
                deleteFirst(&arr,&size);
                display(&arr,&size);
                break;
            case 5:
                deleteLast(&arr,&size);
                display(&arr,&size);
                break;
            case 6:
                printf("\nEnter the position : ");
                scanf("%d",&pos);
                deletePos(&arr,&size,pos);
                display(&arr,&size);
                break;
            case 7:
                printf("\nEnter the position : ");
                scanf("%d",&pos);
                printf("\nEnter the Element : ");
                scanf("%d",&element);
                update(&arr,pos,element,&size);
                display(&arr,&size);
                break;
            case 8:
                bubbleSort(&arr,&size);
                break;
            case 9:
                printf("\nEnter the Element : ");
                int emt = 0;
                scanf("%d",&emt);
                binarySearch(arr,&size,emt);
                break;
            case 10:
                printf("\nEnter the Element : ");
                scanf("%d",&emt);
                linearSearch(arr,&size,emt);
                break;
            case 11:
                display(&arr,&size);
                break;
            case 0:
                printf("Exiting...");
                free(arr);
                return 0;
            default: printf("\nInvalid Choice!\n");
                break;
        }
    }
    return 0;
}