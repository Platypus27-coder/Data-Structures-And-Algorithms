#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>

using namespace std;
using ll = long long;

vector<int> adj[1005];
int visited[1005];
stack<int> st;

void build(int n, int m) {
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    memset(visited, 0, sizeof(visited));
}

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
    st.push(u);
}

int main() {
    int m, n; 
    cin >> m >> n;
    build(n, m);
    for (int i = 1; i <= m; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}



