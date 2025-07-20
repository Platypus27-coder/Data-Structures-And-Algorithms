class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        sort(nums.begin(), nums.end());
        vector<int> answer;
        vector<int> prefix(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) prefix[0] = nums[i];
            else prefix[i] = prefix[i - 1] + nums[i];
        }
        for (int i = 0; i < m; i++) {
            int l = 0, r = n - 1;
            while(l <= r) {
                int m = (l + r) / 2;
                if (prefix[m] <= queries[i]) {
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }
            answer.push_back(l);
        }
        return answer;
    }
};
