class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> maxi(nums.size(),-1);
        vector<int> mini(nums.size(),INT_MAX);

        maxi[0] = nums[0];

        for(int i=1;i<nums.size();i++){
            maxi[i] = max(maxi[i-1],nums[i]);
        }

        mini[nums.size()-1] = nums[nums.size()-1];

        for(int i=nums.size()-2;i>=0;i--){
            mini[i] = min(nums[i],mini[i+1]);
        }

        int ans = -1;
        int diff = 0;

        for(int i=0;i<nums.size();i++){
            int m = maxi[i];
            int n = mini[i];

            diff = m-n;
            if(diff<=k) return i;
        }

        return -1;
    }
};