class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int ans = 0;
    int total = 0;

    void dfs(vector<vector<int>> &grid, int x, int y, int cnt, int m, int n) {
        if (grid[x][y] == 2) {
            if (cnt == total) {
                ++ans;
            }
            return;
        }
        int tmp = grid[x][y];
        grid[x][y] = -1;
        for (int k = 0; k < 4; k++) {
            int xo = x + dx[k];
            int yo = y + dy[k];
            if (xo >= 0 && xo < m && yo >= 0 && yo < n && grid[xo][yo] != -1) {
                dfs(grid, xo, yo, cnt + 1, m, n);
            }
        }
        grid[x][y] = tmp;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int startX = 0, startY = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != -1) {
                    ++total;
                }
                if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                }
            }
        }
        dfs(grid, startX, startY, 1, m, n);
        return ans;
    }
};
