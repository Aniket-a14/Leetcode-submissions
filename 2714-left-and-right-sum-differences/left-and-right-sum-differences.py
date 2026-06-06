class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans, left, right = [0] * n, [0] * n, [0] * n

        for i in range(1,n):
            left[i] = left[i-1] + nums[i-1]

        for i in range(n-2,-1,-1):
            right[i] = right[i+1] + nums[i+1]

        for i in range(n):
            ans[i] = abs(left[i]-right[i])

        return ans
