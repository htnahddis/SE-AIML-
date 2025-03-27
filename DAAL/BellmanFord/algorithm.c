#include <stdio.h>
#include <limits.h>

#define V 5
#define E 8

struct Edge {
    int src, dest, weight;
};

void printTable(int step, int dist[]) {
    printf("\nStep %d:\n", step);
    printf("\n");
    printf("| Vert | 0  | 1  | 2  | 3  | 4  |\n");
  
    printf("| Dist | ");
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            printf(" ∞  |");
        else
            printf(" %2d |", dist[i]);
    }
    printf("\n");
}

void BellmanFord(struct Edge edges[], int src) {
    int dist[V];
    
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
    
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
        printTable(i, dist); 
    }
    
    for (int i = 0; i < E; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle!\n");
            return;
        }
    }
    
    printTable(V, dist);
}

int main() {
    struct Edge edges[E] = {
        {0, 1, 4, 0}, {0, 0, -3, 2}, {0, 0,0,  3}, {0, 0, 0, 0}
        
    };
    
    int src = 0;
    printf("Bellman-Ford Algorithm - Stepwise Execution\n\n");
    BellmanFord(edges, src);
    
    return 0;
}
