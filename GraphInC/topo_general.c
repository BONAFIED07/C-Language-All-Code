#include <stdio.h>
#include <stdlib.h>

void tplgSort(int list[],int V){

    printf("Topological Order: "); 
    for (int i = 0; i < V; i++){
        int data = list[i];
        int x = i;
        for (int j = 0; j < V; j++){
            if (list[j] > data){
                data = list[j];
                x = j;
            }
        }
        printf("%c ", 'a' + x);
        list[x] = -1;
    }
    printf("\n");
}


int main()
{
    int u,v;
    printf("Write number of Elements and number of Edges in the Graph : ");
    scanf("%d %d",&u,&v);
    int graph[u][u];

    for(int i=0; i<u; i++){
        for(int j=0; j<u; j++){
            graph[i][j]=0;
        }
    }

    int TPlist[u];
    for(int i=0; i<u; i++){
        TPlist[i]=0;
    }

    printf("Now specify Edges :\n");
    int x,y;
    for(int i=0; i<v; i++){
            scanf("%d %d",&x,&y);
            graph[x][y]=1;
    }

    for (int i = 0; i < u; i++){
        for (int j = 0; j < u; j++){
            if (graph[i][j] == 1){
                TPlist[i]++;
            }
        }
    }
    // printGraph(graph);
    tplgSort(TPlist,u);

    return 0;
}
