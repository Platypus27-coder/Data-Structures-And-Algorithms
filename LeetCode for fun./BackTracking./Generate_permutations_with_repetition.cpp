// Generate all length-n sequences from 1..n (with repetition)

#include<bits/stdc++.h>
using namespace std;

int X[100], n;

void Try3(int i) {
    for (int j = 1; j <= n; j++) {
        X[i] = j;
        if (i == n) {
            for (int i = 1; i <= n; i++) {
                cout << X[i] << " ";
            }
            cout << endl;
        }
        else {
            Try3(i + 1);
        }
    }
}
