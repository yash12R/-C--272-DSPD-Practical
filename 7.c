#include <stdio.h>
#define SIZE 9

// Adjacency matrix for 3x3 grid graph
int graph[SIZE+1][SIZE+1] = {
    {0},
    {0,0,1,0,1,0,0,0,0,0},   // 1 connected to 2,4
    {0,1,0,1,1,1,0,0,0,0},   // 2 connected to 1,3,5
    {0,0,1,0,0,1,0,0,0,0},   // 3 connected to 2,6
    {0,1,1,0,0,1,0,1,0,0},   // 4 connected to 1,5,7
    {0,0,1,1,1,0,1,1,0,0},   // 5 connected to 2,4,6,8
    {0,0,0,1,0,1,0,0,0,1},   // 6 connected to 3,5,9
    {0,0,0,0,1,0,0,0,1,0},   // 7 connected to 4,8
    {0,0,0,0,0,1,0,1,0,1},   // 8 connected to 5,7,9
    {0,0,0,0,0,0,1,0,1,0}    // 9 connected to 6,8
};

// ------------------------- BFS -------------------------
void BFS(int start) {
    int queue[SIZE], front = 0, rear = 0;
    int visited[SIZE+1] = {0};
    queue[rear++] = start;
    visited[start] = 1;

    printf("\nBFS Traversal: ");
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        // Add all unvisited neighbors in ascending order
        for (int i = 1; i <= SIZE; i++) {
            if (graph[node][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

// ------------------------- DFS -------------------------
void DFS(int start, int visited[]) {
    printf("%d ", start);
    visited[start] = 1;

    // Explore neighbors in descending order
    for (int i = SIZE; i >= 1; i--) {
        if (graph[start][i] && !visited[i])
            DFS(i, visited);
    }
}

int main() {
    int visited[SIZE+1] = {0};

    printf("Graph Traversal on 3x3 Grid (Starting from Node 1):\n");

    BFS(1);

    printf("\nDFS Traversal: ");
    DFS(1, visited);
    printf("\n");

    return 0;
}
