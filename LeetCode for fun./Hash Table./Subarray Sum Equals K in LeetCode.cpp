class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp; 
        mp[0] = 1;
        int currentSum = 0; 
        int res = 0;
        for (int i = 0; i < n; i++) {
            currentSum += nums[i];
            if (mp.count(currentSum - k)) {
                res += mp[currentSum - k];
            }
            mp[currentSum]++;
        }   
        return res; 
    }
};
