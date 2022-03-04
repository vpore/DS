#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

void push(int top, int a[100]);
void pop(int top, int a[100]);
void peek(int top);
bool isEmpty(int top);
void display(int max, int a[100]);
void size(int top);

typedef struct Stack{
    int top;
    int max;
    int a[100];
}stack;

stack s;

void main()
{
    s.top=-1;

    int choice, ch;
    printf("**Enter the limit of array**\n");
    scanf("   %d", &s.max);
    ch=1;
    while(ch==1)
    {
        printf("Enter the option no.\n1.Push  2.Pop  3.Peek  4.Display  5.Size 6.Exit\n");
        scanf("   %d", &choice);
        switch(choice)
        {
            case 1: if(s.top!=s.max-1)
                    {
                        ++s.top;
                        push(s.top, s.a);
                    }
                    else
                        printf("STACK OVERFLOW!\n");
                    break;
            case 2: if(!isEmpty(s.top))
                    {
                         pop(s.top, s.a);
                         --s.top;
                    }
                    else
                        printf("STACK UNDERFLOW!\n");
                    break;
            case 3: peek(s.top);
                    break;
            case 4: display(s.max, s.a);
                    break;
            case 5: size(s.top);
                    break;
            case 6: exit(1);
            default: printf("Enter valid option!\n");
        }
        printf("Do you want to continue?\nEnter 1 for YES and 2 for NO\n");
        scanf("   %d", &ch);
    }
}

void push(int top, int a[100])
{
        printf("**Enter the element to be added**\n");
        scanf("   %d", &a[top]);
}

void pop(int top, int a[100])
{
        printf("**Popped element: %d**\n", a[top]);
        a[top]=0;
}

void peek(int top)
{
    printf("**The element at the top: %d**\n", s.a[top]);
}

bool isEmpty(int top)
{
    if(top==-1)
        return true;
    else
        return false;
}

void display(int max, int a[100])
{
    int i;
    printf("**Displaying elements**\n");
    for(i=0; i<=s.top; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void size(int top)
{
    printf("**Size of the stack: %d**\n", top+1);
}


