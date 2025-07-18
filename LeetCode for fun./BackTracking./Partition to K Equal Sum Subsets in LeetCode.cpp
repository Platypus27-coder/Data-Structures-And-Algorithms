class Solution {
public:
    bool used[10001];

    bool backtrack(int i, vector<int> &nums, int k, int subsetSum, int target) {
        if (k == 0) {
            return true;
        }
        if (subsetSum == target) {
            return backtrack(0, nums, k - 1, 0, target);
        }
        for (int j = i; j < nums.size(); j++) {
            if (used[j] == true || subsetSum + nums[j] > target) {
                continue;
            }
            used[j] = true;
            if (backtrack(j + 1, nums, k, subsetSum + nums[j], target)) return true;
            used[j] = false;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int n : nums) {
            sum += n;
        }   
        int target = sum / k;
        if (sum % k != 0) {
            return false;
        }
        return backtrack(0, nums, k, 0, target);
    }
};
