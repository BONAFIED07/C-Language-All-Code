#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void print(int *a,int n){
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}

void insertionsort(int *a,int n){
	for(int i=1;i<n;i++){
		int val=a[i];
		int hole=i;
		while(hole>0 && a[hole-1]>val){
			a[hole]=a[hole-1];
			hole--;
		}
		a[hole]=val;
	}
}

int main(){
	int num;
	scanf("%d",&num);
	int a[num];
	for(int i=0;i<num;i++){
		scanf("%d",&a[i]);
	}

	insertionsort(a,num);
	print(a,num);
}