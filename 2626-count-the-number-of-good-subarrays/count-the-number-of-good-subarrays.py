class Solution:
    def countGood(self, nums: List[int], k: int) -> int:
        mp = {}
        left = 0
        ans = 0
        pairs = 0

        for right in range(len(nums)):
            pairs += mp.get(nums[right], 0)
            mp[nums[right]] = mp.get(nums[right], 0) + 1

            while pairs >= k:
                pairs -= mp[nums[left]] - 1
                mp[nums[left]] -= 1
                left += 1
                ans += len(nums) - right

        return ans
