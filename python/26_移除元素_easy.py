class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        n, index = len(nums), 0
        if not n:
            return 0
        for i in range(n):
            if nums[i] != val:
                nums[index] = nums[i]
                index += 1
        return index