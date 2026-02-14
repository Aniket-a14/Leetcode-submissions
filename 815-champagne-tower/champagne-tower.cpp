class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if(poured==0) return 0.0;

        vector<vector<double>> dp(101, vector<double>(101,0.0));
        dp[0][0] = poured;

        for(int i=0;i<=query_row;i++){
            for(int j = 0;j<=i;j++){
                double extra = (dp[i][j]-1)/2.0;

                if(extra>0){
                    dp[i+1][j] += extra;
                    dp[i+1][j+1] += extra;
                }
            }
        }

        return min(1.0,dp[query_row][query_glass]);
    }
};