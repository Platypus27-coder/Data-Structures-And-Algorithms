// Find all paths from (1,1) to (n,n) using all four directions (D, R, U, L)
#include<bits/stdc++.h>
using namespace std;

int n, arr[n + 1][n + 1];
int flag = 0; 
string s = "";

void Try5(int i, int j) {
    if (i == n && j == n) {
        flag = 1; 
        cout << s << endl;
    }
    if (i + 1 <= n && arr[i + 1][j] == 1) {
        s += "D";
        arr[i + 1][j] = 0;
        Try5(i + 1, j);
        arr[i + 1][j] = 1;
        s.pop_back();
    }
    if (j + 1 <= n && arr[i][j + 1] == 1) {
        s += "R";
        arr[i][j + 1] = 0;
        Try5(i, j + 1);
        arr[i][j + 1] = 1; 
        s.pop_back();
    }
    if (i - 1 >= 1 && arr[i - 1][j] == 1) {
        s += "U";
        arr[i - 1][j] = 0;
        Try5(i - 1, j);
        arr[i - 1][j] = 1;
        s.pop_back();
    }
    if (j - 1 >= 1 && arr[i][j - 1] == 1) {
        s += "L";
        arr[i][j - 1] = 0;
        Try5(i, j - 1);
        arr[i][j - 1] = 1;
        s.pop_back();
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    if (arr[1][1]) {
        arr[1][1] = 0;
        Try5(1, 1);
    }
    if (!flag) cout << "ERROR\n"; 
    return 0; 
}
