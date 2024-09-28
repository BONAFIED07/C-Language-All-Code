#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(int *a,int *b){
	int val=*a;
	*a=*b;
	*b=val;
}

int partition(int *a,int start,int end){
	int pivot = a[end];
	int pindex= start;

	for(int i=start;i<end;i++){
		if(a[i]<=pivot){
			swap(&a[i],&a[pindex]);
			pindex=pindex+1;
		}
	}
	swap(&a[pindex],&a[end]);
	return pindex;

}

void print(int *a,int num){
	for(int i=0;i<num;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}


void quicksort(int *a,int start,int end){
	if(start<end){
		int pindex = partition(a,start,end);
		quicksort(a,start,pindex-1);
		quicksort(a,pindex+1,end);
	}
}

int main(){
	int num;
	scanf("%d",&num);
	int a[num];
	
	for(int i=0;i<num;i++){
		scanf("%d",&a[i]);
	}

	quicksort(a,0,num);
	print(a,num);
}
