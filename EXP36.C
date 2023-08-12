#include <stdio.h>

#define NUM_CONTAINERS 3
#define NUM_ITEMS 5

void containerLoading(int containers[], int items[], int numContainers, int numItems) {
    for (int i = 0; i < numItems; i++) {
        int minSpaceIndex = 0;

        // Find the container with the least remaining space
        for (int j = 1; j < numContainers; j++) {
            if (containers[j] < containers[minSpaceIndex]) {
                minSpaceIndex = j;
            }
        }

        // Pack the item into the container
        containers[minSpaceIndex] -= items[i];
        printf("Packed item %d into container %d\n", i + 1, minSpaceIndex + 1);
    }
}

int main() {
    int containers[NUM_CONTAINERS] = {10, 8, 6};
    int items[NUM_ITEMS] = {4, 5, 3, 2, 1};

    containerLoading(containers, items, NUM_CONTAINERS, NUM_ITEMS);

    return 0;
}
