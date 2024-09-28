#include<stdio.h>
#include<stdlib.h>
#define u 7

int main(){
    
    int adj[u][u];

    for(int i=0;i<u;i++){
        for(int j=0;j<u;j++){
            adj[i][j] = 0;
        }
    }

    int t[][2] = {{1,5},{1,2},{2,3},{3,4},{4,5}};

    int m = sizeof(t)/(sizeof(int)*2);

    for(int i=0;i<m;i++){
        int x = t[i][0];
        int y = t[i][1];

        adj[x][y] = 1;
        adj[y][x] = 1;
    }

    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            printf("%d ",adj[i][j]);
        }
        printf("\n");
}

}
