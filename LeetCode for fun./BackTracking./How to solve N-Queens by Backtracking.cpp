int is_safe(int **board, int i, int j, int n) {
    int j_left = j; 
    int j_right = j; 
    while(i >= 0) {
        if ((j_left >= 0 && board[i][j_left] == 1) || (j_right < n && board[i][j_right] == 1) || board[i][j] == 1) {
            return 0; 
        }
        --i; ++j_right; --j_left; 
    }
    return 1; 
}

void add_solution(int **board, int n, char ***result, int *returnSize, int **returnColumnSizes) {
    char **solution = (char **)malloc(n  * sizeof(char *)); 
    for (int i = 0; i < n; i++) {
        solution[i] = (char *)malloc((n + 1) * sizeof(char)); 
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1) {
                solution[i][j] = 'Q'; 
            }
            else {
                solution[i][j] = '.'; 
            }
        }
        solution[i][n] = '\0'; 
    }
    result[*returnSize] = solution; 
    (*returnColumnSizes)[*returnSize] = n; 
    ++(*returnSize); 
}

void solve(int **board, int i, int n, char ***result, int *returnSize, int **returnColumnSizes) {
    if (i == n) {
        add_solution(board, n, result, returnSize, returnColumnSizes); 
        return; 
    }
    else {
        for (int j = 0; j < n; j++) {
            if (is_safe(board, i, j, n)) {
                board[i][j] = 1; 
                solve(board, i + 1, n, result, returnSize, returnColumnSizes); 
                board[i][j] = 0; 
            }
        }
    }
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    char ***result = (char ***)malloc(352 * sizeof(char **)); 
    *returnSize = 0; 
    *returnColumnSizes = (int *)malloc(352 * sizeof(int));
    int **board = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        board[i] = (int *)malloc(n * sizeof(int)); 
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 0; 
        }
    }
    solve(board, 0, n, result, returnSize, returnColumnSizes); 
    for (int i = 0; i < n; i++) {
        free(board[i]); 
    }
    free(board); 
    return result; 
}
