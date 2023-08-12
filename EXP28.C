#include <stdio.h>

int binomialCoefficient(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }
    return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
}

void printPascalTriangle(int numRows) {
    for (int i = 0; i < numRows; i++) {
        // Print leading spaces
        for (int spaces = 0; spaces < numRows - i; spaces++) {
            printf(" ");
        }
        
        // Print values for the current row
        for (int j = 0; j <= i; j++) {
            printf("%d ", binomialCoefficient(i, j));
        }
        
        printf("\n");
    }
}

int main() {
    int numRows;

    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &numRows);

    printPascalTriangle(numRows);

    return 0;
}
