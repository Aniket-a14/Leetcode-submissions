class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs.sort()
        add = 0
        ans = 0

        for i in range(len(costs)):
            add += costs[i]
            if add <= coins:
                ans+=1
            else:
                break

        return ans

        