#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>
#include<cctype>

using namespace std;
using ll = long long;

int main() {
    int n; 
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int res[n];
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while(!st.empty() && a[i] > a[st.top()]) {
            res[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()) {
        res[st.top()] = -1;
        st.pop();
    }
    for (int x : res) {
        cout << x << " ";
    }
    return 0;
}
