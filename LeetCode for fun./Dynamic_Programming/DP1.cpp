// Frog Jump
#include <bits/stdc++.h>
using namespace std;

int DP[100], A[100];
int n;

void start() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
}

int solve_DP() {
    DP[0] = 0;
    DP[1] = (int)abs(A[1] - A[0]);
    for (int i = 2; i < n; i++) {
        DP[i] = min(DP[i - 2] + abs(A[i] - A[i - 2]), DP[i - 1] + abs(A[i] - A[i - 1]));
    }
    
    return DP[n - 1];
}
