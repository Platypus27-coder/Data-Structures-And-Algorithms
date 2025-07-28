class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // dp(a) la so to tien nho nhat khi doi to tien thu i 
        vector<int> dp(amount + 1, 1e9);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int a = coins[i - 1]; a <= amount; a++) {
                dp[a] = min(dp[a], dp[a - coins[i - 1]] + 1);
            }
        }
        if (dp[amount] == 1e9) {
            return -1;
        }
        return dp[amount];
    }
};
