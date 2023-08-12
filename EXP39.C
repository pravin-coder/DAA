#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Return the index where the target was found
        }
    }
    return -1;  // Return -1 if the target was not found
}

int main() {
    int arr[] = {10, 25, 7, 18, 32, 12, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Enter the target value: ");
    scanf("%d", &target);

    int result = linearSearch(arr, size, target);

    if (result != -1) {
        printf("Target found at index %d\n", result);
    } else {
        printf("Target not found in the array\n");
    }

    return 0;
}
