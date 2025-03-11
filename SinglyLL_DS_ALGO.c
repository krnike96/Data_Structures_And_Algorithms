#include "stdio.h"
#include "stdlib.h"

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;

node *createNode()
{
    return (node *)malloc(sizeof(node));
}

void insertFirst(int emt)
{
    node *temp = createNode();
    temp->data = emt;
    temp->next = head;
    head = temp;
}

void insertLast(int emt)
{
    if (head == NULL)
    {
        insertFirst(emt);
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node *nn = createNode();
    nn->data = emt;
    nn->next = NULL;
    temp->next = nn;
}

void insertPos(int pos, int emt)
{
    if (pos <= 0)
    {
        printf("\nNot a Valid Position.");
        return;
    }
    else if (pos == 1)
    {
        insertFirst(emt);
        return;
    }
    int nCount = 0;
    node *temp = head;
    while (temp != NULL)
    {
        nCount++;
        temp = temp->next;
    }
    if (pos > nCount)
    {
        printf("\nNot a Valid Position.");
        return;
    }
    temp = head;
    for (int i = 1; i < pos - 1; i++)
    {                      // pos - 1 means first head is skipped as temp is already at head and
        temp = temp->next; // i've to traverse till the position before the required position to
    } // link the new node with the previous node
    node *nn = createNode();
    nn->next = temp->next;
    nn->data = emt;
    temp->next = nn;
}

void deleteFirst()
{
    if (head == NULL)
    {
        printf("The List is Empty!\n");
        return;
    }
    node *temp = head;
    head = temp->next;
    free(temp);
    temp = NULL;
}

void deleteLast()
{
    if (head == NULL)
    {
        printf("The List is Empty!\n");
        return;
    }
    node *temp = head;
    if (temp->next == NULL)
    {
        deleteFirst();
        return;
    }
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

void deletePos(int pos)
{
    if (head == NULL)
    {
        printf("The List is Empty!\n");
        return;
    }
    if (pos <= 0)
    {
        printf("\nNot a Valid Position.");
        return;
    }
    if (pos == 1)
    {
        deleteFirst();
        return;
    }
    int nCount = 0;
    node *temp = head;
    while (temp != NULL)
    {
        nCount++;
        temp = temp->next;
    }
    if (pos > nCount)
    {
        printf("\nNot a Valid Position.");
        return;
    }
    if (pos == nCount)
    {
        deleteLast();
        return;
    }
    temp = head;
    for (int i = 1; i < pos - 1; i++)
    {                      // pos - 1 means first head is skipped as temp is already at head and
        temp = temp->next; // i've to traverse till the position before the required position to
    } // delete the node at this position
    node *temp1 = temp->next;
    temp->next = temp->next->next;
    free(temp1);
    temp1 = NULL;
}

void updateFirst(int emt)
{
    if (head == NULL)
    {
        printf("The List is Empty!\n");
        return;
    }
    head->data = emt;
}

void updateLast(int emt)
{
    if (head == NULL)
    {
        printf("The List is Empty!\n");
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->data = emt;
}

void updatePos(int pos, int emt)
{
    if (head == NULL)
    {
        printf("The List is Empty!\n");
        return;
    }
    if (pos <= 0)
    {
        printf("\nNot a Valid Position.");
        return;
    }
    if (pos == 1)
    {
        updateFirst(emt);
        return;
    }

    node *temp = head;
    int currentPos = 1; // Start counting from the first node

    while (temp != NULL)
    {
        if (currentPos == pos)
        {
            temp->data = emt; // Update the data at the target position
            return;
        }
        temp = temp->next;
        currentPos++;
    }

    // If the loop ends, the position is invalid
    printf("\nNot a Valid Position.");
}

void search(int key)
{
    if (head == NULL)
    {
        printf("The List is Empty!\n");
        return;
    }
    int nCount = 0;
    node *temp = head;
    while (temp->next != NULL)
    {
        nCount++;
        if (temp->data == key)
        {
            printf("The Key Element Found at Position : %d", nCount);
            return;
        }
        temp = temp->next;
    }
    printf("Key Element not Found!");
    return;
}

void bubbleSort()
{
    if (head == NULL || head->next == NULL)
    {
        printf("The List is Empty or Single Element!\n");
        return;
    }
    node *temp;
    node *end = NULL;
    int swap;
    do
    {
        swap = 0;
        temp = head;
        while (temp->next != end)
        { // running the loop till it reaches the end of the list
            if (temp->data > temp->next->data)
            {
                temp->data ^= temp->next->data ^= temp->data ^= temp->next->data;
                swap = 1;
            }
            temp = temp->next;
        }
        end = temp; // pointing the end to one step backwards as the largest element is at the end
                    // so no need to check that element
    } while (swap);
}
void display()
{
    if (head == NULL)
    {
        printf("The List is Empty!\n");
        return;
    }
    else
    {
        int nCount = 0;
        printf("\nThe List is : ");
        node *temp = head;
        while (temp != NULL)
        {
            nCount++;
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
        printf("No. of Elements : %d\n", nCount);
    }
}

int main()
{
    int choice, emt, pos;
    while (1)
    {
        printf("\nSingly LL");
        printf("\n1.Insert at First");
        printf("\n2.Insert at Last");
        printf("\n3.Insert at Specific Position");
        printf("\n4.Delete at First");
        printf("\n5.Delete at Last");
        printf("\n6.Delete at Specific Position");
        printf("\n7.Update at First");
        printf("\n8.Update at Last");
        printf("\n9.Update at Specific Position");
        printf("\n10.Sort(Elemental)");
        printf("\n11.Search(Linear)");
        printf("\n12.Display List");
        printf("\n0.Exit");
        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the Element : ");
            scanf("%d", &emt);
            insertFirst(emt);
            display();
            break;
        case 2:
            printf("Enter the Element : ");
            scanf("%d", &emt);
            insertLast(emt);
            display();
            break;
        case 3:
            printf("Enter the Position : ");
            scanf("%d", &pos);
            printf("Enter the Element : ");
            scanf("%d", &emt);
            insertPos(pos, emt);
            display();
            break;
        case 4:
            deleteFirst();
            display();
            break;
        case 5:
            deleteLast();
            display();
            break;
        case 6:
            printf("Enter the Position : ");
            scanf("%d", &pos);
            deletePos(pos);
            display();
            break;
        case 7:
            printf("Enter the Element : ");
            scanf("%d", &emt);
            updateFirst(emt);
            display();
            break;
        case 8:
            printf("Enter the Element : ");
            scanf("%d", &emt);
            updateLast(emt);
            display();
            break;
        case 9:
            printf("Enter the Position : ");
            scanf("%d", &pos);
            printf("Enter the Element : ");
            scanf("%d", &emt);
            updatePos(pos, emt);
            display();
            break;
        case 10:
            bubbleSort();
            display();
            break;
        case 11:
            printf("Enter the Key Element : ");
            scanf("%d", &emt);
            search(emt);
            break;
        case 12:
            display();
            break;
        case 0:
            printf("Exiting...");
            return 0;
        default:
            printf("Invalid Choice!");
            break;
        }
    }
    return 0;
}