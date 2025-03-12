#include <stdio.h>

#define MAX_ITEMS 100  
#define MAX_CAPACITY 100  

// Knapsack DP function
int knapsack(int weights[], int values[], int n, int capacity) {
    int dp[MAX_ITEMS + 1][MAX_CAPACITY + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = (values[i - 1] + dp[i - 1][w - weights[i - 1]] > dp[i - 1][w]) 
                            ? values[i - 1] + dp[i - 1][w - weights[i - 1]] 
                            : dp[i - 1][w];
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][capacity];  // Return the maximum possible value
}
