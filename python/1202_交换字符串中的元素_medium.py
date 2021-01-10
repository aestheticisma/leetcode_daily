class Solution:
    def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:
        p = {i:i for i in range(len(s))}
        def find_union(x):
            if x!=p[x]:
                p[x] = find_union(p[x])
            return p[x]
        for i, j in pairs:
            p[find_union(j)] = find_union(i)
        print(p)
        d = collections.defaultdict(list)
        for i, j in enumerate(map(find_union, p)):
            d[j].append(i)
        ans = list(s)
        for q in d.values():
            t = sorted(ans[i] for i in q)
            for i, j in zip(sorted(q), t):
                ans[i] = j
        return ''.join(ans)