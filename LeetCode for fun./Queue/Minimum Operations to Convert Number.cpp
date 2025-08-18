class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<pair<int, int>> q;
        int n = nums.size();
        vector<bool> used(1001, false);
        q.push({start, 0});
        while(!q.empty()) {
            pair<int, int> x = q.front();
            q.pop();

            if (x.first == goal) {
                return x.second;
            }
            for (int i = 0; i < n; i++) {
                int add = x.first + nums[i];
                int sub = x.first - nums[i];
                int xo  = x.first ^ nums[i];
                if (add == goal || sub == goal || xo == goal) return x.second + 1;
                if (add >= 0 && add <= 1000 && !used[add]) {
                    used[x.first + nums[i]] = true;
                    q.push({x.first + nums[i], x.second + 1});
                }
                if (sub >= 0 && sub <= 1000 && !used[sub]) {
                    used[x.first - nums[i]] = true;
                    q.push({x.first - nums[i], x.second + 1});
                }
                if (xo >= 0 && xo <= 1000 && !used[xo]) {
                    used[x.first ^ nums[i]] = true;
                    q.push({x.first ^ nums[i], x.second + 1});
                }
            }
        }
        return -1;
    }
};
