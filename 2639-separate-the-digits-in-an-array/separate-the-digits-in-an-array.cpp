class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;

        for(int i=0;i<nums.size();i++){
            string num = to_string(nums[i]);

            for(int i=0;i<num.size();i++){
                ans.push_back(num[i]-'0');
            }
        }

        return ans;
    }
};