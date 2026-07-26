class Solution:
    def largestInteger(self, n: int, s: int) -> int:

        if n * 9 < s:
            return -1

        if s == 0:
            return 0

        ans = []

        for i in range(n):
            d = min(9, s)
            ans.append(str(d))
            s -= d

        return int("".join(ans))
