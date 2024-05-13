class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        for(int i = 0; i < row; i++) {
            if(grid[i][0] == 0) {
                for(int j = 0; j < col; j++) {
                    grid[i][j] ^= 1; // Flip
                }
            }
        }

        for(int j = 1; j < col; j++) {
            int onesCount = 0;
            for(int i = 0; i < row; i++) {
                onesCount += grid[i][j];
            }
            if(onesCount < row - onesCount) {
                for(int i = 0; i < row; i++) {
                    grid[i][j] ^= 1; // Flip
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                ans += grid[i][j] * (1 << (col - 1 - j));
            }
        }
        return ans;
    }
};
