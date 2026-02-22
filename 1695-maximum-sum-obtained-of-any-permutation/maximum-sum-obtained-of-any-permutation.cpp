class Solution {
public:
    int mod = 1e9+7;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        vector<int> events(nums.size(),0);

        for(auto req: requests){
            events[req[0]]++;
            if(req[1]+1<nums.size()) events[req[1]+1]--;
        }

        for(int i=1;i<nums.size();i++){
            events[i] += events[i-1];
        }

        int ans = 0;

        sort(events.begin(),events.end(), greater<int>());
        sort(nums.begin(),nums.end(), greater<int>());

        for(int i=0;i<nums.size();i++){
            ans = (ans + (1LL * nums[i]*events[i])%mod)%mod;
        }

        return ans;
    }
};