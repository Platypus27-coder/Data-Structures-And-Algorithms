class Solution {
public:
    // solution_1
    bool canPartition_1(vector<int>& nums) {
        int total = 0;
        for (int n : nums) {
            total += n;
        }
        if (total % 2 != 0) {
            return false;
        }
        int target = total / 2;
        int n = nums.size();
        vector<bool> dp(target + 1, false);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int s = target; s >= nums[i]; s--) {
                if (dp[s - nums[i]]) {
                    dp[s] = true;
                }
            }
        }
        return dp[target];
    }

    // solution_2

    bool canPartition_2(vector<int>& nums) {
        int total = 0;
        for (int n : nums) {
            total += n;
        }
        if (total % 2 != 0) {
            return false;
        }
        int target = total / 2;
        int n = nums.size();
        vector<bool> dp(target + 1, false);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int s = target; s >= nums[i]; s--) {
                if (dp[s - nums[i]]) {
                    dp[s] = true;
                }
            }
        }
        return dp[target];
    }
};
