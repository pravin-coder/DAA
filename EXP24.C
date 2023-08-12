#include <stdio.h>

// Function to check if a number is perfect
int isPerfect(int num) {
    int sum = 1;  // Initializing sum with 1 as every number has 1 as a proper divisor
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            sum += i;
            
            // If i is not the square root of num, add the corresponding divisor
            if (i * i != num) {
                sum += num / i;
            }
        }
    }
    
    return (sum == num);
}

int main() {
    int start, end;

    printf("Enter the range (start and end): ");
    scanf("%d %d", &start, &end);

    printf("Perfect numbers in the range %d to %d:\n", start, end);
    for (int num = start; num <= end; num++) {
        if (isPerfect(num)) {
            printf("%d ", num);
        }
    }
    printf("\n");

    return 0;
}
