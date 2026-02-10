class Solution {
public:
    vector<vector<int>> dp;
    int solve(int e,int f){
        if(e==1 || f<=1) return f;

        if(dp[e][f]!=-1) return dp[e][f];

        int ans = INT_MAX;
        int start = 1; int end = f;

        while(start<=end){
            int mid = start + (end-start)/2;

            int c1 = solve(e-1,mid-1);
            int c2 = solve(e,f-mid);

            ans = min(ans, 1 + max(c1,c2));
            if(c1>=c2){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }

        return dp[e][f] = ans;
    }
    int superEggDrop(int k, int n) {
        dp.assign(k+1,vector<int>(n+1,-1));
        return solve(k,n);
    }
};