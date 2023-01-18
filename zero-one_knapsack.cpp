#include <iostream>

#define SIZE 3

int knapSack(int W, int wt[], int val[], int n) {
    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);

    return std::max(
        val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),
        knapSack(W, wt, val, n - 1));
}

int main() {
    int val[SIZE] = {60, 100, 120};
    int weight[SIZE] = {10, 20, 30};
    int W = 50;
    std::cout << knapSack(W, weight, val, SIZE);
    return 0;
}