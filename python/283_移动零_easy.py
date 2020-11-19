class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        N = len(nums)
        left, right = 0, 0
        while(right<N):
            if nums[right]:
                temp = nums[left]
                nums[left]=nums[right]
                nums[right]=temp
                left += 1
            right += 1

class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        N = len(nums)
        index = 0
        for i in range(N):
            if nums[i]:
                nums[index] = nums[i]
                index += 1
        for i in range(index, N):
            nums[i] = 0