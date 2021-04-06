class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n, j = len(nums), 2
        if n <= 2:
            return n
        for i in range(2, n):
            if nums[i] != nums[j-2]:
                nums[j] = nums[i]
                j += 1
        return j
