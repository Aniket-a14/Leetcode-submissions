class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<vector<int>> events;

        for(int i=0;i<logs.size();i++){
            int start = logs[i][0];
            int end = logs[i][1];

            events.push_back({start,1});
            events.push_back({end,-1});
        }

        sort(events.begin(),events.end());

        int curr = 0;
        int maxi = 0;
        int year = 0;

        for(int i=0;i<events.size();i++){
            int y = events[i][0];
            int d = events[i][1];

            curr += d;
            if(curr>maxi){
                maxi = curr;
                year = y;
            }
        }
        return year;
    }
};