#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void sieve(ll l, ll r) {
    int prime[r - l + 1];
    for (int i = 0; i <= r - l; i++) {
        prime[i] = 1;
    }
    for (ll i = 2; i <= sqrt(r); i++) {
        for (ll j = max(1ll * i * i, ((i + l - 1) / i) * i); j <= r; j += i) {
            prime[j - l] = 0;
        }
    }
    for (int i = max(2ll, l); i <= r; i++) {
        if (prime[i - l]) {
            cout << i << " ";
        }
    }
}

int main() {
    int l, r;
    cin >> l >> r;
    sieve(l, r);
    return 0;
}
