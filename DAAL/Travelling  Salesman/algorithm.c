#include <stdio.h>
#include <limits.h>

#define N 4 

int minCost = INT_MAX;
int visited[N];
int bestPath[N + 1], tempPath[N + 1];

void tsp(int graph[N][N], int currPos, int count, int cost, int start) {
    tempPath[count - 1] = currPos;  

    if (count == N && graph[currPos][start]) { 
        if (cost + graph[currPos][start] < minCost) {
            minCost = cost + graph[currPos][start];
            for (int i = 0; i < N; i++)  
                bestPath[i] = tempPath[i];
            bestPath[N] = start;  
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i] && graph[currPos][i]) { 
            visited[i] = 1;
            tsp(graph, i, count + 1, cost + graph[currPos][i], start);
            visited[i] = 0;
        }
    }
}

int main() {
    int graph[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    for (int i = 0; i < N; i++) visited[i] = 0;
    visited[0] = 1;

    tsp(graph, 0, 1, 0, 0);

    printf("Minimum cost of travelling salesman tour: %d\n", minCost);
    printf("Best path: ");
    for (int i = 0; i <= N; i++)
        printf("%d ", bestPath[i]);
    printf("\n");

    return 0;
}
