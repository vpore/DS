#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define max 6
typedef struct QUEUE{
    int a[max];
    int f,r;
}queue;

queue q;

void enqueue(int val){
    if(q.f==-1){q.f=q.r=0; q.a[q.r]=val;}
    else if(q.f==q.r+1 || (q.f==0 && q.r==max-1)){printf("STACK OVERFLOW!\n");}
    else if(q.r==max-1){q.r=0; q.a[q.r]=val;}
    else{q.r++; q.a[q.r]=val;}
}

int dequeue(){
    if(q.f==max-1){q.f=0; return q.a[max-1];}
    else if(q.f==q.r){int item=q.a[q.f]; q.f=q.r=-1; return item;}
    else{
        q.f++;
        return q.a[q.f-1];
    }
    
}

bool isEmpty(){
    if(q.f==-1){return true;}
    else{return false;}
}

int peek(){
    return q.a[q.f];
}

void display(){
    int i;
    if(q.f>q.r){
        for(i=q.f; i<max; i++){
            printf("%d ", q.a[i]);
        }
        for(i=0; i<=q.r; i++){
            printf("%d ", q.a[i]);
        }
    }
    else{
        for(i=q.f; i<=q.r; i++)
            printf("%d ", q.a[i]);
    }

    printf("\n");
}

void main(){
    q.f=-1;
    q.r=-1;
    int choice, value;
    do{
        printf("ENTER OPTION NUMBER \n1.Enqueue()\t2.Dequeue()\t3.Peek()\t4.Display()\t5.Exit\n");
        scanf("%d", &choice);
        switch(choice){
        case 1: printf("Enter element to be enqueued\n");
                scanf("%d", &value);
                enqueue(value);
                break;
        case 2: if(!isEmpty(q.a)){
                    printf("Element removed: %d\n", dequeue());
                }
                else{
                    printf("STACK UNDERFLOW!\n");
                }
                break;
        case 3: printf("Element at front end: %d\n", peek());
                break;
        case 4: display();
                break;
        case 5: exit(1);
        default: printf("ENTER APPROPRIATE NUMBER\n");
        }
    }
    while(choice!=5);

}