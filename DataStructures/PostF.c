#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>

#define max 50
typedef struct POST{
    int stack[max];
    int top;
}post;

post p;

void push(int val){
    p.top++;
    if(p.top<=max){
        p.stack[p.top]=val;
    }
    else{
        printf("Stack Overflow\n");
       exit(1);
    }
}

int pop(){
    if(p.top!=-1){
        p.top--;
        return p.stack[p.top+1];
    }
    else{
        printf("Stack Underflow!\n");
    }
}

int stackEvl(int op2, int op1, char opr){
    switch(opr){
        case '+': return op1+op2;
                    break;
        case '-': return op1-op2;
                    break;
        case '*': return op1*op2;
                    break;
        case '/': return op1/op2;
                    break;
        case '^': return pow(op1, op2);
                    break;
        default: printf("ERROR!\n");
    }
}

void PostFixEvl(char exp[]){
    int Answer;
    int opa, opb;
    int i=0;
    char val=exp[i];
    while(val!='\0'){
        if(isdigit(val)){
            push(val-'0');
        }
        else if(val=='+' || val=='-' || val=='/' || val=='*' || val=='^'){
            opb=pop();
            opa=pop();
            Answer=stackEvl(opb, opa, val);
            push(Answer);
        } 
        else{
            printf("Enter a POSTFIX expression ONLY!\n");
        }
        i++;
        val=exp[i];
    }

}

void main(){
    p.top=-1;
    char exp1[max];
    printf("Enter Postfix expression\n");
    scanf("%s", &exp1);
    PostFixEvl(exp1);
    printf("Answer = %d\n", p.stack[0]);
}