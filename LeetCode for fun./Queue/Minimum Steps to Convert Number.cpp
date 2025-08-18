#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>
#include<cctype>

using namespace std;
using ll = long long;

int solve(int s, int t) {
    set<int> used;
    queue<pair<int, int>> q;
    q.push({s, 0});
    while(!q.empty()) {
        pair<int, int> x = q.front();
        q.pop();
        if (x.first == t) {
            return x.second;
        }
        if (used.count(x.first - 1) == 0) {
            q.push({x.first - 1, x.second + 1});
            used.insert(x.first - 1);
        }
        if (used.count(x.first * 2) == 0) {
            q.push({x.first * 2, x.second + 1});
            used.insert(x.first * 2);
        }
    }
    return -1;
}

int main() {
    int s, t; 
    cin >> s >> t;
    cout << solve(s, t);
    return 0;
}
