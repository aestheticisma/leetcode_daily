class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        cnt = collections.Counter(nums)
        ent = collections.Counter()
        for e in nums:
            if not cnt[e]:
                continue
            elif ent[e-1]:
                cnt[e], ent[e-1], ent[e] = cnt[e]-1, ent[e-1]-1, ent[e]+1
            elif cnt[e+1] and cnt[e+2]:
                cnt[e], cnt[e+1], cnt[e+2] = cnt[e]-1, cnt[e+1]-1, cnt[e+2]-1
                ent[e+2] += 1
            else: return False
        return True