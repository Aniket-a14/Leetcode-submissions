class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int left = 0;
        int right = colors.size()-1;

        int ans = INT_MIN;

        while(left<right){
            if(colors[left]!=colors[right]){
                ans =  max(ans,abs(right-left));
                break;
            }else{
                right--;
            }
        }

        left = 0;
        right = colors.size()-1;
        while(left<right){
            if(colors[left]!=colors[right]){
                ans =  max(ans,abs(right-left));
                break;
            }else{
                left++;
            }
        }
        
        return ans;
    }
};