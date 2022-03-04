#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<conio.h>

typedef struct CLL{
    int data;
    struct CLL* next;
}node;

node* head=NULL;

node* createLL(node*);
node* insAtBeg(node*, int);
node* insAtEnd(node*, int);
node* insAtLoc(node*, int);
node* insAfterNode(node*, int);
node* delAtBeg(node*);
node* delAtEnd(node*);
node* delAtLoc(node*);
node* delAfterNode(node*);
node* sort(node*);
node* search(node*);
void display(node*);

void main(){
    head=createLL(head);
    int choice, n, ch, val;
    do{
        printf("Enter Choice:\n1. Insert    2. Delete    3. Sort    4. Search    5. Display   6. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data:\n");
            scanf("%d", &val);
            printf("Enter Choice:\n1. Insert at Beginning    2. Insert at End   3. Insert at Position   4. Insert after Node\n");
            scanf("%d", &n);
            switch(n){
                case 1: head=insAtBeg(head, val); break;
                case 2: head=insAtEnd(head, val); break;
                case 3: head=insAtLoc(head, val); break;
                case 4: head=insAfterNode(head, val); break;
                default: printf("Enter Proper choice!\n");
            }
            break;

        case 2: 
            printf("Enter Choice:\n1. Delete at Beginning   2. Delete at End   3. Delete at Position   4. Delete after Node\n");
            scanf("%d", &ch);
            switch(ch){
                case 1: head=delAtBeg(head); break;
                case 2: head=delAtEnd(head); break;
                case 3: head=delAtLoc(head); break;
                case 4: head=delAfterNode(head); break;
                default: printf("Enter proper choice\n");
            }
            break;

        case 3: head=sort(head); break;

        case 4: head=search(head); break;

        case 5: display(head); break;
        
        case 6: exit(1);
        
        default: printf("Enter proper choice!\n");

        }
    }while(choice!=7);
    
}

node* createLL(node* head){
    printf("To create a List\n");
    node *newNode, *temp;
    int num;
    printf("Enter data:\n");
    scanf("%d", &num);
    do{
        newNode=(node*)malloc(sizeof(node));
        newNode->data=num;
        if(head==NULL){newNode->next=newNode; head=newNode;}
        else{
            temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->next=head;
        }
        printf("Enter -1 to end\n");
        printf("Enter data:\n");
        scanf("%d", &num);
    }while(num!=-1);

    return head;
}

node* insAtBeg(node* head, int val){
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    if(head==NULL){
        head=newnode;
        newnode->next=head;
        return head;
    }
    else{
        node *temp;
        temp=head;
        while(temp->next!=head)
            temp=temp->next;
        temp->next=newnode;
        newnode->next=head;
        head=newnode;
    }
    
}

node* insAtEnd(node* head, int val){
    node *newnode, *temp;
    newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    if(head==NULL){newnode->next=head; head=newnode; return head;}
    else{
        temp=head;
        while(temp->next!=head)
            temp=temp->next;
        temp->next=newnode;
        newnode->next=head;
        return head;
    }
}

node* insAtLoc(node* head, int val){
    int pos;
    node *newnode, *temp;
    temp=head;
    printf("Enter Position:\n");
    scanf("%d", &pos);
    newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    if(pos==1){newnode->next=head; head=newnode; return head;}
    else{
        for(int i=1; i<pos-1; i++){
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        return head;
    }
}

node* insAfterNode(node* head, int val){
    int n;
    printf("Enter node data after which you want to insert:\n");
    scanf("%d", &n);
    node *newnode, *temp;
    newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    temp=head;
    while(temp->data!=n)
        temp=temp->next;
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
}

node* delAtBeg(node* head){
    node* temp;
    if(head==NULL){printf("UNDERFLOW!\n"); return head;}
    else if(head->next==head){
        temp=head;
        head=NULL;
        free(temp);
        return head;
    }
    else{
        temp=head;
        while(temp->next!=head)
            temp=temp->next;
        temp->next=head->next;
        free(head);
        head=temp->next;
        return head;
    }
}

node* delAtEnd(node* head){
    if(head==NULL){printf("UNDERFLOW!\n"); return head;}
    else{
        node *temp1, *temp2;
        temp1=temp2=head;
        if(head==NULL){printf("UNDERFLOW!");}
        else if(head->next==head){head=NULL; free(temp1); return head;}
        else{
            while(temp1->next!=head){    /*temp1->next->next!=NULL o/s while: temp2=temp1->next*/
                temp2=temp1;
                temp1=temp1->next;
            }
            temp2->next=head;
            free(temp1);
        }
    }
    return head;
}

node* delAtLoc(node* head){
    if(head==NULL){printf("UNDERFLOW!\n"); return head;}
    else{
        int pos;
        printf("Enter the position:\n");
        scanf("%d", &pos);
        node *temp1, *temp2;
        temp1=temp2=head;
        for(int i=1; i<pos; i++){
            temp2=temp1;
            temp1=temp1->next;
        }
        temp2->next=temp1->next;
        free(temp1);
        return head;
    }
}

node* delAfterNode(node *head){
    if(head==NULL){printf("UNDERFLOW!\n");}
    else{
        int n;
        printf("Enter node data after which you want to delete:\n");
        scanf("%d", &n);
        node *temp1, *temp2;
        temp1=temp2=head;
        while(temp2->data!=n){
            temp2=temp1;
            temp1=temp1->next;
        }
        temp2->next=temp1->next;
        free(temp1);
    }
    return head;
}

node* sort(node* head){
    node *temp1, *temp2;
    int t;
    temp1=temp2=head;
    while(temp1->next!=head){
        temp2=temp1->next;
        while(temp2!=head){
            if(temp2->data < temp1->data){
                t=temp2->data;
                temp2->data=temp1->data;
                temp1->data=t;
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    return head;
}

node* search(node* head){
    if(head==NULL){printf("The list is EMPTY!\n"); return head;}
    else{
        int num;
        printf("Enter the number:\n");
        scanf("%d", &num);
        node *temp;
        temp=head->next;
        if(head->data==num){printf("Element Found\n");}
        while(temp!=head){
            if(temp->data==num){printf("Element Found\n"); break;}
            temp=temp->next;
        }
        if(temp==head){printf("Element not found\n");}
    }
    return head;
}

void display(node* head){
    if(head==NULL){printf("Empty List!\n"); return;}
    node* temp;
    temp=head->next;
    printf("%d\n", head->data);
    while(temp!=head){
        printf("%d\n", temp->data);
        temp=temp->next;
    }
}