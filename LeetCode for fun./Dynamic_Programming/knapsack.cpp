#include<bits/stdc++.h>
using namespace std;

int knapsack(int n, int W, int weight[], int value[]) {
    DP[101][1001] = {0};
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            DP[i][w] = DP[i - 1][w];
            if (w >= weight[i - 1]) {
                DP[i][w] = max(DP[i][w], DP[i - 1][w - weight[i - 1]] + value[i - 1]);
            }
        }
    }
    return DP[n][w];
}

int main() {
    int n, W;
    cin >> n >> W;
    int weight[n], value[n];
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }
    cout << knapsack(n, W, weight, value);
    return 0;
}
