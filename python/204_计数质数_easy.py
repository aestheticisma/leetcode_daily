class Solution:
    def countPrimes(self, n: int) -> int:
        ans = 0
        a = [1]*n
        for i in range(2, n):
            if a[i]:
                ans += 1
                if i*i<n:
                    for i in range(i*i, n, i):
                        a[i] = 0
        return ans