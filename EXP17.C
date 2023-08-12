#include <stdio.h>

// Function to find maximum and minimum using Divide and Conquer
void findMaxMin(int arr[], int left, int right, int *max, int *min) {
    if (left == right) {
        *max = arr[left];
        *min = arr[left];
        return;
    } else if (left == right - 1) {
        if (arr[left] < arr[right]) {
            *max = arr[right];
            *min = arr[left];
        } else {
            *max = arr[left];
            *min = arr[right];
        }
        return;
    }

    int mid = (left + right) / 2;
    int leftMax, leftMin, rightMax, rightMin;

    findMaxMin(arr, left, mid, &leftMax, &leftMin);
    findMaxMin(arr, mid + 1, right, &rightMax, &rightMin);

    if (leftMax > rightMax) {
        *max = leftMax;
    } else {
        *max = rightMax;
    }

    if (leftMin < rightMin) {
        *min = leftMin;
    } else {
        *min = rightMin;
    }
}

int main() {
    int size;

    printf("Enter the size of the list: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the list:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int max, min;
    findMaxMin(arr, 0, size - 1, &max, &min);

    printf("Maximum value in the list: %d\n", max);
    printf("Minimum value in the list: %d\n", min);

    return 0;
}
