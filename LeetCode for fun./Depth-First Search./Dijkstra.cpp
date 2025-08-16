#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>

using namespace std;
using ll = long long;

int n, m;
vector<pair<int, int>> adj[1005];
bool taken[10005];

void in() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
}

void Dijkstra(int s) {
    vector<int> d(n + 1, 1e9);
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push({0, s});
    while(!Q.empty()) {
        pair<int, int> top = Q.top();
        Q.pop();
        int u = top.second;
        int w = top.first;
        if (w > d[u]) {
            continue;
        }
        for (auto it : adj[u]) {
            if (d[u] + it.second < d[it.first]) {
                d[it.first] = d[u] + it.second;
                Q.push({d[it.first], it.first});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << d[i] << " ";
    }
}

int main() {
    in();
    Dijkstra(1);
    return 0;
}
