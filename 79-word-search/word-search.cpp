class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, i, j, word, 0))
                        return true;
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int index) {
        if (index == word.length())
            return true;

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index])
            return false;

        char temp = board[i][j];
        board[i][j] = '@'; // Mark as visited

        bool found = dfs(board, i + 1, j, word, index + 1) ||
                     dfs(board, i - 1, j, word, index + 1) ||
                     dfs(board, i, j + 1, word, index + 1) ||
                     dfs(board, i, j - 1, word, index + 1);

        board[i][j] = temp; // Restore the cell

        return found;
    }
};