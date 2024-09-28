#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void print(int *a,int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);  
    }
    printf("\n");
}

void merge(int *a,int *l,int left,int *r,int right){

    int i,j,k;
    i=0;j=0;k=0;

    while(i<left && j<right){
        if(l[i]<=r[j]) a[k++]=l[i++];
        else a[k++]=r[j++];
    }
    while(i<left) a[k++]=l[i++];
    while(j<right) a[k++]=r[j++];
}

void mergesort(int *a ,int n){
    if(n<2) return;                 //size 1 pe return
    int mid,*l,*r;          
    mid=n/2;

    l=(int *)malloc(mid*sizeof(int));           //declaring size of array with pointer using malloc
    r=(int *)malloc((n-mid)*sizeof(int));

    for(int i=0;i<mid;i++) l[i]=a[i];           //aadha aadha value distribute
    for(int i=mid;i<n;i++) r[i-mid]=a[i];

    mergesort(l,mid);                           //appling merge sort on both left and right array till 1 element left in their subarray
    mergesort(r,n-mid);
    merge(a,l,mid,r,n-mid);                     //merging both array 

    free(l);
    free(r);

    print(a,n);
}

int main(){

    int num_ele;
    scanf("%d",&num_ele);
    
    int a[num_ele];
    for(int i=0;i<num_ele;i++){
        scanf("%d",&a[i]);
    }

    mergesort(a,num_ele);
    print(a,num_ele);
}