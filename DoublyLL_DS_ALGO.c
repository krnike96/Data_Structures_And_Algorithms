//Using Double Pointer
#include "stdio.h"
#include "stdlib.h"

typedef struct node{
    int data;
    struct node * next;
    struct node * prev;
}node;
int nCount = 0;
node * createNode(){
    return (node *)malloc(sizeof(node));
}

void insertFirst(node **head,int emt){
    node * nn = createNode();
    nn->data = emt;
    nn->next = *head;
    if(*head != NULL)  (*head)->prev = nn;
    *head = nn;
    nn->prev = NULL;
    nCount++;
}
void insertLast(node **head,int emt){
    node * nn = createNode();
    node * temp = *head;
    if(*head == NULL){
        insertFirst(head,emt);
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = nn;
    nn->prev = temp;
    nn->next = NULL;
    nn->data = emt;
    nCount++;
}
void insertPos(node **head,int pos,int emt){
    if(pos <= 0){
        printf("Invalid Position!");
        return;
    }
    if(pos == 1){
        insertFirst(head,emt);
        return;
    }
    if(pos > nCount){
        printf("Invalid Position!");
        return;
    }
    node * temp = *head;
    node * nn = createNode();
    for(int i = 1;i < pos - 1; i++){
        temp=temp->next;
    }
    nn->data = emt;
    nn->next = temp->next;
    temp->next->prev = nn;
    nn->prev = temp;
    temp->next = nn;
    nCount++;
}
void deleteFirst(node **head){
    if(*head == NULL){
        return;
    }
    node * temp = *head;
    if(temp->next == NULL){
        free(*head);
        *head = NULL;
    }else{
    temp->next->prev = NULL;
    *head = temp->next;
    free(temp);
    temp = NULL;
    }
    nCount--;
}
void deleteLast(node **head){
    if(*head == NULL){
        return;
    }
    if((*head)->next == NULL){
        deleteFirst(head);
        return;
    }
    node * temp = *head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    nCount--;
}
void deletePos(node **head,int pos){
    if(*head == NULL){
        return;
    }
    if(pos <= 0 || pos > nCount){
        printf("Invalid Position!");
        return;
    }
    if(pos == 1){
        deleteFirst(head);
        return;
    }
    if(pos == nCount){
        deleteLast(head);
        return;
    }
    node * temp = *head;
    for(int i = 1;i < pos - 1;i++){
        temp = temp->next;
    }
    node * temp1 = *head;
    temp1 = temp->next->next;
    free(temp->next);
    temp->next = temp1;
    temp1->prev = temp;
    nCount--;
}
void updateFirst(node **head,int emt){
    if(*head == NULL){
        return;
    }
    (*head)->data = emt;
}
void updateLast(node **head,int emt){
    if(*head == NULL){
        return;
    }
    node * temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->data = emt;
}
void updatePos(node **head,int pos,int emt){
    if(*head == NULL){
        return;
    }
    if (pos <= 0)
    {
        printf("\nNot a Valid Position.");
        return;
    }
    if (pos == 1)
    {
        updateFirst(head,emt);
        return;
    }
    int currPos = 2;
    node * temp = *head;
    while(temp != NULL){
        temp = temp->next;
        if(pos == currPos){
            temp->data = emt;
            return;
        }
        currPos++;
    }
    printf("Invalid Position!");
}
// void sort(node **);
// void search(node **);
void display(node **head){
    if(*head == NULL){
        printf("\nDLL is Empty!");
        return;
    }
    node * temp = *head;
    printf("#############################################\n\n");
    printf("The DLL is : NULL->");
    while(temp != NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL");
    printf("\nNodes Count : %d",nCount);
    printf("\n\n#############################################");
}
void displayRev(node **head){
    if(*head == NULL){
        printf("\nDLL is Empty!");
        return;
    }
    node * temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    printf("#############################################\n\n");
    printf("The DLL is : NULL");
    while(temp != NULL){
        printf("<-%d",temp->data);
        temp = temp->prev;
    }
    printf("<-NULL");
    printf("\nNodes Count : %d",nCount);
    printf("\n\n#############################################");
}

int main(){
    node * head = NULL;
    int choice,pos,emt;
    printf("\nDoublyLL");
    while(1){
        printf("\n1.Insert At First");
        printf("\n2.Insert At Last");
        printf("\n3.Insert At Specific Position");
        printf("\n4.Delete At First");
        printf("\n5.Delete At Last");
        printf("\n6.Delete At Specific Position");
        printf("\n7.Update At First");
        printf("\n8.Update At Last");
        printf("\n9.Update At Specific Position");
        printf("\n10.Sort(Elemental)");
        printf("\n11.Search");
        printf("\n12.Display");
        printf("\n13.Display in Reverse");
        printf("\n0.Exit");
        printf("\nEnter Your Choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the Element : ");
                scanf("%d",&emt);
                insertFirst(&head,emt);
                display(&head);
                break;
            case 2:
                printf("Enter the Element : ");
                scanf("%d",&emt);
                insertLast(&head,emt);
                display(&head);
                break;
            case 3:
                printf("Enter the Position : ");
                scanf("%d",&pos);
                printf("Enter the Element : ");
                scanf("%d",&emt);
                insertPos(&head,pos,emt);
                display(&head);
                break;
            case 4:
                deleteFirst(&head);
                display(&head);
                break;
            case 5:
                deleteLast(&head);
                display(&head);
                break;
            case 6:
                printf("Enter the Position : ");
                scanf("%d",&pos);
                deletePos(&head,pos);
                display(&head);
                break;
            case 7:
                printf("Enter the Element : ");
                scanf("%d",&emt);
                updateFirst(&head,emt);
                display(&head);
                break;
            case 8:
                printf("Enter the Element : ");
                scanf("%d",&emt);
                updateLast(&head,emt);
                display(&head);
                break;
            case 9:
                printf("Enter the Position : ");
                scanf("%d",&pos);
                printf("Enter the Element : ");
                scanf("%d",&emt);
                updatePos(&head,pos,emt);
                display(&head);
                break;
            case 12:
                display(&head);
                break;
            case 13:
                displayRev(&head);
                break;
            case 0:
                printf("Exiting...");
                return 0;
            default:
                printf("\nError Code : 404 - Not found!");
                break;
        }
    }
    return 0;
}