class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        if c % 4 == 3:
            return False
        base = 2
        while base * base <= c:
            if c % base:
                base += 1
                continue
            exp = 0
            while c % base == 0:
                c //= base
                exp += 1
            if base % 4 == 3 and exp % 2:
                return False
            base += 1
        return c % 4 != 3