class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        if(nums.size()<=2) return -1;
        int ans=INT_MAX;

        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    if(nums[i]==nums[j] && nums[j]==nums[k] && nums[k]==nums[i]){
                        ans=min(ans,abs(i-j)+abs(j-k)+abs(k-i));
                    }
                }
            }
        }

        return (ans==INT_MAX)?-1:ans;
    }
};