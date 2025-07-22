// Frog Jump II
#include <bits/stdc++.h>
using namespace std;

int DP[10000];
int n, k;

int solve_DP2(int k) {
    DP[0] = 0;
    for (int i = 1; i < n; i++) {
        DP[i] = INT_MAX;
        for (int j = max(0, i - k); j < i; j++) {
            DP[i] = min(DP[j] + abs(A[i] - A[j]), DP[i]);
        }
    }
    return DP[n - 1];
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
      cin >> A[i];
  }
  cout << solve_DP2(k);
  return 0;
}
  
