#include "stdio.h"
#include "stdlib.h"

typedef struct node{
    int data;
    struct node * next;
}node;

node * head = NULL;

node * createNode(){
    return (node *)malloc(sizeof(node));
}

void insertFirst(int emt){
    node * temp = createNode();
    temp->data = emt;
    temp->next = head;
    head = temp;
}

void insertLast(int emt){
    if(head == NULL){
        insertFirst(emt);
        return;
    }
    node * temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    node * nn = createNode();
    nn->data = emt;
    nn->next = NULL;
    temp->next = nn;
}

void insertPos(int pos,int emt){
    if(pos == 0){
        printf("\nNot a Valid Position.");
        return;
    }
    else if(pos == 1){
        insertFirst(emt);
        return;
    }
    int nCount = 0;
    node * temp = head;
    while(temp != NULL){
        nCount++;
        temp = temp->next;
    }
    if(pos > nCount){
        printf("\nNot a Valid Position.");
        return;
    }
    temp = head;
    for(int i = 0;i < pos - 2; i++){ // pos - 2 means first head is skipped as temp is already at head and
        temp = temp->next;           // i've to traverse till the position before the required position to
    }                                // link the new node with the previous node
    node * nn = createNode();
    nn->next = temp->next;
    nn->data = emt;
    temp->next = nn;
}

void deleteFirst(){
    if(head == NULL){
        printf("The List is Empty!\n");
        return;
    }
    node * temp = head;
    head = temp->next;
    free(temp);
    temp = NULL;
}

void deleteLast(){
    if(head == NULL){
        printf("The List is Empty!\n");
        return;
    }
    node * temp = head;
    if(temp->next == NULL){
        deleteFirst();
        return;
    }
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    
    free(temp->next);
    temp->next = NULL;
    
}

void deletePos(int pos){
    if(head == NULL){
        printf("The List is Empty!\n");
        return;
    }
    if(pos <= 0){
        printf("\nNot a Valid Position.");
        return;
    }
    if(pos == 1){
        deleteFirst();
        return;
    }
    int nCount = 0;
    node * temp = head;
    while(temp != NULL){
        nCount++;
        temp = temp->next;
    }
    if(pos > nCount){
        printf("\nNot a Valid Position.");
        return;
    }
    if(pos == nCount){
        deleteLast();
        return;
    }
    temp = head;
    for(int i = 0; i < pos - 2; i++){   // pos - 2 means first head is skipped as temp is already at head and
        temp=temp->next;                // i've to traverse till the position before the required position to
    }                                   // delete the node at this position
    node * temp1 = temp->next;
    temp->next = temp->next->next;
    free(temp1);
    temp1 = NULL;
}

void updateFirst(int emt){
    if(head == NULL){
        printf("The List is Empty!\n");
        return;
    }
    head->data = emt;
}

void updateLast(int emt){
    if(head == NULL){
        printf("The List is Empty!\n");
        return;
    }
    node * temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->data = emt;
}

void updatePos(int pos,int emt){
    if(head == NULL){
        printf("The List is Empty!\n");
        return;
    }
    if(pos <= 0){
        printf("\nNot a Valid Position.");
        return;
    }
    if(pos == 1){
        updateFirst(emt);
        return;
    }
    int nCount = 0;
    node * temp = head;
    while(temp != NULL){
        nCount++;
        temp = temp->next;
    }
    if(pos > nCount){
        printf("\nNot a Valid Position.");
        return;
    }
    if(pos == nCount){
        updateLast(emt);
        return;
    }
    temp = head;
    for(int i = 0; i < pos - 1; i++){   // pos - 2 means first head is skipped as temp is already at head and
        temp=temp->next;                // i've to traverse till the position before the required position to
    }                                   // delete the node at this position
    temp->data = emt;
    return;
}
void display(){
    int nCount = 0;
    if(head == NULL){
        printf("The List is Empty!\n");
        return;
    }else{
        printf("\nThe List is : ");
       node * temp = head;
    while(temp != NULL){
        nCount++;
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    printf("No. of Elements : %d\n",nCount);
    }
}

int main(){
    int choice,emt,pos;
    while(1){
        printf("\n1.Insert at First");
        printf("\n2.Insert at Last");
        printf("\n3.Insert at Specific Position");
        printf("\n4.Delete at First");
        printf("\n5.Delete at Last");
        printf("\n6.Delete at Specific Position");
        printf("\n7.Update at First");
        printf("\n8.Update at Last");
        printf("\n9.Update at Specific Position");
        printf("\n10.Sort");
        printf("\n11.Search");
        printf("\n0.Exit");
        printf("\nEnter Your Choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the Element : ");
                scanf("%d",&emt);
                insertFirst(emt);
                display();
                break;
            case 2:
                printf("Enter the Element : ");
                scanf("%d",&emt);
                insertLast(emt);
                display();
                break;
            case 3:
                printf("Enter the Position : ");
                scanf("%d",&pos);
                printf("Enter the Element : ");
                scanf("%d",&emt);
                insertPos(pos,emt);
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
                scanf("%d",&pos);
                deletePos(pos);
                display();
                break;
            case 7:
                printf("Enter the Element : ");
                scanf("%d",&emt);
                updateFirst(emt);
                display();
                break;
            case 8:
                printf("Enter the Element : ");
                scanf("%d",&emt);
                updateLast(emt);
                display();
                break;
            case 9: 
                printf("Enter the Position : ");
                scanf("%d",&pos);
                printf("Enter the Element : ");
                scanf("%d",&emt);
                updatePos(pos,emt);
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