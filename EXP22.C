#include <stdio.h>

// Function to calculate binomial coefficient using dynamic programming
unsigned long long binomialCoefficient(int n, int k) {
    unsigned long long dp[n + 1][k + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k && j <= i; j++) {
            if (j == 0 || j == i) {
                dp[i][j] = 1;  // Base cases
            } else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }

    return dp[n][k];
}

int main() {
    int n, k;

    printf("Enter values of n and k (n choose k): ");
    scanf("%d %d", &n, &k);

    unsigned long long result = binomialCoefficient(n, k);
    printf("C(%d, %d) = %llu\n", n, k, result);

    return 0;
}
