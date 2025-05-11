#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "limits.h"

typedef struct PriorityQueue
{
    int *heap;
    int size, capacity;
} priorityQueue;

priorityQueue *initializer(int& capacity){
    priorityQueue * pq = (priorityQueue *)malloc(sizeof(priorityQueue));
    if(!pq) return NULL;
    pq->heap = (int *)malloc(sizeof(int) * capacity);
    if(!(pq->head)) return NULL;
    pq->capacity = capacity;
    pq->size = 0;
    return pq;
}
int parent(int index){
    return (index - 1)/2; //Valid for both 0 & 1 based indexing
}
int left(int index){
    return 2 * index + 1;
}
int right(int index){
    return 2 * index + 2;
}
bool isFull(priorityQueue *pq){
    if(pq->size == pq->capacity - 1){
        return true;
    }else{
        return false;
    }
}
bool isEmpty(priorityQueue *pq){
    if(pq->size == 0){
        return true;
    }else{
        return false;
    }
}
void heapifyUp(priorityQueue *pq, int index);
void heapifyDown(priorityQueue *pq, int index);
void enQueue(priorityQueue *pq, int &data);
void deQueue(priorityQueue *pq);
int peekTop(priorityQueue *pq);
void display(priorityQueue *pq);
void destroyer(priorityQueue *pq){
    if(!pq){
        printf("\nPriority Queue Doesn't Exist.");
        return;
    }
    free(pq->heap);
    free(pq);
    return;
}

int main()
{
    priorityQueue *pq = NULL;
    int capacity, choice, data;
    printf("Enter the capacity of the Priority Queue : ");
    scanf("%d", &capacity);
    pq = initializer(capacity);
    if (!pq)
        return 1;
    while (true)
    {
        printf("\n1.EnQueue");
        printf("\n2.DeQueue");
        printf("\n3.Peek Top");
        printf("\n4.Check Fullness");
        printf("\n5.Check Emptiness");
        printf("\n6.Display");
        printf("\n7.Exit");
        printf("\nEnter youu Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the data : ");
            scanf("%d", &data);
            enQueue(pq, data);
            display(pq);
            break;
        case 2:
            deQueue(pq);
            break;
        case 3:
            data = peekTop(pq);
            if (data == INT_MIN)
            {
                printf("\nData at Top of PQ : %d", data);
            }
            else
            {
                printf("\nPQ is Empty.");
            }
            break;
        case 4:
            isFull(pq);
            break;
        case 5:
            isEmpty(pq);
            break;
        case 6:
            display(pq);
            break;
        case 7:
            destroyer(pq);
            return 0;
        default:
            printf("\nInvalid");
        }
    }
    return 0;
}