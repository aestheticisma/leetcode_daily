class Solution:
    def minChanges(self, nums: List[int], k: int) -> int:
        MAXX = 1<<10
        n = len(nums)
        f = [float("inf")] * MAXX
        f[0] = 0
        
        for i in range(k):
            size = 0
            cnt = Counter()
            for j in range(i, n, k):
                cnt[nums[j]] += 1
                size += 1
            minT2 = min(f)
            g = [minT2] * MAXX
            for x in range(MAXX):
                for key, value in cnt.items():
                    g[x] = min(g[x], f[x ^ key] - value)
            f = [v + size for v in g]
        return f[0]