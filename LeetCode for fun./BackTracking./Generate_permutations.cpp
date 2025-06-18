// 	Generate all permutations (without repetition) of 1..n
#include<bits/stdc++.h>
using namespace std;

int X[100], n;

bool used[1000];

void Try4(int i) {
    for (int j = 1; j <= n; j++) {
        if (used[j] == false) {
            X[i] = j; 
            used[j] = true;
            if (i == n) {
                for (int i = 1; i <= n; i++) {
                    cout << X[i] << " ";
                }
                cout << endl;
            }
            else {
                Try4(i + 1);
            }
            used[j] = false;
        }
    }
}
