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
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
}

void prim(int s) {
    taken[s] = true;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    for (auto it : adj[s]) {
        int t = it.first;
        if (!taken[t]) {
            Q.push({it.second, t});
        }
    }
    ll d = 0, cnt = 0;
    while(!Q.empty()) {
        pair<int, int> e = Q.top();
        Q.pop();
        int w = e.first;
        int u = e.second;
        if (!taken[u]) {
            d += w;
            ++cnt;
            taken[u] = true;
            for (auto it : adj[u]) {
                if (!taken[it.first]) {
                    Q.push({it.second, it.first});
                }
            }
        }
        if (cnt == n - 1) {
            cout << d << endl;
        }
        else {
            cout << "IMPOSSILBLE\n";
        }
    }
}

int main() {
    in();
    prim(0);
    return 0;
}
