#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>

using namespace std;
using ll = long long;

vector<int> adj[1005], t_adj[1005];
int visited[1005];
stack<int> st;
int timer = 0, scc = 0;
int in_stack[1005];
int disc[1005], low[1005];

void build(int n, int m) {
    for (int i = 1; i <= n; i++) {
        int x, y; 
        cin >> x >> y;
        adj[x].push_back(y);
    }
}

void dfs(int u) {
    visited[u] = true;
    in_stack[u] = true;
    disc[u] = low[u] = ++timer;
    st.push(u);
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if (in_stack[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }
    if (low[u] == disc[u]) {
        ++scc;
        while(st.top() != u) {
            cout << st.top() << " ";
            in_stack[st.top()] = 0;
            st.pop();
        }
        cout << st.top() << endl;
        in_stack[st.top()] = 0;
        st.pop();
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
    cout << scc << endl;
}
