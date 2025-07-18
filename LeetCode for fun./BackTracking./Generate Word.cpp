#include <iostream>

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char s[100];
char c[100][100];
int n, m;
bool used[100][100];

void start() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c[i][j];
        }
    }
}

bool backtrack(int i, int j, char tmp[1000], int len) {
    tmp[len] = c[i][j];
    tmp[len + 1] = '\0';
    if (strcmp(tmp, s) == 0) {
        return true;
    }
    for (int k = 0; k < 4; k++) {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if (i1 < n && i1 >= 0 && j1 < m && j1 >= 0 && used[i1][j1] == false) {
            used[i1][j1] = true;
            if (backtrack(i1, j1, tmp, len + 1)) {
                return true;
            }
            used[i1][j1] = false;       
        }
    }
    tmp[len] = '\0';
    return false;
}

int main() {
    start();
    if (backtrack(0, 0, "", 0)) {
        cout << "Can Find" << endl;
    }
    else {
        cout << "Cann't Find" << endl;
    }
}
