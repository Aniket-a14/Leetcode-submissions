class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<int,long long> mp;

        for(int i=0;i<segments.size();i++){
            mp[segments[i][0]] += segments[i][2];
            mp[segments[i][1]] -= segments[i][2];
        }

        auto it = mp.begin();
        long long sum = it->second;
        long long start = it->first;
        vector<vector<long long>> ans;
        it++;

        while(it!=mp.end()){
            if(sum>0){
                ans.push_back({start,it->first,sum});
            }
            start = it->first;
            sum+= it->second;
            it++;
        }

        return ans;
    }
};