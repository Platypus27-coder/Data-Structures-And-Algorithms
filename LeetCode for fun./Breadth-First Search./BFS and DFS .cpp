
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
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
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

void bfs(int u) {
    visited[u] = true;
    queue<int> q;
    q.push(u);
    while(!q.empty()) {
        int x = q.front();
        cout << x << " ";
        q.pop();
        for (int v : adj[x]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }
    }
}
