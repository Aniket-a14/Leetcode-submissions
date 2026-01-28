class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate=0,count=0,votes=0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                candidate=nums[i];
                count=1;
            }
            else{
                if(nums[i]==candidate){
                    count++;
                }
                else{
                    count--;
                }
            }
        }
        for(int i=0;i<nums.size();i++){
            if(candidate==nums[i]){
                votes++;
            }
        }
        if(votes>nums.size()/2){
            return candidate;
        }
        else{
            return -1;
        }
    }
};