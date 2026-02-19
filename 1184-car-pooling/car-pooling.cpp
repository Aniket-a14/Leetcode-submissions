class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> mp;

        for(int i=0;i<trips.size();i++){
            mp[trips[i][1]] += trips[i][0];
            mp[trips[i][2]] -= trips[i][0];
        }

        int count = 0;
        for(auto it: mp){
            count += it.second;
            if(count>capacity) return false;
        }

        return true;
    }
};