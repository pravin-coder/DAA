#include <stdio.h>
#include <stdbool.h>

#define V 5  // Number of vertices

void printSolution(int path[]) {
    printf("Hamiltonian Circuit: ");
    for (int i = 0; i < V; i++) {
        printf("%d ", path[i]);
    }
    printf("%d\n", path[0]);  // Return to the starting vertex
}

bool isSafe(int v, int graph[V][V], int path[], int pos) {
    if (graph[path[pos - 1]][v] == 0) {
        return false;  // No edge between the previous vertex and the new vertex
    }

    for (int i = 0; i < pos; i++) {
        if (path[i] == v) {
            return false;  // Vertex already in the path
        }
    }

    return true;
}

bool hamiltonianUtil(int graph[V][V], int path[], int pos) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1) {
            return true;  // Hamiltonian circuit found
        }
        return false;
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            if (hamiltonianUtil(graph, path, pos + 1)) {
                return true;
            }

            path[pos] = -1;  // Backtrack
        }
    }

    return false;
}

bool hamiltonianCycle(int graph[V][V]) {
    int path[V];
    for (int i = 0; i < V; i++) {
        path[i] = -1;  // Initialize path with -1
    }
    path[0] = 0;  // Start from the first vertex

    if (!hamiltonianUtil(graph, path, 1)) {
        printf("No Hamiltonian circuit exists.\n");
        return false;
    }

    printSolution(path);
    return true;
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 1, 0},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0}
    };

    hamiltonianCycle(graph);

    return 0;
}
