class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        if n <= 0 or n & (n - 1):
            return False
        cnt = 0
        while n:
            cnt += 1
            n = n >> 1
        return True if cnt % 2 == 1 else False