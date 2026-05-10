class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> dp(nums.size(),-1);
        dp[0] = 0;

        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(abs(nums[i]-nums[j])<=target && dp[j]!=-1){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }

        return dp[nums.size()-1];
    }
};