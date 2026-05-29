class Solution {
public:
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;

        for(int num: nums){
            string temp = to_string(num);
            int count = 0;

            for(int i=0;i<temp.size();i++){
                count += temp[i]-'0';
            }

            mini = min(mini,count);
        }

        return mini;
    }
};