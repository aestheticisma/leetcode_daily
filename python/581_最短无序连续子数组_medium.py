class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        left, minn = -1, float('inf')
        right, maxn = -1, float('-inf')
        n = len(nums)
        for i in range(n):
            if maxn > nums[i]:
                right = i
            else:
                maxn = nums[i]
            if minn < nums[n-i-1]:
                left = n-i-1
            else:
                minn = nums[n-i-1]
        return 0 if right == -1 else right - left + 1