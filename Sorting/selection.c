#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void print(int *a,int num){
	for(int i=0;i<num;i++){
		printf("%d ",a[i]);
	}
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

	for(int i=0;i<num-1;i++){
		for(int j=i+1;j<num;j++){
			if(a[i]>a[j]){
				swap(&a[i],&a[j]);
			}
		}
	}

	print(a,num);
}