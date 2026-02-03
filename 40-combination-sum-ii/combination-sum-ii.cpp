class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& candidates, int target, int sum, int idx, vector<int>& temp,unordered_map<int,int>& mp){
        if(sum==target){
            ans.push_back(temp);
            return;
        }

        for(int i=idx;i<candidates.size();i++){
            if (i > idx && candidates[i] == candidates[i - 1]) continue;

            if (sum + candidates[i] > target) break;

            if(mp[candidates[i]]>0){
                temp.push_back(candidates[i]);
                mp[candidates[i]]--;
                solve(candidates,target,sum+candidates[i],i,temp,mp);
                temp.pop_back();
                mp[candidates[i]]++;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); 
        vector<int> temp;
        unordered_map<int,int> mp;
        for(int x:candidates) mp[x]++;
        solve(candidates,target,0,0,temp,mp);
        return ans;
    }
};