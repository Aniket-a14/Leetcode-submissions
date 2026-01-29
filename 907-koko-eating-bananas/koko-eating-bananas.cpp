class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int left=1;
        long long int right= *max_element(piles.begin(),piles.end());
        long long int ans=0;

        while(left<=right){
            long long int mid = left + (right-left)/2;
            long long int hours=0;
            for(int i=0;i<piles.size();i++){
                hours += (piles[i]+ mid-1)/mid;
            }
            if(hours<=h){
                ans=mid;
                right= mid-1;
            }else{
                left = mid+1;
            }
        }
        return ans;
    }
};