class Solution:
    def fib(self, n: int) -> int:
        MOD = 10**9 + 7
        if n < 2:
            return n
        x, y, z = 0, 0, 1
        for i in range(2, n+1):
            x, y = y, z
            z = (x + y) % MOD
        return z