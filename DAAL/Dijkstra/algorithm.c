#include <stdio.h>
#include <limits.h>

#define V 7 


int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the table at each step
void printTable(int step, int dist[], int visited[]) {
    printf("Iteration %d:\n", step);
    printf("Vertex \t Distance \t Visited\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t %d \t\t %s\n", i, dist[i], visited[i] ? "Yes" : "No");
    }
    printf("\n");
}





// Function that implements Dijkstra's algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V];    
    int visited[V]; 
    
   
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0; 

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX  && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }

        // Print table at each step
        printTable(count + 1, dist, visited);
    }
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 1, 0, 0, 0},
        {0, 0, 0, 3, 10, 0, 0},
        {4, 0, 0, 0, 0, 5, 0},
        {0, 0, 2, 0, 2, 8, 4},
        {0, 0, 0, 0, 0, 0, 6},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0}
    };
    
    int src = 0;
    printf("Dijkstra's Algorithm\n\n");
    dijkstra(graph, src);
    return 0;
}