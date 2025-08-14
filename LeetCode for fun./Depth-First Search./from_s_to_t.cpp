#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>

using namespace std;
using ll = long long;

vector<int> adj[1005];
bool visited[1005];
int parent[1005];

void build(int n) {
    for (int i = 1; i <= n; i++) {
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
    cout << u << " ";
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
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
                parent[v] = x;
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

int main() {
    int m, n, s, t;
    cin >> m >> n;
    cin >> s >> t;
    build(n);
    for (int i = 1; i <= m; i++) {
        dfs(i);
    }
    if (visited[t] == false) {
        cout << "-1\n";
    }
    else {
        vector<int> path;
        while(s != t) {
            path.push_back(t);
            t = parent[t];
        }
        path.push_back(t);
        reverse(path.begin(), path.end());
        for (int p : path) cout << p << " "; 
    }
    return 0;
}





