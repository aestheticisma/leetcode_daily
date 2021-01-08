class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        def reverse(start, end):
            while start < end:
                nums[start], nums[end] = nums[end], nums[start]
                start += 1
                end -= 1
        N = len(nums)
        k %= N
        reverse(0, N-1)
        reverse(0, k-1)
        reverse(k, N-1)