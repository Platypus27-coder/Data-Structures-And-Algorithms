class Solution {
public:
    // solution_1
    int dp[1000][1000];
    int solve(int i, int j, string &text1, string &text2) {
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if (text1[i] == text2[j]) {
            ans = 1 + solve(i - 1, j - 1, text1, text2);
        }
        else {
            ans = max(solve(i - 1, j, text1, text2), solve(i, j - 1, text1, text2));
        }
        return dp[i][j] = ans;
    }

    int longestCommonSubsequence_1(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        int n = text1.size();
        int m = text2.size();
        return solve(n - 1, m - 1, text1, text2);
    }
    // solution_2
    int longestCommonSubsequence_2(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= m; j++) {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};
