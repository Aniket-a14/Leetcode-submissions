class Solution:
    def sumOfGoodIntegers(self, n: int, k: int) -> int:
        start = max(1,n-k)
        end = n+k
        ans = 0

        for i in range(start,end+1):
            ans += i if i&n==0 else 0

        return ans