#include<stdio.h>
#include<stdlib.h>

int main(){
    int u,v;
    scanf("%d %d",&u,&v);

    int adj[u][u];
    for(int i=0;i<u;i++){
        for(int j=0;j<u;j++){
            adj[i][j]=0;
        }
    }

    int x,y;
    for(int i=0;i<v;i++){
        scanf("%d %d",&x,&y);
        adj[x][y]=1;
        adj[y][x]=1;
    }

    for(int i=0;i<u;i++){
        for(int j=0;j<u;j++){
            printf("%d ",adj[i][j]);
    }
    printf("\n");
}
}