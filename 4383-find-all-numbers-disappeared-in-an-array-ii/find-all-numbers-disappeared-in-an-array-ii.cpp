class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        int low = lower;

        for(int i=0;i<nums.size();i++){
            if(nums[i]<lower || nums[i]>upper) continue;

            if(nums[i]>low){
                ans.push_back({low,nums[i]-1});
            }

            low = nums[i] + 1;
        }

        if(low<=upper) ans.push_back({low,upper});

        return ans;
    }
};