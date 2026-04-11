class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        if(nums.size()<=2) return -1;
        unordered_map<int, vector<int>> mp;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }

        int ans=INT_MAX;
        for(auto& [val, index]: mp){
            if(index.size()<3) continue;

            for (int i=0;i+2<index.size();i++) {
                int a = index[i];
                int b = index[i + 1];
                int c = index[i + 2];

                int dist = abs(a-b)+abs(b-c)+abs(c-a);
                ans = min(ans, dist);
            }
        }

        return (ans==INT_MAX)?-1:ans;
    }
};