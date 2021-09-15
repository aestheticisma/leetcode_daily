class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return 0
        elif n == 2:
            return 0 if nums[0] > nums[1] else 1
        else: 
            left, i, right, j = 0, 1, n-1, n-2
            data = set()
            while i < n:
                while i<n and nums[i] > nums[left]:
                    left += 1
                    i += 1
                left += 1
                i += 1
                data.add(left-1)
            while j > -1:
                while j > -1 and nums[j] > nums[right]:
                    j -= 1
                    right -= 1
                j -= 1
                right -= 1
                if right+1 in data:
                    return right+1