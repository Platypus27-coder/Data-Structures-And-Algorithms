#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>

using namespace std;
using ll = long long;

vector<int> adj[1005];
bool visited[1005];
int degree[1005];
queue<int> q;

void build(int n, int m) {
    for (int i = 1; i <= n; i++) {
        int x, y; 
        cin >> x >> y;
        adj[x].push_back(y);
        degree[y]++;
    }
    
}

void kahn(int m) {
    for (int i = 1; i <= m; i++) {
        if (degree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> topo;
    while(!q.empty()) {
        int x = q.front();
        topo.push_back(x);
        q.pop();
        for (int v : adj[x]) {
            --degree[v];
            if (degree[v] == 0) {
                q.push(v);
            }
        }
    }
    for (int x : topo) cout << x << " ";
}
