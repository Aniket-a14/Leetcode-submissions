class Solution {
public:
    int binaryGap(int n) {
        int len = (int)(log2(n));

        string ans = bitset<64>(n).to_string().substr(64 - len - 1);

        cout<<ans<<endl;
        int count = 0;
        int maxi = 0;

        for(int i=0;i<ans.size();i++){
            if(ans[i]=='0'){
                count++;
            }else{
                maxi=max(maxi,count);
                count=1;
            }
        }

        return maxi;
    }
};