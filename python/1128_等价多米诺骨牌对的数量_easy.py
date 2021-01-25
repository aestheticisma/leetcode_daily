class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        nums = [0]*100
        res = 0
        for (x, y) in dominoes:
            num = (10*x+y if x<=y else 10*y+x)
            res += nums[num]
            nums[num] += 1
        return res