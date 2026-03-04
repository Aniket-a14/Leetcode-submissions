class Solution {
public:
    int numSpecial(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> row(n, vector<int>(m, 0)),
            col(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            row[i][0] = matrix[i][0];
            for (int j = 1; j < m; j++) {
                row[i][j] = row[i][j - 1] + matrix[i][j];
            }
        }

        for (int i = 0; i < m; i++) {
            col[0][i] = matrix[0][i];
            for (int j = 1; j < n; j++) {
                col[j][i] = col[j - 1][i] + matrix[j][i];
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 1 && row[i][m - 1] == 1 &&
                    col[n - 1][j] == 1)
                    ans++;
            }
        }

        return ans;
    }
};