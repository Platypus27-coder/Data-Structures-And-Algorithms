class Solution {
public:
    vector<vector<bool>> visited;
    
    bool backtrack(vector<vector<char>> &board, string word, int idx, int i, int j, int m, int n) {
        if (board[i][j] != word[idx]) return false;
        if (idx == word.size() - 1) return true;
        visited[i][j] = true;
        if (i + 1 < m && visited[i + 1][j] == false) {
            if (backtrack(board, word, idx + 1, i + 1, j, m, n)) return true;
        }
        if (j + 1 < n && visited[i][j + 1] == false) {
            if (backtrack(board, word, idx + 1, i, j + 1, m, n)) return true;
        }
        if (j - 1 >= 0 && visited[i][j - 1] == false) {
            if (backtrack(board, word, idx + 1, i, j - 1, m, n)) return true;
        }
        if (i - 1 >= 0 && visited[i - 1][j] == false) {
            if (backtrack(board, word, idx + 1, i - 1, j, m, n)) return true;
        }
        visited[i][j] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        visited.assign(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (backtrack(board, word, 0, i, j, m, n)) return true;
                }
            }
        }
        return false;
    }
};
