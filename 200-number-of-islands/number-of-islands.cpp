class Solution {
private:
    void dfs(int row,int col,vector<vector<int>>&visited,vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();


        // Check if the current cell is within the grid boundaries and not visited
        if (row < 0 || row >= n || col < 0 || col >= m || visited[row][col] || grid[row][col] == '0') {
            return;
        }
        // Mark the current cell as visited
        visited[row][col] = 1;

        int delRow[] = {1, -1, 0, 0};
        int delCol[] = {0, 0, -1, 1};
        // Explore only horizontally and vertically adjacent land cells
        for (int i = 0; i < 4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == '1' && visited[nRow][nCol] == 0) {
                dfs(nRow, nCol, visited, grid);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int component = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!visited[row][col] && grid[row][col] == '1') {
                    component++;
                    dfs(row, col, visited, grid);
                }
            }
        }
        return component;
    }

};