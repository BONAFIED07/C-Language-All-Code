//sorting 
#include<stdio.h>
void print(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("%4d", arr[i]);
    }
}
void swap(int *a,int *b){
    int temp=*a;
        *a=*b;
        *b=temp;
}
void selectionsort(int *arr,int n){
    int j;
    for(int i=0;i<n-1;i++){
        int min=i;
       for(int j=i+1;j<n;j++){
        if(arr[j]<arr[min]){
            min=j;
        }
       }
        if(min!=i){
        
            swap(&arr[min],&arr[j]);//most imp. line
        }
    }

}
void merge(int*A,int mid,int s,int e){
    int i=s;
    int k=s;
    int j=mid+1;
    int C[e-s+1];
    while(i<=mid&&j<=e){
        while(A[i]<A[j]){
            C[k]=A[i];
             k++;i++;
          }
         while(A[i]>A[j]){
             C[k]=A[j];
             k++;j++;
            }
        while(i<=mid){
           C[k]=A[i];
           k++;i++;
            }
        while(j<=e){
           C[k]=A[j];
           k++;j++;
            }
    for(int k=s;k<=e;k++){
        A[k]=C[k];
      }
    }
}

void mergesort(int *A,int s,int e){
  int mid=s+((e-s)/2);
      //base case
      if(s>=e){
        return;
      }
      mergesort(A,s,mid);
      mergesort(A,mid+1,e);
      merge(A,mid,s,e);

 }
 int partition(int *A,int lb,int ub){
    int s=lb;
    int e=ub;
    int pivot=A[lb];
    while(e>s){
        if(pivot>=A[s]){
            s++;
        }
         if(pivot<A[e]){
            s--;
        }
       if(e>s){
        swap(&A[s],&A[e]);
       }
    }
       swap(&A[lb],&A[e]);
    
    return e;

 }
void quicksort(int *A,int lb,int ub){
  
    if(ub>lb){
        int loc=partition(A,lb,ub);
        quicksort(A, lb ,loc-1);
        quicksort(A, loc+1 ,ub);
    }
}


int main(){
    int n=7;
    int odd[]={7,4,10,8,16,3,1};
      
    printf("sorted array by selection sort");
    
     selectionsort(odd,7);
      print(odd,7);
     printf("\n");
    //   printf("sorted array by merge sort");
    //   mergesort(odd,0,n-1);
      
      printf("sorted array by quick sort");
      quicksort(odd,0,n-1);
        print(odd,7);

    return 0;

}