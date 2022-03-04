#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<conio.h>

typedef struct Polynomial{
    int coeff;
    int exp;
    struct Polynomial *next;
}node;

node *p1head, *p2head, *p3head;

node *insert(node*, int, int);
node *add(node*, node*);
node *append(node*, int, int);
void display(node*);

void main(){

    int a, b, i, n;
    p1head=p2head=NULL;
    printf("Polynomial-1:\n");
    printf("Enter the number of terms:\n");
    scanf("%d", &n);
    printf("Enter the Polynomial:\n");
    for(i=1; i<=n; i++){
        printf("Enter the Coefficient & its Exponent:\n");
        scanf("%d%d", &a, &b);
        p1head=insert(p1head, a, b);
    }

    printf("Polynomial-2:\n");
    printf("Enter the number of terms:\n");
    scanf("%d", &n);
    printf("Enter the Polynomial:\n");
    for(i=1; i<=n; i++){
        printf("Enter the Coefficient & its Exponent:\n");
        scanf("%d%d", &a, &b);
        p2head=insert(p2head, a, b);
    }
    
    p3head=add(p1head, p2head);

    printf("Polynomial-1:\n");
    display(p1head);
    printf("\n");
    
    printf("Polynomial-2:\n");
    display(p2head);
    printf("\n");

    printf("The Sum = ");
    display(p3head);
    printf("\n");
}

node *insert(node *head, int a, int b){

    node *newnode=(node *)malloc(sizeof(node));
    newnode->coeff=a;
    newnode->exp=b;

    if(head==NULL){newnode->next=NULL; return newnode;} //To enter the FIRST NODE

    else{
        node *prev, *curr;
        prev=curr=head;
        while(curr!=NULL && curr->exp>b){
            prev=curr;
            curr=curr->next;
        }
        if(curr==NULL){prev->next=newnode; newnode->next=NULL;} //Inserting AFTER the FIRST NODE
        else if(curr==head){newnode->next=curr; return newnode;} //Inserting BEFORE the FIRST NODE
        else{ //Inserting in the MIDDLE
            newnode->next=curr;
            prev->next=newnode;
        }
        return head;
    }
}

node *add(node *p1, node *p2){
    node *ans=NULL;
    while(p1!=NULL && p2!=NULL){
        if(p1->exp > p2->exp){
            ans=append(ans, p1->coeff, p1->exp);
            p1=p1->next;
        }
        else if(p2->exp > p1->exp){
            ans=append(ans, p2->coeff, p2->exp);
            p2=p2->next;
        }
        else{
            ans=append(ans, p1->coeff+p2->coeff, p1->exp);
            p1=p1->next;
            p2=p2->next;
        }
    }
    while(p1!=NULL){ans=append(ans, p1->coeff, p1->exp);  p1=p1->next;}
    while(p2!=NULL){ans=append(ans, p2->coeff, p1->exp);  p2=p2->next;}
    return ans;
}

node *append(node *head, int a, int b){

    node *newnode=(node*)malloc(sizeof(node));
    newnode->coeff=a;
    newnode->exp=b;
    
    if(head==NULL){
        newnode->next=NULL;
        return newnode;
    }

    node *trav=head;
    while(trav->next!=NULL)
        trav=trav->next;
    trav->next=newnode;
    newnode->next=NULL;
    return head;

}

void display(node *head){
    if(head==NULL){printf("Underflow!\n"); return;}
    node *temp=head;
    while(temp!=NULL){
        printf(" %dx^%d ", temp->coeff, temp->exp);
        if(temp->next!=NULL){printf("+");}
        temp=temp->next;
    }
}