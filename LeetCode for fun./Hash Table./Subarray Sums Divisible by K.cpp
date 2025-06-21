class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int cnt = 0, sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int remain = sum % k;
            if (remain < 0) remain += k;
            if(mp.find(remain) != mp.end()) {
                cnt += mp[remain];
            }
            mp[remain]++;
        }
        return cnt; 
    }
};
