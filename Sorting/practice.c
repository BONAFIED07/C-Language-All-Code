#include<stdio.h>

void print(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%4d", arr[i]);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionsort(int *arr, int n) {
    for(int i = 0; i < n-1; i++) {
        int min = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        if(min != i) {
            swap(&arr[min], &arr[i]);
        }
    }
}

void merge(int *A, int mid, int s, int e) {
    int i = s;
    int k = s;
    int j = mid+1;
    int C[e-s+1];
    while(i <= mid && j <= e) {
        if(A[i] < A[j]) {
            C[k] = A[i];
            k++; i++;
        } else {
            C[k] = A[j];
            k++; j++;
        }
    }
    while(i <= mid) {
        C[k] = A[i];
        k++; i++;
    }
    while(j <= e) {
        C[k] = A[j];
        k++; j++;
    }
    for(int k = s; k <= e; k++) {
        A[k] = C[k];
    }
}

void mergesort(int *A, int s, int e) {
    if(s >= e) {
        return;
    }
    int mid = s + (e - s) / 2;
    mergesort(A, s, mid);
    mergesort(A, mid + 1, e);
    merge(A, mid, s, e);
}

int partition(int *A, int lb, int ub) {
    int pivot = A[lb];
    int start = lb;
    int end = ub;
    while(start < end) {
        while(A[start] <= pivot) {
            start++;
        }
        while(A[end] > pivot) {
            end--;
        }
        if(start < end) {
            swap(&A[start], &A[end]);
        }
    }
    swap(&A[lb], &A[end]);
    return end;
}

void quicksort(int *A, int lb, int ub) {
    if(ub > lb) {
        int loc = partition(A, lb, ub);
        quicksort(A, lb, loc - 1);
        quicksort(A, loc + 1, ub);
    }
}

int main() {
    int n = 7;
    int odd[] = {7, 4, 10, 8, 16, 3, 1};
      
    printf("sorted array by selection sort\n");
    selectionsort(odd, 7);
    print(odd, 7);
    printf("\n");
      
    printf("sorted array by merge sort\n");
    mergesort(odd, 0, n-1);
    print(odd, 7);
    printf("\n");
      
    printf("sorted array by quick sort\n");
    quicksort(odd, 0, n-1);
    print(odd, 7);

    return 0;
}
