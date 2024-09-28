#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void print(int *a,int n ){
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
        printf("\n");
}

void swap(int *a,int *b){
    int val=*a;
    *a=*b;
    *b=val;
}

int main(){
    int num;
    scanf("%d",&num);
    int a[num];
    for(int i=0;i<num;i++){
        scanf("%d",&a[i]);
    }
    
    while(num--){
        for(int i =0;i<num;i++){
            if(i<num-1){
            if(a[i]<a[i+1]){
                swap(&a[i],&a[i+1]);
            }
        }
        }
    }

    print(a,num);
    
}