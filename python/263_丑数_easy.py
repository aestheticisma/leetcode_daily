class Solution:
    def isUgly(self, n: int) -> bool:
        if not n:
            return False
        a = [2, 3, 5]
        for _a in a:
            while n % _a == 0:
                n //= _a
        return True if n == 1 else False