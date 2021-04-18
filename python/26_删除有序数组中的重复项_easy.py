class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n, j = len(nums), 1
        if n <= 1:
            return n
        for i in range(1, n):
            if nums[i] != nums[j-1]:
                nums[j] = nums[i]
                j += 1
        return j