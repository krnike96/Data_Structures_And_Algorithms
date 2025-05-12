#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct PriorityQueue
{
    int *heap;
    int size;
    int capacity;
} PriorityQueue;

PriorityQueue *initializePriorityQueue(int capacity)
{
    if (capacity <= 0)
    {
        printf("Error: Capacity must be positive.\n");
        return NULL;
    }

    PriorityQueue *pq = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    if (!pq)
    {
        printf("Memory allocation failed for PriorityQueue structure.\n");
        return NULL;
    }

    pq->heap = (int *)malloc(sizeof(int) * capacity);
    if (!pq->heap)
    {
        printf("Memory allocation failed for heap array.\n");
        free(pq);
        return NULL;
    }

    pq->capacity = capacity;
    pq->size = 0;
    return pq;
}

int parent(int index) { return (index - 1) / 2; }
int leftChild(int index) { return 2 * index + 1; }
int rightChild(int index) { return 2 * index + 2; }

bool isFull(PriorityQueue *pq)
{
    if (!pq)
    {
        printf("Error: PriorityQueue is NULL.\n");
        return false;
    }
    return pq->size == pq->capacity;
}

bool isEmpty(PriorityQueue *pq)
{
    if (!pq)
    {
        printf("Error: PriorityQueue is NULL.\n");
        return true;
    }
    return pq->size == 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(PriorityQueue *pq, int index)
{
    if (!pq || index < 0 || index >= pq->size)
        return;

    while (index > 0 && pq->heap[parent(index)] < pq->heap[index])
    {
        swap(&pq->heap[parent(index)], &pq->heap[index]);
        index = parent(index);
    }
}

void heapifyDown(PriorityQueue *pq, int index)
{
    if (!pq || index < 0 || index >= pq->size)
        return;

    int maxIndex = index;
    int left = leftChild(index);
    int right = rightChild(index);

    if (left < pq->size && pq->heap[left] > pq->heap[maxIndex])
        maxIndex = left;
    if (right < pq->size && pq->heap[right] > pq->heap[maxIndex])
        maxIndex = right;

    if (index != maxIndex)
    {
        swap(&pq->heap[index], &pq->heap[maxIndex]);
        heapifyDown(pq, maxIndex);
    }
}

bool enqueue(PriorityQueue *pq, int data)
{
    if (!pq)
    {
        printf("Error: PriorityQueue is NULL.\n");
        return false;
    }
    if (isFull(pq))
    {
        printf("Priority Queue is full. Cannot enqueue %d.\n", data);
        return false;
    }

    pq->heap[pq->size] = data;
    heapifyUp(pq, pq->size);
    pq->size++;
    return true;
}

bool dequeue(PriorityQueue *pq, int *result)
{
    if (!pq || !result)
    {
        printf("Error: Invalid arguments.\n");
        return false;
    }
    if (isEmpty(pq))
    {
        printf("Priority Queue is empty. Cannot dequeue.\n");
        return false;
    }

    *result = pq->heap[0];
    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;
    heapifyDown(pq, 0);
    return true;
}

bool peek(PriorityQueue *pq, int *result)
{
    if (!pq || !result)
    {
        printf("Error: Invalid arguments.\n");
        return false;
    }
    if (isEmpty(pq))
    {
        printf("Priority Queue is empty. Cannot peek.\n");
        return false;
    }

    *result = pq->heap[0];
    return true;
}

void display(PriorityQueue *pq)
{
    if (!pq)
    {
        printf("Error: PriorityQueue is NULL.\n");
        return;
    }
    if (isEmpty(pq))
    {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("Priority Queue (Array Form): ");
    for (int i = 0; i < pq->size; i++)
    {
        printf("%d ", pq->heap[i]);
    }
    printf("\n");

    printf("Priority Queue (Tree Form):\n");
    // Simple tree display (level order)
    for (int i = 0; i < pq->size;)
    {
        int levelSize = 1;
        while (i < pq->size && levelSize > 0)
        {
            for (int j = 0; j < levelSize && i < pq->size; j++)
            {
                printf("%d ", pq->heap[i++]);
            }
            printf("\n");
            levelSize *= 2;
        }
    }
}

void destroyPriorityQueue(PriorityQueue *pq)
{
    if (!pq)
    {
        printf("Error: PriorityQueue is already NULL.\n");
        return;
    }
    free(pq->heap);
    free(pq);
}

int main()
{
    int capacity, choice, data;
    printf("Enter the capacity of the Priority Queue: ");
    scanf("%d", &capacity);

    PriorityQueue *pq = initializePriorityQueue(capacity);
    if (!pq)
    {
        printf("Failed to initialize Priority Queue.\n");
        return 1;
    }

    while (true)
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Peek");
        printf("\n4. Check if Full");
        printf("\n5. Check if Empty");
        printf("\n6. Display");
        printf("\n7. Exit");
        printf("\nEnter your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            if (enqueue(pq, data))
            {
                printf("Enqueued %d successfully.\n", data);
            }
            display(pq);
            break;
        case 2:
            if (dequeue(pq, &data))
            {
                printf("Dequeued element: %d\n", data);
            }
            display(pq);
            break;
        case 3:
            if (peek(pq, &data))
            {
                printf("Element at top: %d\n", data);
            }
            break;
        case 4:
            printf(isFull(pq) ? "Priority Queue is full.\n" : "Priority Queue is not full.\n");
            break;
        case 5:
            printf(isEmpty(pq) ? "Priority Queue is empty.\n" : "Priority Queue is not empty.\n");
            break;
        case 6:
            display(pq);
            break;
        case 7:
            destroyPriorityQueue(pq);
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}