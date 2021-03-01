class NumArray:

    def __init__(self, nums: List[int]):
        self.mm = [0]
        for num in nums:
            self.mm.append(num+self.mm[-1])

    def sumRange(self, i: int, j: int) -> int:
        return self.mm[j+1] - self.mm[i]
        



# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)