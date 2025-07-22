 // Longest Increasing Subsequence
#include <bits/stdc++.h>
using namespace;
int DP[100000];
int n; 
int A[100000];

int solve_DP3() {
    for (int i = 0; i < n; i++) {
        DP[i] = 1;
    }
    for (int i = 2; i < n; i++) {
        int dp = 0;
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i]) {
                dp = max(dp, DP[j]);
            }
        }
        DP[i] += dp;
    }
    int result = INT_MIN;
    for (int i = 0; i < n; i++) {
        result = max(result, DP[i]);
    }
    return result;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
          cin >> A[i];
    };
  cout << solve_DP3();
  return 0;
}
