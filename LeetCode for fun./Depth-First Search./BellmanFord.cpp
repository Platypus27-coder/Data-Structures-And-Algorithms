#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>

using namespace std;
using ll = long long;

int n, m;
int d[1005];

struct edge {
    int x, y, w;
};

vector<edge> E;

void in() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        E.push_back({x, y, w});
        E.push_back({y, x, w});
    }
}

void BellmanFord(int s) {
    fill(d + 1, d + n + 1, 1e9);
    d[s] = 0;
    for (int i = 1; i <= n - 1; i++) {
        for (edge e : E) {
            int u = e.x, v = e.y, w = e.w;
            if (d[u] < 1e9) {
                d[v] = min(d[v], d[u] + w);
            }
        }
    }
    bool hasNegcycle = false;
    for (edge e : E) {
        int u = e.x, v = e.y, w = e.w;
        if (d[u] < 1e9) {
            if (d[v] > d[u] + w) {
                hasNegcycle = true;
                break;
            }
        }
    }

    if (hasNegcycle) {
        cout << "Graph contains negative weight cycle\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        cout << d[i] << " ";
    }
}

int main() {
    in();
    BellmanFord(1);
    return 0;
}
