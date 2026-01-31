class Solution {
public:
    int solve(int i, string &s, vector<int> &dp) {
        if (i <= 0) return 0;
        if (dp[i] != -1) return dp[i];

        int ans = 0;

        if (s[i] == ')') {
            if (s[i - 1] == '(') {
                ans = 2 + solve(i - 2, s, dp);
            } else if (s[i - 1] == ')') {
                int prevLen = solve(i - 1, s, dp);
                int j = i - prevLen - 1;
                if (j >= 0 && s[j] == '(') {
                    ans = prevLen + 2 + solve(j - 1, s, dp);
                }
            }
        }

        return dp[i] = ans;
    }

    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            maxLen = max(maxLen, solve(i, s, dp));
        }

        return maxLen;
    }
};
