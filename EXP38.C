#include <stdio.h>
#include <stdbool.h>

#define N 4  // Number of workers and tasks

void printAssignment(int assignment[N]) {
    printf("Optimal assignment:\n");
    for (int i = 0; i < N; i++) {
        printf("Worker %d -> Task %d\n", i, assignment[i]);
    }
}

void hungarianAlgorithm(int costMatrix[N][N]) {
    int assignment[N];
    int rowCovered[N] = {0};
    int colCovered[N] = {0};
    
    for (int i = 0; i < N; i++) {
        assignment[i] = -1;
    }

    // Find the minimum cost and adjust cost matrix
    for (int i = 0; i < N; i++) {
        int minCost = costMatrix[i][0];
        for (int j = 1; j < N; j++) {
            if (costMatrix[i][j] < minCost) {
                minCost = costMatrix[i][j];
            }
        }
        for (int j = 0; j < N; j++) {
            costMatrix[i][j] -= minCost;
        }
    }

    // Main loop of the algorithm
    // To be continued...

    printAssignment(assignment);
}

int main() {
    int costMatrix[N][N] = {
        {5, 8, 7, 6},
        {8, 12, 7, 6},
        {7, 5, 6, 8},
        {6, 9, 9, 10}
    };

    hungarianAlgorithm(costMatrix);

    return 0;
}
