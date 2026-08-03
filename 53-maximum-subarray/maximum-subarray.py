class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        count = 0
        maxi = -1e6

        for i in range(len(nums)):
            count += nums[i]
            maxi = max(maxi,count)
            if count < 0:
                count = 0

        return maxi
        