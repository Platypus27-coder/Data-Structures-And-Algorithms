// Generate all binary sequences of length n
#include<bits/stdc++.h>
using namespace std;

int X[100], n;

void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        X[i] = j;
        if (i == n) {
            for (int i = 1; i <= n; i++) {
                cout << X[i] << " " ;
            }
            cout << endl; 
        }
        else {
            Try(i + 1);
        }
    }
}
