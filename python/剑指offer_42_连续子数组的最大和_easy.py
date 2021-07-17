class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans, pre = float('-inf'), 0
        for num in nums:
            pre = max(pre + num, num)
            ans = max(ans, pre)
        return ans