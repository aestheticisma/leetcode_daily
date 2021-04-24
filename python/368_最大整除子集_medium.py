class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        n, maxSize, maxVal = len(nums), 1, nums[0]
        if n == 1:
            return [nums[0]]
        nums.sort()
        dp = [1] * n
        for i in range(1, n):
            for j in range(i):
                if nums[i] % nums[j] == 0:
                    dp[i] = max(dp[i], dp[j]+1)
            if dp[i] > maxSize:
                maxSize = dp[i]
                maxVal = nums[i]
        ans = list()
        for i in range(n-1, -1, -1):
            if maxSize < 1:
                break
            if dp[i] == maxSize and maxVal % nums[i] == 0:
                ans.append(nums[i])
                maxSize -= 1
                maxVal = nums[i]
        return ans