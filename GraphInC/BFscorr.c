#include <stdio.h>
#include <stdlib.h>
#define MAX 8

int stack[MAX];
int rear = -1;
int front = -1; 

void enqueue(int data) {
        stack[++rear] = data;
}

int dequeue() {
        return stack[++front];
}

int main() {

    int visited[7] = {0,0,0,0,0,0,0};
    int a[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0},
    };

    int i= 0;
    printf("%d ", i);
    visited[i] = 1;
    enqueue(i);

    while (front != rear) {
        int vis = dequeue();
        for (int j = 0; j < 7; j++) {
            if (a[vis][j] == 1 && visited[j]==0) {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }

    return 0;
}
