class Solution {
public:
    static const int mod = 1e9 + 7;

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();

        for (int i = 0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            int v = queries[i][3];

            long long mul = v;  

            for (int j = l; j <= r; j += k) {
                nums[j] = (nums[j] * mul) % mod;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans ^= nums[i];
        }

        return ans;
    }
};