#include <bits/stdc++.h>
using namespace std; 

vector<string> v; 
int arr[100];
int x[100], n;

void backtrack(int i, int pos) {
    if (i >= 2) {
        string res;
        for (int k = 0; k < i; k++) {
            res += to_string(x[k]) + " ";
        }
        v.push_back(res);
    }
    for (int j = pos; j < n; j++) {
        if (i == 0 || arr[j] > x[i - 1]) {
            x[i] = arr[j];
            backtrack(i + 1, j + 1);
        }
    }
} 

int main() {
    cin >> n; 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    backtrack(0, 0);
    sort(v.begin(), v.end());
    for (string s : v) {
        cout << s << endl; 
    }
    return 0;
}
