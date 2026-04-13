class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans = 0;

        for(int i=0;i<nums.size();i++){
            int num = nums[i];

            while(num!=0){
                int r = num%10;
                if(r==digit) ans++;
                num/=10;
            }
        }

        return ans;
    }
};