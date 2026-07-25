class Solution:
    def maxProduct(self, n: int) -> int:
        maxi_1 = maxi_2 = -1

        while n > 0:
            d = n % 10
            if d > maxi_1:
                maxi_2 = maxi_1
                maxi_1 = d
            elif d > maxi_2:
                maxi_2 = d

            n = n // 10

        return maxi_1 * maxi_2
