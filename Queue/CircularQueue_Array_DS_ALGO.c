#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int front, rear;
    int *arr;
    int capacity;
    int count;    // Moved count inside structure
} Queue;

Queue *initializer(int capacity)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL)
    {
        printf("Memory allocation failed for queue.\n");
        return NULL;
    }
    
    q->arr = (int *)malloc(sizeof(int) * capacity);
    if (q->arr == NULL)
    {
        printf("Memory allocation failed for queue array.\n");
        free(q);  // Free previously allocated memory to prevent leak
        return NULL;
    }
    
    q->front = q->rear = -1;
    q->capacity = capacity;
    q->count = 0;
    return q;
}

int isFull(Queue *q)
{
    return (q->count == q->capacity);
}

int isEmpty(Queue *q)
{
    return (q->count == 0);
}

void enQueue(Queue *q, int data)
{
    if (q == NULL)
    {
        printf("\nQueue doesn't exist.");
        return;
    }
    
    if (isFull(q))
    {
        printf("\nCan't enQueue. Queue is Full.");
        return;
    }
    
    // Update rear (with wraparound)
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = data;
    q->count++;
    
    // If this is the first element
    if (q->count == 1)
        q->front = q->rear;
}

int deQueue(Queue *q)
{
    if (q == NULL)
    {
        printf("\nQueue doesn't exist.");
        return -1;
    }
    
    if (isEmpty(q))
    {
        printf("\nCan't DeQueue. Queue is Empty!");
        return -1;
    }
    
    int dequeued = q->arr[q->front];
    
    // Decrement count and update front
    q->count--;
    
    if (q->count == 0)
    {
        // Reset pointers when queue becomes empty
        q->front = q->rear = -1;
    }
    else
    {
        // Move front (with wraparound)
        q->front = (q->front + 1) % q->capacity;
    }
    
    return dequeued;
}

int peekFront(Queue *q)
{
    if (q == NULL || isEmpty(q))
    {
        printf("\nQueue is Empty or doesn't exist!");
        return -1;
    }
    
    return q->arr[q->front];
}

int peekRear(Queue *q)
{
    if (q == NULL || isEmpty(q))
    {
        printf("\nQueue is Empty or doesn't exist!");
        return -1;
    }
    
    return q->arr[q->rear];
}

void display(Queue *q)
{
    if (q == NULL || isEmpty(q))
    {
        printf("\nQueue is Empty or doesn't exist!");
        return;
    }
    
    printf("\nQueue elements: ");
    int i, index;
    for (i = 0; i < q->count; i++)
    {
        index = (q->front + i) % q->capacity;
        printf("%d ", q->arr[index]);
    }
    printf("\nNumber of Elements: %d", q->count);
    printf("\nFront index: %d, Rear index: %d", q->front, q->rear);
}

void destroyer(Queue *q)
{
    if (q == NULL)
        return;
        
    if (q->arr != NULL)
        free(q->arr);
    free(q);
    printf("\nThe Queue has been destroyed!");
}

int main()
{
    int capacity, data, choice;
    printf("Enter the Size of Queue: ");
    scanf("%d", &capacity);
    
    if (capacity <= 0)
    {
        printf("Invalid capacity. Please enter a positive number.\n");
        return 1;
    }
    
    Queue *q = initializer(capacity);
    if (q == NULL)
    {
        printf("Failed to initialize queue. Exiting...\n");
        return 1;
    }
    
    while (1)
    {
        printf("\n\n=== Circular Queue Operations ===");
        printf("\n1. EnQueue");
        printf("\n2. DeQueue");
        printf("\n3. Check if Full");
        printf("\n4. Check if Empty");
        printf("\n5. Peek Front");
        printf("\n6. Peek Rear");
        printf("\n7. Display Queue");
        printf("\n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
        case 0:
            destroyer(q);
            printf("\nExiting...");
            return 0;
            
        case 1:
            printf("\nEnter the Value to add: ");
            scanf("%d", &data);
            enQueue(q, data);
            display(q);
            break;
            
        case 2:
            data = deQueue(q);
            if (data != -1)
                printf("\nDequeued Element: %d", data);
            if (!isEmpty(q))
                display(q);
            break;
            
        case 3:
            if (isFull(q))
                printf("\nThe Queue is Full.");
            else
                printf("\nThe Queue is not Full. %d out of %d slots used.", q->count, q->capacity);
            break;
            
        case 4:
            if (isEmpty(q))
                printf("\nThe Queue is Empty.");
            else
                printf("\nThe Queue is not Empty. Contains %d elements.", q->count);
            break;
            
        case 5:
            data = peekFront(q);
            if (data != -1)
                printf("\nFront Element: %d", data);
            break;
            
        case 6:
            data = peekRear(q);
            if (data != -1)
                printf("\nRear Element: %d", data);
            break;
            
        case 7:
            display(q);
            break;
            
        default:
            printf("\nInvalid choice! Please try again.");
            break;
        }
    }
}