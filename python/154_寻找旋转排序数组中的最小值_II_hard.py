class Solution:
    def findMin(self, nums: List[int]) -> int:
        n = len(nums)
        l, r = 0, n-1
        while l<r:
            mid = (l+r) // 2
            if nums[l] == nums[mid] and nums[mid] == nums[r]:
                l += 1
                r -= 1
                continue
            if nums[l] <= nums[mid]:
                if nums[mid] <= nums[r]:
                    return nums[l]
                else:
                    l = mid + 1
            else:
                r = mid
        return nums[l]