class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ret, f = [-1]*n, []
        for i in range(2*n-1):
            while f and nums[f[-1]] < nums[i%n]:
                ret[f[-1]] = nums[i%n]
                f.pop()
            f.append(i%n)
        return ret