class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n,0);
        vector<int> ans(n,0);

        for(int i=0;i<bookings.size();i++){
            int first = bookings[i][0]-1;
            int last = bookings[i][1]-1;
            int seats = bookings[i][2];

            diff[first]+=seats;
            if(last+1<n){
                diff[last+1]-=seats;
            }
        }

        int sum = 0;
        for(int i=0;i<n;i++){
            sum+= diff[i];
            ans[i]= sum;
        }

        return ans;
    }
};