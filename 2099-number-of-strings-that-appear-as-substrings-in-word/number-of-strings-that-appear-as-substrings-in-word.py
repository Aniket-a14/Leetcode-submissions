class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        ans = 0

        for char in patterns:
            if char in word:
                ans+=1

        return ans
        