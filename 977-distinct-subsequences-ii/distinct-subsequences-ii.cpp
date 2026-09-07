class Solution {
public:
    const long long MOD = 1e9 + 7;

    vector<int> prev;
    vector<long long> dp;

    long long solve(int n) {
        if (n == 0)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        long long total = (2LL * solve(n - 1)) % MOD;
        if (prev[n - 1] != -1) {
            total = (total - solve(prev[n - 1]) + MOD) % MOD;
        }

        return dp[n] = total;
    }

    int distinctSubseqII(string s) {
        int n = s.size();

        prev.resize(n, -1);
        vector<int> last(26, -1);

        for (int i = 0; i < n; i++) {
            prev[i] = last[s[i] - 'a'];
            last[s[i] - 'a'] = i;
        }

        dp.assign(n + 1, -1);

        return (solve(n) - 1 + MOD) % MOD;
    }
};