// Generate all combinations of k elements chosen from 1..n
#include<bits/stdc++.h>
using namespace std;

int X[100], n, k;

void Try2(int i) {
    for (int j = X[i - 1] + 1; j <= n - k + i; j++) {
        X[i] = j; 
        if (i == k) {
            for (int i = 1; i <= k; i++) {
                cout << X[i] << " ";
            }
            cout << endl; 
        }
        else {
            Try2(i + 1);
        }
    }
}
