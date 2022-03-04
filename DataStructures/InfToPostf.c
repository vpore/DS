#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define max 50
typedef struct IP{
    char list[max];
    int j;
    char stack[max];
    int top;
}ip;

ip t;

void push(char val){
    if(t.top<=max){
        t.top++;
        t.stack[t.top]=val;
    }
    else{printf("Stack Overflow!\n");}
}

char pop(){
    if(t.top!=-1){
        t.top--;
        return t.stack[t.top+1];
    }
    else{printf("Stack Underflow!\n");}
}

int opnPrec(char val){
    t.list[t.j]=pop();
    t.j++;
    push(val);
}

int Prec(char val){
    if(val=='^'){return 3;}
    else if(val=='*' || val=='/' || val=='%'){return 2;}
    else if(val=='+' || val=='-'){return 1;}
    else if(val=='('){return Prec(t.stack[t.top-1]);}
    else{printf("ERROR!\n"); exit(1);}
}

void InFPostFExp(char exp[], char list[]){
    int i=0;
    char val=exp[i];
    while(val!='\0'){
        if(isdigit(val) || isalpha(val)){
            list[t.j]=val;
            t.j++;
        }
        else if(val=='('){
            push(val);
        }
        else if(val==')'){
            while(t.stack[t.top]!='('){
                list[t.j]=pop();
                t.j++;
            }
            if(t.stack[t.top]=='('){t.top--;}
        }
        else if(val=='+' || val=='-' || val=='*' || val=='/' || val=='%' || val=='^'){
            if(t.top==-1){push(val);}
            else{
                switch(val){
                    case '+': opnPrec(val);
                              break;
                    case '-': opnPrec(val);
                              break;
                    case '*': if(Prec(val)<=Prec(t.stack[t.top])){
                                    opnPrec(val);
                                }
                                else{
                                    push(val);
                                }
                                break;
                    case '/': if(Prec(val)<=Prec(t.stack[t.top])){
                                    opnPrec(val);
                                }
                                else{
                                    push(val);
                                }
                                break;
                    case '%': if(Prec(val)<=Prec(t.stack[t.top])){
                                    opnPrec(val);
                                }
                                else{
                                    push(val);
                                }
                                break;
                    case '^': push(val);
                              break;
                    default:  printf("ERROR!\n");
                }
            }
            
        }
        else{
            printf("Invalid Infix Expression!\n");
        }

        i++;
        val=exp[i];
    }
    while(t.top!=-1){
        list[t.j]=pop();
        t.j++;
    }
}

void main(){
    t.top=-1;
    t.j=0;
    char exp1[max];
    printf("Enter an Infix Expression\n");
    scanf("%s", &exp1);
    InFPostFExp(exp1, t.list);
    printf("Postfix Expression : %s", t.list);
}