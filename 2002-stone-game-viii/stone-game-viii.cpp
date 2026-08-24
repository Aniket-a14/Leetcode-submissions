class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        
        for(int i=1;i<stones.size();i++){
            stones[i] = stones[i] + stones[i-1];
        }

        int ans = stones.back();

        for(int i=stones.size()-2;i>0;i--){
            ans = max(ans,stones[i]-ans);
        }

        return ans;
    }
};