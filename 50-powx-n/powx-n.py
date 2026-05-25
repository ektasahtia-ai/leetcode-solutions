class Solution:
    def myPow(self, x, n):

        def power(x, n):
            if n == 0:
                return 1

            half = power(x, n // 2)

            if n % 2 == 0:
                return half * half
            else:
                return half * half * x

        # Handle negative powers
        if n < 0:
            x = 1 / x
            n = -n

        return power(x, n)