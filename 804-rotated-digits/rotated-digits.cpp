class Solution {
public:
    bool digit(int n){
        bool valid = true;
        bool changed = false;
        
        while(n>0 && valid){
            int rem = n%10;
            if(rem==3 || rem==4 || rem==7) valid = false;
            else if(rem==2 || rem==5 || rem==6 ||rem==9) changed = true;
            n/=10;
        }

        return valid && changed;
    }
    int rotatedDigits(int n) {
        int ans = 0;

        for(int i=1;i<=n;i++){
            if(digit(i)){
                ans++;
            }
        }

        return ans;
    }
};