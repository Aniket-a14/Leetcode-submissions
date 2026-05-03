class Solution {
public:
    vector<int> prime;
    void seive(int n) {

        prime.assign(n + 1, true);
        prime[0] = prime[1] = false;
        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true) {

                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
    }
    int sumOfPrimesInRange(int n) {
        int reversed_number = 0, remainder;
        int start = n, end = n;
        while (n != 0) {
            remainder = n % 10;
            reversed_number = reversed_number * 10 + remainder;
            n /= 10;
        }

        start = min(start,reversed_number);
        end = max(end,reversed_number);

        seive(end);

        int ans = 0;
        for(int i=start;i<=end;i++){
            if(prime[i]) ans+=i;
        }
        return ans;
    }
};