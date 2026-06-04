class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        left = 0
        freq = {}
        ans = 0
        maxi = 0

        for right in range(len(s)):
            freq[s[right]] = freq.get(s[right],0) + 1
            maxi = max(maxi,freq[s[right]])

            while right-left+1-maxi>k:
                freq[s[left]]-=1
                left += 1
            
            ans = max(ans,right-left+1)
        
        return ans
            

        