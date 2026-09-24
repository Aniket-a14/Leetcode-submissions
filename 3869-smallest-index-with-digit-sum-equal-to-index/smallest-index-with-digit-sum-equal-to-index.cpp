class Solution {
public:
    int add(int num){
        int ans = 0;

        while(num>0){
            int r = num%10;
            ans += r;
            num/=10;
        }

        return ans;
    }
    int smallestIndex(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++){
            if(add(nums[i])==i) return i;
        }

        return -1;
    }
};