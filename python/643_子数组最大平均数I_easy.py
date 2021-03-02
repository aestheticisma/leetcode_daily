class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        tmp = sum(nums[:k])
        res = tmp
        for i in range(k, len(nums)):
            tmp = tmp + nums[i] - nums[i-k]
            res = max(res, tmp)
        return res/k