class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        rows, columns = len(heights), len(heights[0])
        q = [(0, 0, 0)]
        seen = set()
        dist = [0] + [float('inf')] * (rows*columns-1)
        directions = [(-1, 0), (0, -1), (1, 0), (0, 1)]
        while q:
            d, x, y = heapq.heappop(q)
            idx = x*columns+y
            if idx in seen:
                continue
            if x == rows-1 and y == columns-1:
                break
            seen.add(idx)
            for dx, dy in directions:
                nx, ny = x+dx, y+dy
                if 0<=nx<rows and 0<=ny<columns and max(d, abs(heights[nx][ny]-heights[x][y]))<=dist[nx*columns+ny]:
                    dist[nx*columns+ny] = max(d, abs(heights[nx][ny]-heights[x][y]))
                    heapq.heappush(q, (dist[nx*columns+ny], nx, ny))
        return dist[-1]