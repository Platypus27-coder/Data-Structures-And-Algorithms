class Solution {
public:
    bool canSplit(vector<int> &nums, int largest, int k) {
        int subarray = 0;
        int currentSum = 0;
        for(int n : nums) {
            currentSum += n;
            if (currentSum > largest) {
                ++subarray;
                currentSum = n;
            }
        }
        return subarray + 1 <= k; 
    }
    int splitArray(vector<int>& nums, int k) {
        int l = nums[0];
        int r = 0;
        for (int n : nums) {
            if (l < n) {
                l = n;
            }
            r += n;
        }
        int res = r; 
        while(l <= r) {
            int m = (l + r) / 2;
            if (canSplit(nums, m, k)) {
                res = m; 
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return res; 
    }
};
