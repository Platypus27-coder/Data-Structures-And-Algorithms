// Given an integer array nums containing n integers, find the beauty of each subarray of size k.

// The beauty of a subarray is the xth smallest integer in the subarray if it is negative, or 0 if there are fewer than x negative integers.

// Return an integer array containing n - k + 1 integers, which denote the beauty of the subarrays in order from the first index in the array.

// A subarray is a contiguous non-empty sequence of elements within an array.

class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans(n - k + 1, 0);
        vector<int> counter(50, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                counter[nums[i] + 50]++;
            }
            if (i - k >= 0 && nums[i - k] < 0) {
                counter[nums[i - k] + 50]--;
            }
            if (i - k + 1 < 0) continue;
            int count = 0;
            for (int j = 0; j < 50; j++) {
                count += counter[j];
                if (count >= x) {
                    ans[i - k + 1] = j - 50;
                    break;
                }
            }
        }
        return ans;
    }
};

