#include <iostream>
using namespace std;

int X[100], n, ans = 0;
int d1[100], d2[100], c[100];

int BackTrack(int i) {
    for (int j = 1; j <= n; j++) {
        if (c[j] == 0 && d1[i + j - 1] == 0 && d2[i - j + n] == 0) {
            X[i] = j;
            d1[i + j - 1] = 1;
            d2[i - j + n] = 1;
            if (i == n) {
                for (int row = 1; row <= n; row++) {
                    for (int col = 1; col <= n; col++) {
                        if (X[row] == col) {
                            cout << "#";
                        }
                        else {
                            cout <<".";
                        }
                    }
                    cout << endl;
                }
                cout << endl;
            }
            else {
                BackTrack(i + 1);
                X[i] = 0;
                d1[i + j - 1] = 0;
                d2[i - j + n] = 0;
            }
        }
    }
}
