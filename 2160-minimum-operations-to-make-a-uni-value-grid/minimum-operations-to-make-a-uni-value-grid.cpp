class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> ans;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                ans.push_back(grid[i][j]);
            }
        }

        int rem=ans[0]%x;
        for(int i=0;i<ans.size();i++){
            if(rem!=ans[i]%x) return -1;
        }

        sort(ans.begin(),ans.end());

        int op=0;
        int median = ans[ans.size()/2];
        for(int i=0;i<ans.size();i++){
            op += abs(ans[i]-median)/x;
        }

        return op;
    }
};