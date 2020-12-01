class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def binarysearch(lower):
            left, right, ans = 0, len(nums)-1, len(nums)
            while(left<=right):
                mid = (left+right)//2
                if nums[mid]>target or (lower and nums[mid]>=target):
                    right -= 1
                    ans = mid
                else:
                    left += 1
            return ans
        if len(nums)<1: return [-1, -1]
        if nums[0]>target: return [-1, -1]
        leftPos = binarysearch(True)
        rightPos = binarysearch(False)-1
        if(leftPos<=rightPos and rightPos<=len(nums) and nums[leftPos]==target and nums[rightPos]==target):
            return [leftPos, rightPos]
        else:
            return [-1, -1]