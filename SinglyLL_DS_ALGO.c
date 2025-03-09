#include "stdio.h"
#include "stdlib.h"

struct node{
    int data;
    struct node * next;
};

struct node * head = NULL;

struct node * createNode(){
    return (struct node *)malloc(sizeof(struct node));
}

void insertFirst(int emt){
    struct node * temp = createNode();
    temp->data = emt;
    temp->next = head;
    head = temp;
}

void insertLast(int emt){
    if(head == NULL){
        insertFirst(emt);
        return;
    }
    struct node * temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    struct node * nn = createNode();
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
    struct node * temp = head;
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
    struct node * nn = createNode();
    nn->next = temp->next;
    nn->data = emt;
    temp->next = nn;
    
}

void display(){
    int nCount = 0;
    if(head == NULL){
        printf("\nThe List is Empty!");
        return;
    }else{
        printf("\nThe List is : ");
        struct node * temp = head;
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
        printf("\n5.Delete at First");
        printf("\n6.Delete at Last");
        printf("\n7.Insert at Specific Position");
        printf("\n8.Update at First");
        printf("\n9.Update at Last");
        printf("\n10.Update at Specific Position");
        printf("\n11.Sort");
        printf("\n12.Search");
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