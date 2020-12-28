class Solution:
    def minPatches(self, nums: List[int], n: int) -> int:
        length = len(nums)
        index, ans = 0, 0
        x = 1
        while x <= n:
            if index < length and nums[index] <= x:
                x += nums[index]
                index += 1
            else:
                x <<= 1
                ans += 1
        return ans