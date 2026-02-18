class Solution {
public:
    void floodFill(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0' || visited[i][j]) 
            return;

        visited[i][j] = true;
        floodFill(i + 1, j, grid, visited);
        floodFill(i - 1, j, grid, visited);
        floodFill(i, j + 1, grid, visited);
        floodFill(i, j - 1, grid, visited);

    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1' && visited[i][j] == false) {
                    floodFill(i, j, grid, visited);
                    cnt += 1;
                }
            }
        }
        
        return cnt;
    }
};