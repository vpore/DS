#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include<stdlib.h>

typedef struct PrioQ{
    int data;
    int prio;
    struct PrioQ *next;
}node;

node *rear=NULL;

node *insert(node*);
node *delete(node*);
void display(node*);

//***Maximum Priority Queue***
void main(){
    int choice;
    do{
        printf("Enter your choice:\n1. Insert\t2. Delete\t3. Display\t4. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1: rear=insert(rear); break;
            case 2: rear=delete(rear); break;
            case 3: display(rear); break;
            case 4: exit(1);
            default: printf("Enter appropriate choice!\n");
        }
    }while(choice!=4);
}

node *insert(node *rear){
    int val, priority;
    printf("Enter data:\n");
    scanf("%d", &val);
    printf("Enter its Priority:\n");
    scanf("%d", &priority);
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->prio=priority;
    if(rear==NULL){
        rear=newnode;
        rear->next=NULL;
    }
    else{
        newnode->next=rear;
        rear=newnode;
    }
    return rear;
}

node *delete(node *rear){
    node *temp1, *temp2;
    node *max;
    temp1=temp2=max=rear;
    if(rear==NULL){printf("Underflow!\n"); return NULL;}
    else if(rear->next==NULL){
        printf("Deleted Element: %d\tPriority: %d\n", temp1->data, temp1->prio);
        free(rear); 
        rear=NULL;
        return rear;
    }
    else{
        while(temp2!=NULL){
            if(temp2->prio >= max->prio){max=temp2;}
            temp2=temp2->next;
        }
        temp1=rear;
        if(temp1==max){rear=max->next;}
        else{
            while(temp1->next!=max){
                temp1=temp1->next;
            }
            if(max->next==NULL){temp1->next=NULL;}
            else{temp1->next=max->next;}
        }
        printf("Deleted Element: %d\tPriority: %d\n", max->data, max->prio);
        free(max);
        return rear;
    }
}

void display(node *temp){
    if(temp==NULL){printf("UNDERFLOW!\n"); return;}
    while(temp!=NULL){
        printf("%d\t", temp->data);
        temp=temp->next;
    }
    printf("\n");
}