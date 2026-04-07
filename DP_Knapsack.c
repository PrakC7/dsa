#include <stdio.h>
int table[5][9];

int max(int a, int b) {
    return (a > b) ? a : b;
}

int Knapsack(int item, int capacity,
             int profit[], int weight[]) {
    if (item == 0 || capacity == 0)
        return 0;
    if (table[item][capacity] != -1) //not included
        return table[item][capacity]; 
    if (weight[item] > capacity) {
        table[item][capacity] =
            Knapsack(item - 1, capacity, profit, weight); // do not put [] with array arguments
    }
    else {
        int exclude =
            Knapsack(item - 1, capacity, profit, weight);
        int include =
            profit[item] +
            Knapsack(item - 1,
                     capacity - weight[item],
                     profit, weight);
        table[item][capacity] = max(include, exclude);
    }
    return table[item][capacity];
}

int main() {
    int capacity = 8;
    int item = 4;
    int weight[] = {0, 2, 3, 5, 8}; //index 0 is not handled properly
    int profit[] = {0, 3, 6, 7, 12}; //index 0 is not handled properly
    for (int i = 0; i <= item; i++)
        for (int j = 0; j <= capacity; j++)
            table[i][j] = -1;
    printf("Max Profit: %d\n",
           Knapsack(item, capacity, profit, weight));
    return 0;
}
