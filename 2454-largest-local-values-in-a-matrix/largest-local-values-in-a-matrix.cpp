class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> result(row - 2, vector<int>(col - 2, 0));

        for (int i = 1; i < row - 1; i++) {
            for (int j = 1; j < col - 1; j++) {
                int max_value = grid[i][j]; // Initialize with center cell
                for (int r = i - 1; r <= i + 1; r++) {
                    for (int c = j - 1; c <= j + 1; c++) {
                        max_value = max(max_value, grid[r][c]);
                    }
                }
                result[i - 1][j - 1] = max_value;
            }
        }

        return result;
    }
};