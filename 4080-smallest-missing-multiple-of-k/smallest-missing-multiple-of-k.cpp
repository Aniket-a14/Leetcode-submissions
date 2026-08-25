class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> arr;

        for(int i=0;i<nums.size();i++){
            if(nums[i]%k==0) arr.push_back(nums[i]);
        }

        int num=k;
        sort(arr.begin(),arr.end());
        arr.erase(unique(arr.begin(), arr.end()), arr.end());

        for(int i=0;i<arr.size();i++){
            if(arr[i]!=num){
                return num;
            }
            num+=k;
        }
        return num;
    }
};