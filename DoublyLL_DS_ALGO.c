#include "stdio.h"
#include "stdlib.h"

typedef struct node{
    int data;
    node * next;
    node * prev;
}node;

node * createNode(){
    return (node *)malloc(sizeof(node));
}

void insertFirst(node *);
void insertLast(node *);
void insertPos(node *,int,int);
void deleteFirst(node *);
void deleteLast(node *);
void deletePos(node *,int);
void updateFirst(node *);
void updateLast(node *);
void updatePos(node *,int);
void sort(node *);
void search(node *);
void display(node *);

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
        printf("\nEnter Your Choice");
        scanf("%d",&choice);
        switch(choice){
            default:
                printf("\nError 400 - Bad Behaviour");
                return 0;
        }
    }
    return 0;
}