class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        

        for i in range(n,n+11):
            num = i
            mul = 1

            while num > 0:
                r = num%10
                mul = mul * r
                num = num//10

            if mul%t==0:
                return i
        