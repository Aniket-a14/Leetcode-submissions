class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<long long,long long> mp;

        for(auto seg: segments){
            mp[seg[0]]+= seg[2];
            mp[seg[1]]-= seg[2];
        }

        vector<vector<long long>> ans;
        auto it = mp.begin();
        long long sum = it->second;
        long long start = it->first;
        it++;

        while(it!=mp.end()){
            if(sum>0) ans.push_back({start,it->first,sum});
            start = it->first;
            sum += it->second;
            it++;
        }

        return ans;
    }
};