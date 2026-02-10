class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& nums, int i,int j){
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int ans=0;
        for(int k=i;k<=j;k++){
            int c1 = solve(nums,i,k-1);
            int c2 = solve(nums,k+1,j);

            int c3 = nums[k]*nums[i-1]*nums[j+1];
            ans = max(ans,c1+c2+c3);
        }
        
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        dp.assign(nums.size()+2,vector<int>(nums.size()+2,-1));
        nums.insert(nums.begin(),1);
        nums.push_back(1);

        return solve(nums,1,nums.size()-2);
    }
};