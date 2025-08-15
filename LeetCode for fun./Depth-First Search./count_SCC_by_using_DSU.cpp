#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>

using namespace std;
using ll = long long;

int n, m;
int parent[1005];
int sz[1005];

void init() {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int u) {
    if (parent[u] == u) {
        return u;
    }
    return parent[u] = find(parent[u]);
}

bool Union(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) {
        return false;
    }
    if (sz[u] > sz[v]) {
        parent[v] = u;
        sz[u] += sz[v];
    }
    else {
        parent[u] = v;
        sz[v] += sz[u];
    }
    return true;
}

int main() {
    cin >> n >> m;
    int cnt = n;
    init();
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        if(Union(x, y)) {
            --cnt;
        }
    }
    cout << cnt << endl;
    return 0;
}
