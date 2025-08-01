#include <bits/stdc++.h>
#include <vector>

using namespace std;
using ll = long long;

vector<int> adj[1005];
bool visited[1005];
int n, m, s;

void build() {
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}
