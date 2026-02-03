class Solution {
public:
    int partition_sum = 0;
    bool solve(vector<int>& nums, int k, int currsum, vector<bool>& vis, int idx){
        if(k==1) return true;

        if(currsum==partition_sum) return solve(nums,k-1,0,vis,0);

        for(int i=idx;i<nums.size();i++){
            if(nums[i]+currsum>partition_sum) break;
            if(vis[i]) continue;

            vis[i]=true;
            if(solve(nums,k,currsum+nums[i],vis,i+1)) return true;
            vis[i]=false;

            if(currsum==0) return false;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total_sum = accumulate(nums.begin(),nums.end(),0);
        partition_sum = total_sum/k;
        vector<bool> vis(nums.size(),false);
        sort(nums.begin(),nums.end());
        if(total_sum%k || nums[nums.size()-1]>partition_sum)return false;
        return solve(nums,k,0,vis,0);
    }
};