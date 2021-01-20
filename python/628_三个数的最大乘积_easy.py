class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        min1, min2 = [float('inf')]*2
        max1, max2, max3 = [float('-inf')]*3
        for num in nums:
            min1, min2, _ = sorted([min1, min2, num])
            _, max3, max2, max1 = sorted([max1, max2, max3, num])
        return max(min1*min2*max1, max3*max2*max1)