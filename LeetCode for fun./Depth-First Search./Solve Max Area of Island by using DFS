int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void visit(int **grid, int m, int n, int i, int j, int *res) {
    grid[i][j] = 0; 
    for (int k = 0; k < 4; k++) {
        int i1 = i + dx[k], j1 = j + dy[k];
        if (i1 < m && i1 >= 0 && j1 < n && j1 >= 0 && grid[i1][j1] == 1) {
            ++(*res); 
            visit(grid, m, n, i1, j1, res); 
        }
    }
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0]; 
    int Area = 0; 
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                int res = 1; 
                visit(grid, m, n, i, j, &res); 
                if (res > Area) {
                    Area = res; 
                }
            }
        }
    }
    return Area; 
}
