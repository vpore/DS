#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define max 6
typedef struct QUEUE{
    int f;
    int r;
    int a[max];
}queue;

queue q;

bool isEmpty(int arr[]){
    if(q.f==-1){return true;}
    else{return false;}
}

bool isFull(int arr[]){
    if(q.r==max-1){return true;}
    else{return false;}
}

void enqueue(int val){
    if(!isFull(q.a)){
        if(q.r==-1){q.f=q.r=0; q.a[q.r]=val;}
        else{
            q.r++;
            q.a[q.r]=val;
        }
    }
    else{printf("QUEUE OVERFLOW!\n");}
}

int dequeue(){
        q.f++;
        return q.a[q.f-1];
}

int peek(){
    return q.a[q.f];
}

void display(int arr[]){
    int i;
    for(i=q.f; i<=q.r; i++){
        printf("%d ", arr[i]);
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
        case 4: display(q.a);
                break;
        case 5: exit(1);
        default: printf("ENTER APPROPRIATE NUMBER\n");
        }
    }
    while(choice!=5);
    
}