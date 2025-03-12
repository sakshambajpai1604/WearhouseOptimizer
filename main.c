#include <stdio.h>
#include "knapsack.h"

#define MAX_ITEMS 100  

int main() {
    int n, capacity;
    int weights[MAX_ITEMS], values[MAX_ITEMS];

    // Read input from file
    FILE *file = fopen("items.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fscanf(file, "%d %d", &n, &capacity);
    for (int i = 0; i < n; i++)
        fscanf(file, "%d %d", &weights[i], &values[i]);

    fclose(file);

    // Calculate the maximum value using Knapsack DP
    int max_value = knapsack(weights, values, n, capacity);

    printf("Maximum Storage Value: %d\n", max_value);

    // Save results
    FILE *output = fopen("results.txt", "w");
    fprintf(output, "Maximum Storage Value: %d\n", max_value);
    fclose(output);

    return 0;
}
