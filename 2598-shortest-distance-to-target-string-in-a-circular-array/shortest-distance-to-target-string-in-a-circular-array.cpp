class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans = INT_MAX;
        int n = words.size();
        int idx = startIndex+1%n;
        int i = 1;

        if(words[startIndex]==target) return 0;

        while(idx!=startIndex){
            if(words[idx]==target){
                ans = min(ans,i);
                break;
            }
            i++;
            idx = (idx + 1) % n;
        }

        idx = (startIndex-1+n)%n;
        i = 1;
        while(idx!=startIndex){
            if(words[idx]==target){
                ans = min(ans,i);
                break;
            }
            i++;
            idx = (idx - 1 + n)%n;
        }
    
        return ans==INT_MAX?-1:ans;
    }
};