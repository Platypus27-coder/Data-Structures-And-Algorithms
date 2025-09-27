class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int DP[3000];
        for (int i = 0; i < n; i++) {
            DP[i] = 1;
        }
        int result = INT_MIN;
        for (int i = 0; i < n; i++) {
            int dp = 0;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp = max(dp, DP[j]);
                }
            }
            DP[i] += dp;
        }
        for (int i = 0; i < n; i++) {
            result = max(DP[i], result);
        }
        return result;
    }
};
