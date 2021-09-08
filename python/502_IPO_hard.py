class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        n, cur = len(profits), 0
        pq = []
        data = [(capital[i], profits[i]) for i in range(n)]
        data.sort(key = lambda x : x[0])
        for i in range(k):
            while cur < n and data[cur][0] <= w:
                heappush(pq, -data[cur][1])
                cur += 1
            if pq:
                w -= heappop(pq)
            else:
                break
        return w