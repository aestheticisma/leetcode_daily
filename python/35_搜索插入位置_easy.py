# 按部就班
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if not nums:
            return 0;
        for i in range(len(nums)):
            if nums[i]==target:
                return i
        index = 0
        while index<len(nums) and nums[index]<target:
            index += 1
        return index

# 二分法:
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        N = len(nums)
        low, high = 0, N-1
        while low<=high:
            mid = (low+high)>>1
            if target==nums[mid]:
                return mid
            elif target<nums[mid]:
                high = mid - 1
            else:
                low = mid + 1
        return low