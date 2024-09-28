#include <stdio.h>
#define INF 99999
#define V 4


void floydWarshall(int graph[V][V]) {
    int i,j,k;
    for (k = 0; k < V; k++) {                              // Main algo
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (graph[i][j] > graph[i][k] + graph[k][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }
}

void print(int graph[V][V]){
    int i, j;
    printf("The shortest graphances between every pair of vertices:\n");  // printing of Graph
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (graph[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
int graph[V][V] = {      // Hardcore
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    floydWarshall(graph);
    print(graph);

    return 0;
}
