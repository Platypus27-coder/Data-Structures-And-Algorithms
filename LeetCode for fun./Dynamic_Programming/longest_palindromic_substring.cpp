class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 5, vector<int> (n + 5, 0));
        for (int x = 1; x <= n; x++) {
            for (int l =  n - 1; l >= 0; l--) {
                int r = l + x - 1;
                if (r >= n) continue;
                if (x == 1) {
                    dp[l][r] = 1;
                }
                else if (x == 2) {
                    if (s[l] == s[r]) {
                        dp[l][r] = 1;
                    }
                }
                else {
                    if (dp[l + 1][r - 1] && s[l] == s[r]) {
                        dp[l][r] = 1;
                    }
                }
            }
        }
        int ans = 0;
        int start = 0;
        for (int l = 0; l <= n; l++) {
            for (int r = 0; r <= n; r++) {
                if (dp[l][r] && r - l + 1 > ans) {
                    ans = r - l + 1;
                    start = l;
                }
            }
        }
        string result = "";
        for (int i = start; i < ans + start; i++) {
            result += s[i];
        }
        return result;
    }
};
