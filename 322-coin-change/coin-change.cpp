class Solution {
public:
    vector<vector<int>> dp;
    int solve(int idx,int target,vector<int>& coins){
        if(target==0) return 0;
        if(idx==coins.size()) return 1e9;

        if(dp[idx][target]!=-1) return dp[idx][target];

        int pick = 1e9;
        if(coins[idx]<=target) pick= 1+ solve(idx,target-coins[idx],coins);

        int skip = solve(idx+1,target,coins);

        return dp[idx][target] = min(pick,skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.assign(coins.size(),vector<int>(amount+1,-1));
        return solve(0,amount,coins)==1e9?-1:solve(0,amount,coins);
    }
};