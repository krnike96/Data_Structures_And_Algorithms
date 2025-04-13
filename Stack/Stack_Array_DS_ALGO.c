//Renamed the file from Stack_Array to Stack_Array_DS_ALGO
#include "stdio.h"
#include "stdlib.h"
int count = 0;
typedef struct stackArray
{
    int *arr; //Nuked the unnecessary int data
    int top;
} stack;

int isfull(stack *s, int size)
{
    return (s->top == size - 1) ? 1 : 0;
}
int isempty(stack *s)
{
    return (s->top == -1) ? 1 : 0;
}
int push(stack *s, int size, int data)
{
    if (isfull(s, size))
        return -9999999;
    else
    {
        count++;
        return s->arr[++s->top] = data;
    }
}
int pop(stack *s)
{
    if (isempty(s))
        return -9999999;
    else
    {
        count--;
        return s->arr[s->top--];
    }
}
int peek(stack *s)
{
    if (isempty(s))
        return -9999999;
    else
        return s->arr[s->top];
}

void display(stack *s)
{
    if (isempty(s))
    {
        printf("\nThe Stack is Empty!");
        return;
    }
    printf("\nThe Stack is : ");
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\nNo. of Elements : %d", count);
}

int main()
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->top = -1;
    printf("\nEnter the size of Stack : ");
    int size;
    scanf("%d", &size);
    if (size < 1)
    {
        printf("\nInvalid Size!");
        return 0;
    }
    s->arr = (int *)malloc(sizeof(int) * size);
    int choice, data;
    printf("\nStack using Array");
    while (1)
    {
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Peek");
        printf("\n4.Check Fullness");
        printf("\n5.Check Emptiness");
        printf("\n6.Display");
        printf("\n0.Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the data to be pushed : ");
            scanf("%d", &data);
            data = push(s, size, data);
            if (data == -9999999)
                printf("\nCan't Push. The Stack is Full!");
            else
                printf("\nThe Pushed Element is : %d", data);
            break;
        case 2:
            data = pop(s);
            if (data == -9999999)
                printf("\nCan't Pop. The Stack is Empty!");
            else
                printf("\nThe Popped Element is : %d", data);
            break;
        case 3:
            data = peek(s);
            if (data == -9999999)
                printf("\nCan't Peek. The Stack is Empty!");
            else
                printf("\nThe Element at the Top is : %d", data);
            break;
        case 4:
            if (isfull(s, size))
                printf("\nThe Stack is Full.");
            else
                printf("The Stack is not Full.");
            break;
        case 5:
            if (isempty(s))
                printf("\nThe Stack is Empty!");
            else
                printf("\nThe Stack is not Empty!");
            break;
        case 6:
            display(s);
            break;
        case 0:
            printf("\nExiting...");
            free(s->arr);
            s->arr = NULL;
            free(s);
            s = NULL;
            return 0;
        default:
            printf("\nError 400 : Bad Behaviour");
            break;
        }
    }
    return 0;
}