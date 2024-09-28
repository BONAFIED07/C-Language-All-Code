#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int top=-1;
int stack[MAX];

void push(int n){
    if(top==MAX-1){
        printf("OverFlow!!\n");
        return;
    }
    else{
    top=top+1;
    stack[top]=n;

    }
}

void pop(){
    if(top==-1){
        printf("UnderFlow!!\n");
        exit(0);
    }
    else{
        printf("%d\n",stack[top]);
        top=top-1;
    }
}

int main(){
    push(2);
    push(3);
    push(54);
    pop();
    pop();
    pop();
    pop();
    return 0;
}