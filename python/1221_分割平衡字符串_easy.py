class Solution:
    def balancedStringSplit(self, s: str) -> int:
        ans = 0
        i, j = 0, 0
        for ch in s:
            if ch == 'R':
                i += 1
            else:
                j += 1
            if i == j:
                i, j = 0, 0
                ans += 1
        return ans