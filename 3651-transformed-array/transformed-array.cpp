class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(nums.size(),0);

        for(int i=0;i<n;i++){
            int steps = nums[i]%n;
            int num = (i+steps+n)%n;
            result[i]=nums[num];
        }
        return result;
    }
};