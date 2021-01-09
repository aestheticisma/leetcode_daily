class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if not nums:
            return nums
        i = 0
        res = []
        while i<len(nums):
            start = end = nums[i]
            while i+1<len(nums) and nums[i+1] == end+1:
                end += 1
                i += 1
            res.append(str(start) if start==end else str(start)+'->'+str(end))
            i += 1
        return res