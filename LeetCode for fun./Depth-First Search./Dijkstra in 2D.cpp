#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>

using namespace std;
using ll = long long;

int n, m;
int a[100][100];
int d[100][100];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void in() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            d[i][j] = 1e9;
        }
    }
}

void Dijkstra(int i, int j) {
    d[i][j] = a[i][j];
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> Q;
    Q.push({d[i][j], {i, j}});
    while(!Q.empty()) {
        pair<int, pair<int, int>> top = Q.top();
        Q.pop();
        int w = top.first;
        int u = top.second.first;
        int v = top.second.second;
        if (w > d[u][v]) {
            continue;
        }
        for (int k = 0; k < 4; k++) {
            int u1 = u + dx[k];
            int v1 = v + dy[k];
            if (u1 <= n && u1 >= 1 && v1 <= m && v1 >= 1) {
                if (d[u1][v1] > d[u][v] + a[u1][v1]) {
                    d[u1][v1] = d[u][v] + a[u1][v1];
                    Q.push({d[u1][v1], {u1, v1}});
                }
            }
        }
    }
        cout << d[n][m] << endl;
}

int main() {
    in();
    Dijkstra(1, 1);
    return 0;
}
