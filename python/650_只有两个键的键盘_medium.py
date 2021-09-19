class Solution:
    def minSteps(self, n: int) -> int:
        dp = [0] * (n+1)
        for i in range(2, n+1):
            dp[i] = float("+inf")
            j = 1
            while j*j <= i:
                mod = i % j
                if mod == 0:
                    x = i // j
                    dp[i] = min([dp[i], dp[j]+x, dp[x]+j])
                j += 1
        return dp[n]