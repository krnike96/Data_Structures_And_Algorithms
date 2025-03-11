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
// void updateFirst(node **);
// void updateLast(node **);
// void updatePos(node **,int);
// void sort(node **);
// void search(node **);
void display(node **head){
    if(*head == NULL){
        printf("\nDLL is Empty!");
        return;
    }
    node * temp = *head;
    while(temp != NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL");
    printf("\nNo. of Nodes : %d",nCount);
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
            default:
                printf("\nError 400 - Bad Behaviour");
                return 0;
        }
    }
    return 0;
}