#include <stdio.h>
#define INF 1000L
#define numV 6

int Graph[numV][numV] = {
    {0, 5, INF, 2, 4, INF},
    {5, 0, 3, 3, INF, INF},
    {INF, 3, 0, 3, 4, 2},
    {2, 3, 3, 0, 1, INF},
    {4, INF, 4, 1, 0, 2},
    {INF, INF, 2, INF, 2, 0}
};

void dijkstra(int W[numV][numV]) {
    int visit[numV], distance[numV];
    int i, j, k, min;
    int start = 0;

    for (i = 0; i < numV; i++) {
        visit[i] = 0;
        distance[i] = INF;
    }
    distance[start] = 0;
    
    for (i = 0; i < numV; i++) {
        min = INF;
        for (j = 0; j < numV; j++) {
            if (visit[j] == 0 && distance[j] < min) {
                k = j;
                min = distance[j];
            }
        }
        visit[k] = 1;

        for (j = 0; j < numV; j++) {
            if (distance[j] > distance[k] + Graph[k][j]) 
                distance[j] = distance[k] + Graph[k][j];
        }
    }

    for (i = 0; i < numV; i++)
        printf("%d ", distance[i]);
}

int main() {
    dijkstra(Graph);

    return 0;
}