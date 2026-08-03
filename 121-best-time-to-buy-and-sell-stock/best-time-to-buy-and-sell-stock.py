class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mini = 1e9
        ans = 0

        for i in range(len(prices)):
            mini = min(mini,prices[i])
            ans = max(ans, prices[i] - mini)

        return ans
        