class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned long long> dp(amount + 1, 0);
        dp[0] = 1;
        for (int c : coins) {
            for (int am = c; am <= amount; am++) {
                dp[am] += dp[am - c];
            }
        }
        return dp[amount];
    }
};
