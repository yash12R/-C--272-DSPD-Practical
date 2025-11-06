#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF 9999

void dijkstra(int graph[MAX][MAX], int n, int start) {
    int distance[MAX], visited[MAX], parent[MAX];
    
    // Initialize distances and visited array
    for (int i = 1; i <= n; i++) {
        distance[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    distance[start] = 0;  // Distance to itself = 0

    for (int count = 1; count <= n - 1; count++) {
        int min = INF, u = -1;

        // Find unvisited node with smallest distance
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && distance[i] < min) {
                min = distance[i];
                u = i;
            }
        }

        if (u == -1)
            break;  // All reachable nodes are processed

        visited[u] = 1;

        // Update distances for neighbors
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] && distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print shortest distances
    printf("\nShortest Distances from Node %d:\n", start);
    for (int i = 1; i <= n; i++) {
        if (distance[i] == INF)
            printf("Node %d : -1 (Unreachable)\n", i);
        else
            printf("Node %d : %d\n", i, distance[i]);
    }

    // Print the shortest-path tree (parent relationships)
    printf("\nSubtree using Dijkstra’s Algorithm (Parent Relationships):\n");
    for (int i = 1; i <= n; i++) {
        if (i != start) {
            if (parent[i] == -1)
                printf("Node %d <- None (Unreachable)\n", i);
            else
                printf("Node %d <- %d\n", i, parent[i]);
        }
    }
}

int main() {
    int n, edges, u, v, w, start;
    int graph[MAX][MAX] = {0};

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;  // Undirected graph
    }

    printf("Enter starting node: ");
    scanf("%d", &start);

    dijkstra(graph, n, start);

    return 0;
}
