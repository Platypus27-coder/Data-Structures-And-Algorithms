#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>

using namespace std;
using ll = long long;

int n, m;
int parent[1005];
int sz[1005];

struct edges {
    int x, y, w;
};

vector<edges> list_edges;

void in() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> y;
        edges e{x, y, w};
        list_edges.push_back(e);
    }
}

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

bool cmp(edges a, edges b) {
    return a.w < b.w;
}

void kruskal() {
    sort(list_edges.begin(), list_edges.end(), cmp); 
    vector<edges> MST;
    int d = 0;
    for (int i = 0; i < m; i++) {
        if (MST.size() == n - 1) break;
        if (Union(list_edges[i].x, list_edges[i].y)) {
            d += list_edges[i].w;
            MST.push_back(list_edges[i]);
        }
    }
    if (MST.size() != n - 1) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        cout << d << endl;
    }
}

int main() {
    in();
    init();
    kruskal();
    return 0;
}
