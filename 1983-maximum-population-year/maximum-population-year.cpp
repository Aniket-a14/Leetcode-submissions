class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> diff(2051,0);

        for(int i=0;i<logs.size();i++){
            int start = logs[i][0];
            int end = logs[i][1]-1;

            diff[start] += 1;
            if(end+1<2051) diff[end+1] -=1;
        }

        int ans = INT_MAX;
        int sum = 0;
        int temp = 0;

        for(int i=0;i<diff.size();i++){
            sum += diff[i];
            if(sum>temp){
                temp=sum;
                ans=i;
            }
        }

        return ans;
    }
};