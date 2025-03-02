#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char stack[30],inFix[30],postFix[30];
char reverseInFix[30];
char *reverseInFixPointer=reverseInFix;
char symbol;
int top=-1;

bool isFull(){
    if(top==24){
        return true;
    }
    else{
        return false;
    }
}

bool isEmpty(){
    if(top==-1){
        return true;
    }
    else {
        return false;
    }
}

void push(char smb){
    if(!isFull()){
            stack[++top]=smb;
    }
    else{
        printf("\nstack is full");
    }
}

char pop(){
    char data;
    if(!isEmpty()){
            data=stack[top--];
            printf("\npopped %c out of the stack",data);
        return data;
    }
    else{
        printf("\nstack is empty");
        return '\0';
    }
}

void display(){
    for(int i=top;i>=0;i--){
        printf("\n%c",stack[i]);
    }
}

bool isOperator(char symbol){
    switch(symbol){
    case '+':
    case '-':
    case '/':
    case '*':
    case ')':
    case '(':
        return true;
        break;
    default:
        return false;
        break;
    }
}

int precedence(char symbol){
    switch (symbol)
            {
        case ')':
    case '(':
        return 1;
        break;
    case '^':
        return 2;
        break;
    case '*':
    case '/':
        return 3;
        break;
    case '+':
    case '-':
        return 4;
        break;
    default:
        return -1;
        break;
    }
}

void input(){
    printf("\nenter the infix notation to convert and evaluate");
    scanf("\n%[^\n]s",&inFix);
}

void reverseFunc(char nString[]){
    char temp;
    int length = strlen(nString);
    for(int i =0;i<length/2;i++){
        temp = nString[i];
        nString[i]=nString[length-i-1];
        nString[length-i-1]=temp;
    }
    for(int i=0;i<length;i++){
        if(nString[i]=='('){
            nString[i]=')';
           }
           else if(nString[i]==')'){
            nString[i]='(';
           }
    }
    }

void convertPostFix(char reverseInFix[],char postFix[]){
    int postFixCounter=0;
    push('(');
    reverseInFix[strlen(reverseInFix)] = ')';
    reverseInFix[strlen(reverseInFix) + 1] = '\0';
    for(int i=0;i<strlen(reverseInFix);i++){
        symbol=reverseInFix[i];
        if(!isOperator(symbol)){
            postFix[postFixCounter++]=symbol;
        }
        else{
            if(symbol=='('){
                push(symbol);
               }
                if(symbol==')'){
                    while(stack[top]!='('){
                            postFix[postFixCounter++]=pop();
                            postFixCounter++;
                          }
                          pop();
                }
               else{
                if(precedence(symbol)>precedence(stack[top])){
                    push(symbol);
                }
                else{
                        while(precedence(symbol)<=precedence(stack[top])){
                        postFix[postFixCounter++]=pop();
                }
                push(symbol);
                }
               }
        }
        }
        postFix[postFixCounter]='\0';
    }


int main(){
    char prefix[30];
input();
reverseFunc(inFix);
convertPostFix(inFix,postFix);
printf("\nthe postfix expression of given infix%s",postFix);
convertPostFix(inFix,reverseInFix);
reverseFunc(postFix);
printf("\nthe prefix expression of given infix%s",postFix);
}
