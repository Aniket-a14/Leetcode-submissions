class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        abc = [-1,-1,-1]
        ans = 0

        for right in range(len(s)):
            abc[ord(s[right]) - ord('a')] = right

            min_index = min(abc)
            ans += min_index + 1
        
        return ans
        