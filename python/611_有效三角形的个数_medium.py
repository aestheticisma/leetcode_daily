class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        n = len(nums)
        nums.sort()
        ans = 0
        for i in range(0, n-2):
            k = i+1
            for j in range(i+1, n-1):
                while k+1 < n and nums[k+1] < nums[i] + nums[j]:
                    k += 1
                ans += max(k-j, 0)
        return ans