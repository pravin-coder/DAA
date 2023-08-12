#include <stdio.h>
#include <limits.h>

#define N 4  // Number of cities

int tsp(int graph[][N], int visited, int current) {
    if (visited == (1 << N) - 1) {
        return graph[current][0];
    }

    int minCost = INT_MAX;

    for (int city = 0; city < N; city++) {
        if (!(visited & (1 << city))) {
            int newCost = graph[current][city] + tsp(graph, visited | (1 << city), city);
            if (newCost < minCost) {
                minCost = newCost;
            }
        }
    }

    return minCost;
}

int main() {
    int graph[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int minCost = tsp(graph, 1, 0);  // Start from city 0, with only city 0 visited
    printf("Minimum cost for TSP: %d\n", minCost);

    return 0;
}
