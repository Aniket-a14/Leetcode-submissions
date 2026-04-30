class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        
        vector<vector<int>> prev(n, vector<int>(k + 1, -1));
        vector<vector<int>> curr(n, vector<int>(k + 1, -1));

        auto cellScore = [](int v){ return v == 2 ? 2 : (v == 1 ? 1 : 0); };
        auto cellCost  = [](int v){ return (v == 1 || v == 2) ? 1 : 0; };


        int s0 = cellScore(grid[0][0]);
        int c0 = cellCost(grid[0][0]);
        if (c0 <= k) curr[0][c0] = s0;

        for (int j = 1; j < n; ++j) {
            int s = cellScore(grid[0][j]);
            int co = cellCost(grid[0][j]);
            for (int cost = co; cost <= k; ++cost) {
                if (curr[j-1][cost - co] != -1) {
                    curr[j][cost] = max(curr[j][cost], curr[j-1][cost - co] + s);
                }
            }
        }
        prev = curr;
        for (auto &row : curr) fill(row.begin(), row.end(), -1);

        for (int i = 1; i < m; ++i) {
            int s = cellScore(grid[i][0]);
            int co = cellCost(grid[i][0]);
            for (int cost = co; cost <= k; ++cost) {
                if (prev[0][cost - co] != -1) {
                    curr[0][cost] = max(curr[0][cost], prev[0][cost - co] + s);
                }
            }

            
            for (int j = 1; j < n; ++j) {
                int sc = cellScore(grid[i][j]);
                int cc = cellCost(grid[i][j]);
                for (int cost = cc; cost <= k; ++cost) {
                    int best = -1;
                    if (prev[j][cost - cc] != -1)
                        best = max(best, prev[j][cost - cc] + sc);
                    if (curr[j-1][cost - cc] != -1)
                        best = max(best, curr[j-1][cost - cc] + sc);
                    curr[j][cost] = best;
                }
            }

            prev = curr;
            for (auto &row : curr) fill(row.begin(), row.end(), -1);
        }

    
        int ans = -1;
        for (int cost = 0; cost <= k; ++cost)
            ans = max(ans, prev[n-1][cost]);
        return ans;
    }
};
