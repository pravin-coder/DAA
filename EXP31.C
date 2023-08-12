#include <stdio.h>
#include <limits.h>

int main() {
    int size;

    printf("Enter the size of the list: ");
    scanf("%d", &size);

    int list[size];

    printf("Enter the elements of the list:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &list[i]);
    }

    int min = INT_MAX;
    int max = INT_MIN;

    for (int i = 0; i < size; i++) {
        if (list[i] < min) {
            min = list[i];
        }
        if (list[i] > max) {
            max = list[i];
        }
    }

    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);

    printf("Sequence of numbers between minimum and maximum values:\n");
    for (int i = min + 1; i < max; i++) {
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}
