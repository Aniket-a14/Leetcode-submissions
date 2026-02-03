class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& candidates, int target, int sum,vector<int>& temp,int idx){
        if(sum==target){
            ans.push_back(temp);
            return;
        }

        for(int i=idx;i<candidates.size();i++){
            if(candidates[i]+sum<=target){
                temp.push_back(candidates[i]);
                solve(candidates,target,sum+candidates[i],temp,i);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        solve(candidates,target,0,temp,0);
        return ans;
    }
};