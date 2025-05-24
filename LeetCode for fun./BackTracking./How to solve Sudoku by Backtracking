int is_valid(char **board, int boardSize, int *boardColSize, int row, int col, int num) {
    for (int i = 0; i < boardSize; i++) {
        if (board[i][col] - '0' == num) 
            return 0; 
    }
    for (int i = 0; i < boardColSize[0]; i++) {
        if (board[row][i] - '0' == num) {
            return 0; 
        }
    }
    int R = (row / 3) * 3; 
    int C = (col / 3) * 3; 
    for (int i = R; i < R + 3; i++) {
        for (int j = C; j < C + 3; j++) {
            if (board[i][j] - '0' == num) {
                return 0; 
            }
        }
    }
    return 1; 
}

int solve(char **board, int boardSize, int *boardColSize, int r, int c) {
    if (r == 9)   
        return true; 
    else if (c == 9) {
        return solve(board, boardSize, boardColSize, r + 1, 0); 
    }
    else if (board[r][c] != '.') {
        return solve(board, boardSize, boardColSize, r, c + 1); 
    }
    else {
        for (int num = 1; num <= 9; num++) {
            if (is_valid(board, boardSize, boardColSize, r, c, num)) {
                board[r][c] = num + '0'; 
                if (solve(board, boardSize, boardColSize, r, c + 1)) {
                    return 1; 
                }
                board[r][c] = '.'; 
            }
        }
    }
    return 0; 
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
    solve(board, boardSize, boardColSize, 0, 0); 
}
