#include <stdio.h>
#include <stdbool.h>

void printSubset(int subset[], int subsetSize) {
    printf("Subset with the sum: ");
    for (int i = 0; i < subsetSize; i++) {
        printf("%d ", subset[i]);
    }
    printf("\n");
}

void subsetSumUtil(int set[], int subset[], int n, int subsetSize, int sum, int targetSum, int currentIndex) {
    if (sum == targetSum) {
        printSubset(subset, subsetSize);
        return;
    }

    for (int i = currentIndex; i < n; i++) {
        if (sum + set[i] <= targetSum) {
            subset[subsetSize] = set[i];
            subsetSumUtil(set, subset, n, subsetSize + 1, sum + set[i], targetSum, i + 1);
        }
    }
}

void subsetSum(int set[], int n, int targetSum) {
    int subset[n];
    subsetSumUtil(set, subset, n, 0, 0, targetSum, 0);
}

int main() {
    int set[] = {10, 7, 5, 18, 12, 20, 15};
    int n = sizeof(set) / sizeof(set[0]);
    int targetSum = 35;

    subsetSum(set, n, targetSum);

    return 0;
}
