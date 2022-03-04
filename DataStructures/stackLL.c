#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<conio.h>

typedef struct STACK{
    int data;
    struct STACK* next;
}node;

node* top=NULL;

node* createStack(node*);
node* push(node*);
node* pop(node*);
void peek(node*);
void display(node*);
void size(node*);

void main(){
    top=createStack(top);
    int choice;
    do{
        printf("Enter your choice:\n1. Push    2. Pop    3. Peek    4. Size   5. Display   6. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                top=push(top); break;

            case 2:
                top=pop(top); break;

            case 3:
                peek(top); break;

            case 4:
                size(top); break;

            case 5:
                display(top); break;

            case 6: exit(1);

            default: printf("Enter proper choice!\n");
        }
    }while(choice!=6);
}

node* createStack(node* top){
    int val, ch;
    node *newnode;
    printf("To create a STACK\n");
    printf("Enter data:\n");
    scanf("%d", &val);
    do{
        newnode=(node*)malloc(sizeof(node));
        newnode->data=val;
        if(top==NULL){top=newnode; newnode->next=NULL;}
        else{
            newnode->next=top;
            top=newnode;
        }
        printf("Enter -1 to end\n");
        printf("Enter data:\n");
        scanf("%d", &val);
    }while(val!=-1);
    return top;
}

node* push(node* top){
    int val;
    node* newnode;
    printf("Enter data:\n");
    scanf("%d", &val);
    newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    if(top==NULL){top=newnode; newnode->next=NULL;}
    else{
        newnode->next=top;
        top=newnode;
    }
    return top;
}

node* pop(node* top){
    node* temp;
    if(top==NULL){printf("UNDERFLOW!\n"); return top;}
    else if(top->next==NULL){
        temp=top;
        top=NULL;
        printf("Element Removed: %d\n", temp->data);
        free(temp);
        return top;
    }
    else{
        temp=top;
        top=temp->next;
        printf("Element Removed: %d\n", temp->data);
        free(temp);
        return top;
    }
}

void peek(node* top){
    if(top==NULL){printf("UNDERFLOW!\n");}
    else{
        printf("Element at Top: %d\n", top->data);
    }
}

void size(node* top){
    int c=0;
    node *temp;
    temp=top;
    while(temp!=NULL){
        ++c;
        temp=temp->next;
    }
    printf("Size of Stack: %d\n", c);
}

void display(node *top){
    node *temp;
    temp=top;
    printf("\n");
    while(temp!=NULL){
        printf("%d\n", temp->data);
        temp=temp->next;
    }
    printf("\n");
}
