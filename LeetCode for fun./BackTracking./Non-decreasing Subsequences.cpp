class Solution {
public:
    bool check(vector<int> tmp) {
        if (tmp.size() < 2) return false;
        for (int i = 1; i < tmp.size(); i++) {
            if (tmp[i] < tmp[i - 1]) 
                return false;
        }
        return true;
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> unique;
        vector<vector<int>> result;
        int n = nums.size();
        int total = (1 << n);
        for (int i = 0; i < total; i++) {
            vector<int> tmp;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    tmp.push_back(nums[j]);
                }
            }
            if (check(tmp)) unique.insert(tmp);
        }
        for(auto sub : unique) {
            result.push_back(sub);
        }
        return result;
    }
};
