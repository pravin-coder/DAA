#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int list[MAX_SIZE];
    int size, position, newNumber;

    printf("Enter the size of the list (up to %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size < 0 || size > MAX_SIZE) {
        printf("Invalid size\n");
        return 1;
    }

    printf("Enter %d elements for the list:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &list[i]);
    }

    printf("Enter the position to insert the new number (0-based index): ");
    scanf("%d", &position);

    if (position < 0 || position > size) {
        printf("Invalid position\n");
        return 1;
    }

    printf("Enter the new number to insert: ");
    scanf("%d", &newNumber);

    // Shift elements to make space for the new number
    for (int i = size; i > position; i--) {
        list[i] = list[i - 1];
    }

    list[position] = newNumber;
    size++;

    printf("List after inserting %d at position %d:\n", newNumber, position);
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    return 0;
}
