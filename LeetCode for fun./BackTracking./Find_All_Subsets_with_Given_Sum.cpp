#include <bits/stdc++.h>
using namespace std;

int s, X[100];
int n, arr[100];
int flag = 0;

void backtrack(int sum, int i, int pos) {
    if (sum == s) {
        flag = 1;
        cout << "[";
        for (int k = 0; k < i; k++) {
            cout << X[k];
            if (k != i - 1) {
                cout << " ";
            }
            else {
                cout << "]";
            }
        }
        cout << endl;
    }
    else {
        for (int j = pos; j < n; j++) {
            if (sum + arr[j] <= s) {
                X[i] = arr[j];
                backtrack(sum + arr[j], i + 1, j + 1);
            }
        }
    }
}

int main () {
  cin >> n >> s; 
  for (int i = 0; i < n; i++) {
      cin >> arr[i];
  }
  backtrack(0, 0, 0);
  if (!flag) {
    cout << "-1" << endl;
  }
  return 0;
}
