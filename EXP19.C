#include <stdio.h>

// Structure to represent items
struct Item {
    int value;
    int weight;
};

// Function to compare items by their value-to-weight ratio
int compareItems(const void *a, const void *b) {
    double ratioA = (double)((struct Item *)a)->value / ((struct Item *)a)->weight;
    double ratioB = (double)((struct Item *)b)->value / ((struct Item *)b)->weight;

    if (ratioA > ratioB)
        return -1;  // Sort in decreasing order
    else if (ratioA < ratioB)
        return 1;
    else
        return 0;
}

// Function to solve Fractional Knapsack using greedy technique
double fractionalKnapsack(int capacity, struct Item items[], int n) {
    qsort(items, n, sizeof(items[0]), compareItems);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remainingWeight = capacity - currentWeight;
            totalValue += (double)(remainingWeight) * items[i].value / items[i].weight;
            break;
        }
    }

    return totalValue;
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];
    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    int capacity;
    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    double maxValue = fractionalKnapsack(capacity, items, n);
    printf("Maximum value that can be obtained: %.2lf\n", maxValue);

    return 0;
}
