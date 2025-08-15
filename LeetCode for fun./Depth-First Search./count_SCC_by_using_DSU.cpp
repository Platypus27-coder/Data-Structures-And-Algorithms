#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>

using namespace std;
using ll = long long;

int n, m;
int parent[1005];

void init() {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
}

int find(int u) {
    while(u != parent[u]) {
        u = parent[u];
    }
    return u;
}

bool Union(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) {
        return false;
    }
    else if (u < v) {
        parent[v] = u;
    }
    else {
        parent[u] = v;
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
