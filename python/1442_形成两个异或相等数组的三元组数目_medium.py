class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        ans, n, s = 0, len(arr), [0]
        for i in range(n):
            s.append(s[-1] ^ arr[i])
        cnt, total = Counter(), Counter()
        for k in range(n):
            if s[k+1] in cnt:
                ans += cnt[s[k+1]] * k - total[s[k+1]]
            cnt[s[k]] += 1
            total[s[k]] += k
        return ans