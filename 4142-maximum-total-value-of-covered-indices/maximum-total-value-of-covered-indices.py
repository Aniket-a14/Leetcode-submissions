from typing import List

class Solution:
    def maxTotal(self, nums: List[int], s: str) -> int:
        n = len(nums)
        NEG = -10**18

        dp = [NEG, NEG]
        dp[1 if s[0] == '1' else 0] = 0

        for i in range(n):
            ndp = [NEG, NEG]

            nxt = 1 if (i + 1 < n and s[i + 1] == '1') else 0

            for cur in (0, 1):
                if dp[cur] == NEG:
                    continue

                ndp[nxt] = max(ndp[nxt], dp[cur])

                if cur:
                    ndp[nxt] = max(ndp[nxt], dp[cur] + nums[i])

                if nxt:
                    ndp[0] = max(ndp[0], dp[cur] + nums[i])

            dp = ndp

        return max(dp)