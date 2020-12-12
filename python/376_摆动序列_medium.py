class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        if len(nums)<2:
            return len(nums)
        up, down = 1, 1
        for index in range(1, len(nums)):
            if nums[index]<nums[index-1]:
                down = max(down, up+1)
            elif nums[index]>nums[index-1]:
                up = max(up, down+1)
        return max(up, down)