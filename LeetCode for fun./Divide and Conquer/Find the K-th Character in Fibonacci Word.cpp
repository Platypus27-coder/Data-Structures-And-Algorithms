#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll F[100];

char find(ll n, int k) {
    if (n == 1) return 'A';
    if (n == 2) return 'B';
    if (k <= F[n - 2]) {
        return find(n - 2, k);
    }
    else {
        return find(n - 1, k - F[n - 2]);
    }
}

int main() {
  ll n, k;
  cin >> n >> k;
  F[0] = F[1] = 1;
  for (int i = 2; i < n; i++) {
        F[i] = F[i - 1] + F[i - 2];
  }
  cout << find(n, k);
  return 0;
}
