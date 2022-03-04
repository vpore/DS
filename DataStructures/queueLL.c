#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<conio.h>

typedef struct QUEUE{
    int data;
    struct QUEUE* next;
}node;

node* front=NULL;
node* rear=NULL;

node* createQueue(node*);
node* enqueue(node*);
node* dequeue(node*);
void peek(node*);
void display(node*);
void size(node*);

void main(){
    rear=createQueue(rear);
    int choice;
    do{
        printf("Enter your choice:\n1. Enqueue    2. Dequeue    3. Peek    4. Size   5. Display   6. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                rear=enqueue(rear); break;
            
            case 2: 
                front=dequeue(front); break;

            case 3:
                peek(front); break;

            case 4: 
                size(rear); break;

            case 5:
                display(rear); printf("\n"); break;

            case 6: exit(1);

            default: printf("Enter proper choice!\n");
        }
    }while(choice!=6);
}

node* createQueue(node* rear){
    int val, ch;
    node *newnode;
    printf("To create a QUEUE\n");
    printf("Enter data:\n");
    scanf("%d", &val);
    do{
        newnode=(node*)malloc(sizeof(node));
        newnode->data=val;
        if(front==NULL){front=newnode; rear=newnode; newnode->next=NULL;}
        else{
            newnode->next=rear;
            rear=newnode;
        }
        printf("Enter -1 to end\n");
        printf("Enter data:\n");
        scanf("%d", &val);
    }while(val!=-1);
    return rear;
}

node* enqueue(node* rear){
    int val;
    node* newnode;
    printf("Enter data:\n");
    scanf("%d", &val);
    newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    if(front==NULL){front=newnode; rear=newnode; newnode->next=NULL;}
    else{
        newnode->next=rear;
        rear=newnode;
    }
    return rear;
}

node* dequeue(node* front){
    node* temp;
    if(front==NULL){printf("UNDERFLOW!\n"); return front;}
    else if(rear->next==NULL){
        temp=rear;
        front=NULL;
        rear=NULL;
        printf("Element Removed: %d\n", temp->data);
        free(temp);
        return front;
    }
    else{
        temp=rear;
        while(temp->next!=front){
            temp=temp->next;
        }
        front=temp;
        printf("Element Removed: %d\n", temp->next->data);
        free(temp->next);
        front->next=NULL;
        return front;
    }
}

void peek(node* front){
    if(front==NULL){printf("UNDERFLOW!\n");}
    else{
        printf("Element at Front: %d\n", front->data);
    }
}

void size(node* rear){
    int c=0;
    node *temp;
    temp=rear;
    while(temp!=NULL){
        ++c;
        temp=temp->next;
    }
    printf("Size of Queue: %d\n", c);
}

void display(node *rear){
    if(rear==NULL){}
    else{display(rear->next); printf("%d\t", rear->data);}
}