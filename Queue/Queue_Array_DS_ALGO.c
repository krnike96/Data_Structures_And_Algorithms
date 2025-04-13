#include "stdio.h"
#include "stdlib.h"
typedef struct Queue
{
    int data;
    int *arr;
    int front, rear;
} queue;
int capacity;
int count = 0;
queue *initializer(int capacity)
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->arr = (int *)malloc(sizeof(int) * capacity); // allocating size for array
    q->front = -1;                                  //-1 denotes the queue is empty initially
    q->rear = -1;                                   //-1 denotes the queue is empty initially
    return q;
}

int isfull(queue *q)
{
    return (q->rear == capacity - 1) ? 1 : 0;
}

int isEmpty(queue *q)
{
    return (q->front == -1 || q->front > q->rear) ? 1 : 0;
}

void enQueue(queue *q, int data)
{
    if (isfull(q))
    {
        printf("Queue Is Full. Can't enQueue!\n");
        return;
    }
    if (q->front == -1 && q->rear == -1)
    {
        q->front = 0;
        q->rear = 0;
        q->arr[q->rear] = data;
        count++;
    }
    else
    {
        q->arr[++q->rear] = data;
        count++;
    }
}
int deQueue(queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty. Can't deQueue!");
        return -999999;
    }
    int val = q->arr[q->front];
    q->arr[q->front++] = 0;
    count--;
    if(q->front > q->rear){ //fixed
        q->front = -1;
        q->rear = -1;
    }
    return val;
}

void peekFront(queue *q)
{
    if (isEmpty(q))
    {
        printf("No Front Element. Queue is Empty!");
        return;
    }
    printf("Front Element : %d", q->arr[q->front]);
}
void peekRear(queue *q)
{
    if (isEmpty(q))
    {
        printf("No Rear Element. Queue is Empty!");
        return;
    }
    printf("Front Element : %d", q->arr[q->rear]);
}
void display(queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Queue : ");
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\nCount : %d", count);
}

int main()
{
    int ch, data;
    printf("Enter the size of Queue : ");
    scanf("%d", &capacity);
    queue *q = initializer(capacity);
    while (1)
    {
        printf("\n1.Enqueue");
        printf("\n2.DeQueue");
        printf("\n3.Fullness");
        printf("\n4.Emptiness");
        printf("\n5.Peek Front");
        printf("\n6.Peek Rear");
        printf("\n7.Display");
        printf("\n0.Exit");
        printf("\nEnter your Choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the Element : ");
            scanf("%d", &data);
            enQueue(q, data);
            display(q);
            break;
        case 2:
            data = deQueue(q);
            if (data != -999999)
            {
                printf("The deQueued Element is : %d", data);
            }
            break;
        case 3:
            if (isfull(q))
                printf("The Queue is Full.");
            else
                printf("The Queue is not Full.");
            break;
        case 4:
            if (isEmpty(q))
                printf("The Queue is Empty.");
            else
                printf("The Queue is not Empty.");
            break;
        case 5:
            peekFront(q);
            break;
        case 6:
            peekRear(q);
            break;
        case 7:
            display(q);
            break;
        case 0:
            printf("\nExiting...");
            free(q);
            return 0;
            break;
        default:
            printf("Invalid Choice!");
            break;
        }
    }
    return 0;
}