#include<stdio.h>

int main(){
	int a[5]={2,0,1,4,3};
	int n=5;
	while(n--){
		for(int i=0;i<5;i++){
			if(i<4){
				if(a[i]>a[i+1]){
					int val=a[i];
					a[i]=a[i+1];
					a[i+1]=val;
				}
			}
		}
	}
	for(int i=0;i<5;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}

