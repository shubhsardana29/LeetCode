class Solution {
public:
    bool isSafe(vector<vector<int>>& grid, int i, int j) {
        int row = grid.size();
        int col = grid[0].size();
        return i >= 0 && i < row && j >= 0 && j < col && grid[i][j] == 1;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int perimeter = 0;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1) {
                    perimeter += 4;
                    if (i > 0 && isSafe(grid, i - 1, j)) {
                        perimeter -= 2;
                    }
                    if (j > 0 && isSafe(grid, i, j - 1)) {
                        perimeter -= 2;
                    }
                }
            }
        }

        return perimeter;
    }
};