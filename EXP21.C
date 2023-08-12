#include <stdio.h>
#include <limits.h>

// Function to find the sum of frequencies from i to j
int sumOfFrequencies(int freq[], int i, int j) {
    int sum = 0;
    for (int k = i; k <= j; k++) {
        sum += freq[k];
    }
    return sum;
}

// Function to find the optimal cost of a binary search tree
int optimalCost(int keys[], int freq[], int n) {
    int dp[n][n];  // Dynamic programming table to store optimal costs

    for (int i = 0; i < n; i++) {
        dp[i][i] = freq[i];  // Single nodes have the frequency as their cost
    }

    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length + 1; i++) {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;

            for (int r = i; r <= j; r++) {
                int cost = ((r > i) ? dp[i][r - 1] : 0) +
                           ((r < j) ? dp[r + 1][j] : 0) +
                           sumOfFrequencies(freq, i, j);

                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    int keys[] = {10, 12, 16, 21};
    int freq[] = {4, 2, 6, 3};
    int n = sizeof(keys) / sizeof(keys[0]);

    int cost = optimalCost(keys, freq, n);
    printf("Optimal cost of the binary search tree: %d\n", cost);

    return 0;
}
