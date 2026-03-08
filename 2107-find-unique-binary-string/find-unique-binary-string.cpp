class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";

        for(int i=0;i<nums.size();i++){
            string word = nums[i];
            ans += (word[i]=='1')?'0':'1';
        }

        return ans;
    }
};