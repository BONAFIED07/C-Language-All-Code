#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int stack[MAX];
int stackx[MAX];
int top=-1;
int first=-1;

void enqueue(int data){
    if(top==MAX){
        printf("Already Filled\n");
    }
    else{
        top=top+1;
        stackx[top]=data;
        
    }
}

void dequeue(){
    if(top==first){
        printf("Empty!!\n");
    }
    else{
        printf("%d\n",stackx[top]);
        top=top-1;
    }
}



int main(int argc, char const *argv[])
{
    enqueue(1);
    enqueue(4);
    enqueue(6);
    enqueue(42);
    enqueue(5);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    return 0;
}
