#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;
using ll = long long;

vector<int> adj[1005], t_adj[1005];
bool visited[1005];
stack<int> st;

void build(int n, int m) {
    for (int i = 1; i <= n; i++) {
        int x, y; 
        cin >> x >> y;
        adj[x].push_back(y);
        t_adj[y].push_back(x);
    }
}

void dfs(int u) {
    visited[u] = 1;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
    st.push(u);
}

void dfs2(int u) {
    cout << u << " ";
    visited[u] = true;
    for (int v : t_adj[u]) {
        if(!visited[v]) {
            dfs2(v);
        }
    }
}

int main() {
    int n, m; 
    cin >> m >> n;
    build(n, m);
    for (int i = 1; i <= m; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    memset(visited, 0, sizeof(visited));
    while(!st.empty()) {
        int s = st.top();
        st.pop();
        if (!visited[s]) {
            dfs2(s);
            cout << endl;
        }
    }
    return 0;
}
