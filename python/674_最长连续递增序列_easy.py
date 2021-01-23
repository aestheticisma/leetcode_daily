class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        cur = 1
        res = 1
        for i in range(1, len(nums)):
            if nums[i] > nums[i-1]:
                cur += 1
            else:
                cur = 1
            res = max(res, cur)
        return res