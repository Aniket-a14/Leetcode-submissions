class Solution {
    public int minMoves(int[] nums) {
        int maxi = -1;

        for(int i=0;i<nums.length;i++){
            if(nums[i]>maxi){
                maxi = nums[i];
            }
        }

        int ans = 0;

        for(int i=0;i<nums.length;i++){
            int move = maxi - nums[i];
            ans = ans + move;
        }

        return ans;
    }
}