class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        ans = []
        nums.sort()
        for mask in range(0, 1<<n):
            t = []
            flag = 1
            for i in range(n):
                if mask & (1<<i):
                    if i>0 and (mask>>(i-1) & 1)==0 and nums[i] == nums[i-1]:
                        flag = 0
                        break
                    t.append(nums[i])
            if flag:
                ans.append(t)
        return ans