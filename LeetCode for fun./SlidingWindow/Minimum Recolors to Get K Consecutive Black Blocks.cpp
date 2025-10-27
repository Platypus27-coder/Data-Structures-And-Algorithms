class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int ans = 0;
        int res = INT_MAX;
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') {
                ++ans;
            }
        }
        res = min(res, ans);
        for (int i = 1; i <= n - k; i++) {
            if (blocks[i - 1] == 'W') {
                --ans;
            }
            if (blocks[i + k - 1] == 'W') {
                ++ans;
            }
            res = min(ans, res);
        }
        return res;
    }
};
