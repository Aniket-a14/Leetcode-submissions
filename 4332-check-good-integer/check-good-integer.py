class Solution:
    def checkGoodInteger(self, n: int) -> bool:
        digit = 0
        square = 0

        while n != 0:
            r = n % 10
            digit += r
            square += r * r
            n //= 10

        return square - digit >= 50