class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        go = [[float('inf')] * n for _ in range(n)]
        for x, y, time in times:
            go[x-1][y-1] = time
        dist = [float('inf')] * n
        dist[k-1] = 0
        used = [False] * n
        for i in range(n):
            x = -1
            for y, u in enumerate(used):
                if not u and (x == -1 or dist[y] < dist[x]):
                    x = y
            used[x] = True
            for y, time in enumerate(go[x]):
                dist[y] = min(dist[y], dist[x] + time)
        ans = max(dist)
        return ans if ans < float('inf') else -1