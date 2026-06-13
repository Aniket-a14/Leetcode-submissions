from typing import List

class Solution:
    def mapWordWeights(self, words: List[str], weights: List[int]) -> str:
        ans = []

        for word in words:
            s = 0

            for ch in word:
                s = (s + weights[ord(ch) - ord('a')]) % 26

            ans.append(chr(ord('a') + (25 - s)))

        return "".join(ans)