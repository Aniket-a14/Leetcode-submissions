class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, -1));
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;

                if (i + 1 == j) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (dp[0][i] == true) {
                ans[i] = 0;
            } else {
                ans[i] = INT_MAX;
                for (int k = 0; k < i; k++) {
                    if (dp[k + 1][i] == true && 1 + ans[k] < ans[i]) {
                        ans[i] = 1 + ans[k];
                    }
                }
            }
        }

        return ans[n - 1];
    }
};