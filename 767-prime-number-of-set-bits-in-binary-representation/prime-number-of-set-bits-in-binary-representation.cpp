class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans =0;

        unordered_map<int,int> mp = {{2,1},{3,1},{5,1},{7,1},{11,1},{13,1},{17,1},{19,1}};

        for(int i=left;i<=right;i++){
            int count = __builtin_popcount(i);
            if(mp.find(count)!=mp.end()) ans++;
        }

        return ans;
    }
};