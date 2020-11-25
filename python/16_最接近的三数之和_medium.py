class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums_asc = sorted(nums)
        ans = float("+inf")
        N = len(nums_asc)
        for a in range(0, N-2):
            if a>0 and nums_asc[a]==nums_asc[a-1]:
                continue
            b, c = a+1, N-1
            while(b<c):
                sum3 = nums_asc[a]+nums_asc[b]+nums_asc[c]
                gap = abs(sum3 - target)
                if gap < abs(ans-target):
                    ans = sum3
                if sum3 == target:
                    return sum3
                elif sum3 > target:
                    while b<c and nums_asc[c]==nums_asc[c-1]:
                        c-=1
                    c-=1
                else:
                    while b<c and nums_asc[b]==nums_asc[b+1]:
                        b+=1
                    b+=1
        return ans