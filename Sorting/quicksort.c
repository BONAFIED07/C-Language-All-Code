#include<stdio.h>
#include<string.h>

int max;

void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void print(int *a){
    for(int i=0;i<max;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int partition(int *a,int start,int end){
    int pivot=a[end];
    int pindex=start;
    for(int i=start;i<end;i++){
        if(a[i]<=pivot){
            swap(&a[i],&a[pindex]);    //if you are passing chat or int type write &. For array you dont have to it accesss the first elemet of array
            pindex++;
        }
    }
    swap(&a[end],&a[pindex]);  //swapping elements which are less than pivor with elements which are greater than that
    print(a);
    return pindex;     // returning pindex for future use
}

void quicksort(int *a,int start,int end){
    if(start<end){
        int pindex=partition(a,start,end); //dividing segments
        quicksort(a,start,pindex-1);       //dealing with segment
        quicksort(a,pindex+1,end);
    }
}

int main(){
    scanf("%d",&max);
    int a[max];

    for(int i=0;i<max;i++){
        scanf("%d",&a[i]);
    }
    
    quicksort(a,0,max-1);  //pass max-1 since starting from 0
    
}