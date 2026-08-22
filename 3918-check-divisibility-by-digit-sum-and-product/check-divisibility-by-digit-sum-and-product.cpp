class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int mul = 1;

        int num = n;

        while(num>0){
            int r = num % 10;
            sum += r;
            mul *= r;
            num/=10;
        }

        return n%(sum+mul)==0?true:false;
    }
};