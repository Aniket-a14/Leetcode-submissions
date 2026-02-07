class Solution {
public:
    int minimumDeletions(string s) {
        int count = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                count++;
            }
        }

        int ans = count;
        int count_b = 0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='a') count--;
            else count_b++;

            ans=min(ans,count+count_b);
        }

        return ans;
    }
};