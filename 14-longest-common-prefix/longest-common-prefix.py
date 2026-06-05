class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if(len(strs)<=1): 
            return strs[0]

        s = strs[0]
        ans = len(s)

        for i in range(1,len(strs)):
            temp = strs[i]
            j = 0

            while(j<len(s) and j<len(temp) and s[j]==temp[j]):
                j+=1
            
            ans=min(ans,j)

        return s[0:ans]
        