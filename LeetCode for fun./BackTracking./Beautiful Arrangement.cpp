class Solution {
public:
    bool used[100];
    int ans = 0;

    void solve(int n, int j) {
        if (j > n) {
            ++ans;
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (used[i] == false && (j % i == 0 || i % j == 0)) {
                used[i] = true;
                solve(n, j + 1);
                used[i] = false;
            }
        }
    }

    int countArrangement(int n) {
        solve(n, 1);
        return ans;
    }
};
