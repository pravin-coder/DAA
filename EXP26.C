#include <stdio.h>

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        // Print leading spaces
        for (int spaces = 0; spaces < n - i; spaces++) {
            printf("  ");
        }

        // Print the numbers in ascending order
        for (int num = 1; num <= i; num++) {
            printf("%d", num);
            if (num != i) {
                printf(" ");
            }
        }

        printf("\n");
    }

    return 0;
}
